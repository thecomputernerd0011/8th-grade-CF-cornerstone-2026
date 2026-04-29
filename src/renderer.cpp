#include "renderer.hpp"
#include <cstdio>

bool goingBack = false;

void menu::promptUser(){
    unsigned long childID = 1;
    for(menuOption* child : Children){
        printf("\n\t%zu. %s\n", childID, child->text.c_str());
        childID++;
    }
    printf("Enter a number (0 to go back)(0-%zu): ", Children.capacity());
    unsigned long choice;
    scanf("%zu", &choice);
    if(choice == 0){
        goingBack = true;
        return;
    }
    Children[choice - 1]->Destination->open();
}

void menu::open(){
    while (!goingBack){
        printf("%s\n%s", Title.c_str(), Body.c_str());
        promptUser();
    }
    goingBack = false;
}

void startRenderer(menu* mainMenu){
    mainMenu->open();
}
