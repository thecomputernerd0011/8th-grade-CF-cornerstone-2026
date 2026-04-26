#include "renderer.hpp"
#include <cstdio>

void Menu::promptUser(){
    unsigned long childID = 1;
    for(MenuOption* child : Children){
        printf("\n\t%zu. %s\n", childID, child->text.c_str());
        childID++;
    }
    printf("Enter a number (1-%zu): ", Children.capacity());
    unsigned long choice;
    scanf("%zu", &choice);

    Children[choice - 1]->Destination->open();
}

void Menu::open(){
    printf("%s\n%s", Title.c_str(), Body.c_str());
    promptUser();
}

void startRenderer(Menu* mainMenu){
    mainMenu->open();
}
