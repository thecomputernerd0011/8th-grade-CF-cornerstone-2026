#include "parser.hpp"
#include "renderer.hpp"
#include <cstdio>
#include <cstring>
#include <fstream>

std::vector<menu*> Scene;

menu* StringIDtoMenuPtr(const char* ID){
    for(menu* suspect : Scene){
        if(strcmp(suspect->ID.c_str(), ID) == 0)
            return suspect;
    }
    menu* newMenu = new menu{ID, "---ERROR!---\n", ""};
    Scene.push_back(newMenu);
    return newMenu;
}

void parseSection(formattedSection Section){
    char ownerID[64];
    char destID[64];
    switch(Section.dataType){
        case TITLE:
            sscanf(Section.formatText.c_str(), "[t@%[^]]]", ownerID);
            StringIDtoMenuPtr(ownerID)->Title = Section.mainText;
            break;
        case BODY:
            sscanf(Section.formatText.c_str(), "[b@%[^]]]", ownerID);
            StringIDtoMenuPtr(ownerID)->Body = Section.mainText;
            break;
        case OPTION:{
            sscanf(Section.formatText.c_str(), "[q@%[^>]>%[^]]]", ownerID, destID);
            menu* parent = StringIDtoMenuPtr(ownerID);
            menuOption* newOption = new menuOption{
                parent,
                Section.mainText,
                StringIDtoMenuPtr(destID)
            };
            parent->Children.push_back(newOption);
            break;
        }
        default:
            printf("Failed to parse:\n%s%s", Section.formatText.c_str(), Section.mainText.c_str());
            return;
    }
}

void parseFile(std::string path){
    std::ifstream File(path);
    if(!File.is_open()){
        printf("Failed to open %s\n", path.c_str());
        return;
    }
    std::string currentLine;
    formattedSection currentSection;
    std::vector<formattedSection> undercookedData;

    while(getline(File, currentLine)){
        currentLine.append("\n");
        if(currentLine.c_str()[0] == '['){
            // Is formatting data
            // First, put away previous info
            if(!currentSection.formatText.empty())
                undercookedData.push_back(currentSection);
            // Now fill out the struct
            currentSection.formatText = currentLine;
            currentSection.mainText = "";
            switch (currentLine.c_str()[1]) {
                case 't':
                    currentSection.dataType = TITLE;
                    break;
                case 'b':
                    currentSection.dataType = BODY;
                    break;
                case 'q':
                    currentSection.dataType = OPTION;
                    break;
                default:
                    printf("failed to parse a format\n");
                    currentSection.dataType = NOTFORMAT;
            }
        } else {
            // Is not formatting data
            currentSection.mainText.append(currentLine);
        }
    }
    undercookedData.push_back(currentSection); // Add in that last bit of data

    for(formattedSection data : undercookedData)
        parseSection(data);
}

int main(){
    parseFile("./text/Mainmenu.txt");
    parseFile("./text/1sthabit.txt");
    parseFile("./text/2ndhabit.txt");
    StringIDtoMenuPtr("0")->open();
}
