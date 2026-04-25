#include "renderer.hpp"

void Menu::open(){
    printf("%s\n%s", Title.c_str(), Body.c_str());
}

void startRenderer(Menu* mainMenu){
    mainMenu->open();
}
