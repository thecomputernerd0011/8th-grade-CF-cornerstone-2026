#pragma once
#include "renderer.hpp"

// This code is going to be the hardest part, John.

enum formatType{
    NOTFORMAT,
    TITLE,
    BODY,
    OPTION
};

struct formattedSection{
    formatType dataType;
    std::string formatText;
    std::string mainText;
};

menu* StringIDtoMenuPtr(const char* ID); // This can and will create new menu objects to make sure an ID actually goes somewhere

menuOption* interpretOption(formattedSection readInfo);

void parseSection(formattedSection section);

void parseFile(std::string path);

