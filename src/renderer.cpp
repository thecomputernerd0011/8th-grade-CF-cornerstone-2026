#include "renderer.hpp"
#include <cstdio>

void Menu::promptUser(){
    int childID = 1;
    for(MenuOption* child : Children){
        printf("\n\t%i. %s\n", childID, child->text.c_str());
        childID++;
    }
}

void Menu::open(){
    printf("%s\n%s", Title.c_str(), Body.c_str());
    promptUser();
}

void startRenderer(Menu* mainMenu){
    mainMenu->open();
}
