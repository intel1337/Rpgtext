#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "save.c"
#include "fastsleep.c"
#include "anim.c"
#include "queteread.c"
#include "menu.c"



void addquest(const char *file, int *visit, const char *filewin, const char *filelose, const char *choices){
    if (*visit == 0) {
        *visit = 1;
        load_quete(file);
        load_quete(choices);
        printf("> Votre Choix : ");
        char choice[10];
        fgets(choice, 10, stdin);
        choice[strcspn(choice, "\n")] = 0;
        int input = atoi(choice);
        if(input == 1){
            load_quete(filewin);
            getchar();
            fflush(stdout);
            system("clear");
        }
        else{
            load_quete(filelose);
            getchar();
            fflush(stdout);
            system("clear");
        }
    }
}

int main()
{

    int visit = 0;
    char file[50];
    char filewin[50];
    char filelose[50];
    char choices[50];

    printf("Quel est le nom du fichier de quete ? ");
    fgets(file, 50, stdin);
    file[strcspn(file, "\n")] = 0;

    printf("Quel est le nom du fichier de reussite ? ");
    fgets(filewin, 50, stdin);
    filewin[strcspn(filewin, "\n")] = 0;

    printf("Quel est le nom du fichier d'echec ? ");
    fgets(filelose, 50, stdin);
    filelose[strcspn(filelose, "\n")] = 0;

    printf("Quel sont les choix possible ? ");
    fgets(choices, 50, stdin);
    choices[strcspn(choices, "\n")] = 0;

    addquest(file, &visit, filewin, filelose, choices);

    return 0;
}


