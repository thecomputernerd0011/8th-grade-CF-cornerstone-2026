#pragma once
#include <vector>
#include <string>

struct menuOption;
struct menu{
    std::string ID;
    std::string Title;
    std::string Body;
    std::vector<menuOption*> Children;

    void open();
    void promptUser(); //
};
struct menuOption{
    menu* Start;
    std::string text;
    menu* Destination;
};

void startRenderer(menu* mainMenu);
