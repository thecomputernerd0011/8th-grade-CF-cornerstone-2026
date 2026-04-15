#pragma once
#include <vector>
#include <string>

struct MenuOption;
struct Menu{
    std::string ID; // Full ID. I'm having issues making this so were are going have to do this the C way
    std::string Title;
    // We store image as a GLuint, but I have not started development on the renderer yet.
    std::string Body;
    std::vector<MenuOption*> Children;
};
struct MenuOption{
    Menu* Start;
    std::string text;
    Menu* Destination;
};
