#include "renderer.hpp"
#include <cstdio>

void menu::promptUser(){
    unsigned long childID = 1;
    for(menuOption* child : Children){
        printf("\n\t%zu. %s\n", childID, child->text.c_str());
        childID++;
    }
    printf("Enter a number (1-%zu): ", Children.capacity());
    unsigned long choice;
    scanf("%zu", &choice);

    Children[choice - 1]->Destination->open();
}

void menu::open(){
    printf("%s\n%s", Title.c_str(), Body.c_str());
    promptUser();
}

void startRenderer(menu* mainMenu){
    mainMenu->open();
}
