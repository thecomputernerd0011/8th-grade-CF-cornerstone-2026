#include "renderer.hpp"
#include <cstdio>

void menu::promptUser(){
    unsigned long childID = 1;
    for(menuOption* child : Children){
        printf("\n\t%zu. %s\n", childID, child->text.c_str());
        childID++;
    }
    printf("Enter a number (1-%zu): ", Children.size());
    unsigned long choice;
    scanf("%zu", &choice);

    Children[choice - 1]->Destination->open();
}

void pagedPrint(const std::string& text){
    int lineCount = 0;
    int start = 0;
    for(size_t i = 0; i <= text.size(); i++){
        if(text[i] == '\n' || text[i] == '\0'){
            printf("%.*s\n", i - start, text.c_str() + start);
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
    printf("%s\n", Title.c_str());

#ifdef __unix__
    FILE* pager = popen("less", "w");
    fprintf(pager, "%s", Body.c_str());
    pclose(pager);
#else
    pagedPrint(Body);
#endif

    promptUser();
}

void startRenderer(menu* mainMenu){
    mainMenu->open();
}
