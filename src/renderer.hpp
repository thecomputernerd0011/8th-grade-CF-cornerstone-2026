#pragma once
#include <vector>
#include <string>

struct MenuOption;
struct Menu{
    std::string ID; // Full ID. I'm having issues making this so were are going have to do this the C way
    std::string Title;
    std::string Body;
    std::vector<MenuOption*> Children;

    void open();
    void promptUser(); //
};
struct MenuOption{
    Menu* Start;
    std::string text;
    Menu* Destination;
};

void startRenderer(Menu* mainMenu);
