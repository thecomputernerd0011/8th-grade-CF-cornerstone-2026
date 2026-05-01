#include "renderer.hpp"
#include <cstdio>
#include <windows.h>

bool goBack = false;
void menu::promptUser(){
    size_t childID = 1;
    for(menuOption* child : Children){
        printf("\n\t%zu. %s\n", childID, child->text.c_str());
        childID++;
    }
    printf("\n\t0. Go back\n\nEnter a number (0-%zu): ", Children.size());
    size_t choice;
    scanf("%zu", &choice);

    if (choice == 0){
        goBack = true;
        return;
    }

    Children[choice - 1]->Destination->open();
}

void printCentered(const std::string& text){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int padding = (width - (int)text.size()) / 2;
    printf("%*s%s\n", padding, "", text.c_str());
}

void pagedPrint(const std::string& text){
    int lineCount = 0;
    int start = 0;
    for(size_t i = 0; i <= text.size(); i++){
        if(text[i] == '\n' || text[i] == '\0'){
            printf("%.*s\n", (int)(i - start), text.c_str() + start);
            start = i + 1;
            lineCount++;
            if(lineCount % 20 == 0){
                printf("-- press enter for more --");
                getchar();
            }
        }
    }
}

void menu::open(){
    while (!goBack){
        system("cls");
        printf("\n");
        printCentered(Title); // "centered text"

#ifdef __unix__
        FILE* pager = popen("less -F -X", "w");
        fprintf(pager, "%s", Body.c_str());
        pclose(pager);
#else
        pagedPrint(Body);
#endif

        promptUser();
    }
    goBack = false;
}

void startRenderer(menu* mainMenu){
    mainMenu->open();
}
