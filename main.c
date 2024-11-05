#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "save.c"
#include "fastsleep.c"
#include "anim.c"
#include "queteread.c"
#include "menu.c"

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"


int main(){
    struct player
    {
        char* name;
        int health;
        int fear;
        int body;
        int golds;
    };
    char choice[2];
    system("clear");
    printf(CYN);
    load_quete();
    printf(WHT);
    printf("> Appuyez Sur Entrée pour continuer...");
    getchar();
    fflush(stdout);
    system("clear");
    printf("Vous choisissez un surnom pour ce périple\n");
    printf("> Votre Choix: ");
    struct player player1;
    fgets(player1.name, 20, stdin);
    player1.name[strcspn(player1.name, "\n")] = 0;
    system("clear");
    printf("Trois lieux doivent être visité…\n");
    printf("[%s>%s] 1 Les Profondeurs de la Forêt\n", RED, WHT);
    printf("[%s>%s] 2 L'Asile\n", RED, WHT);
    printf("[%s>%s] 3 Les Catacombes\n", RED, WHT);
    printf("> Votre Choix :");
    fgets(choice, 2, stdin);
    choice[strcspn(choice, "\n")] = 0;
    int input = atoi(choice);
    
    if(input == 1) {
        player1.fear = 20;
        player1.health = 100;
        player1.body = 0;
        player1.golds = 0;
        save_score(player1.name, player1.health, player1.fear, player1.body, player1.golds);
        menu(player1.health, player1.golds, player1.name, player1.body, player1.fear);

    }
    else if(input == 2) {
        printf("2");
    }
    else if(input == 3) {
        printf("3");
    }
    else{
        printf("Mauvais Choix");
    }
  

    return 0;
}