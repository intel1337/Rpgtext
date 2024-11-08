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

void enterToContinue(){
    printf(COLOR_RESET);
    printf("> Appuyez Sur Entrée pour continuer...");
    getchar();
    fflush(stdout);
    system("clear");
}

void introduction(){
    system("clear");
    printf(MAG);
    load_quete("intro.txt");
    printf(WHT);
    printf("> Appuyez Sur Entrée pour continuer...");
    getchar();
    fflush(stdout);
    system("clear");
    printf(MAG);
    load_quete("intro2.txt");
    printf("\n");
    printf(WHT);
    printf("> Appuyez Sur Entrée pour continuer...");
    getchar();
    fflush(stdout);
    system("clear");
}


int main(){
    while(1){
        struct player
        {
            char* name;
            int health;
            int fear;
            int body;
            int golds;
            char* status;
        };
        struct player player1;
        char choice[2];
        int visit1 = 0;
        int visit2 = 0;
        int visit3 = 0;
        int visit1x1 = 0;
        int visit1x2 = 0;
        int visit1x3 = 0;
        int visit2x1 = 0;
        int visit2x2 = 0;
        int visit2x3 = 0;


        srand(time(NULL));
        system("clear");
        if(player1.body > 0){
        
        introduction();

        printf("Vous choisissez un surnom pour ce périple\n");
        printf("> Votre Choix: ");

        fgets(player1.name, 20, stdin);
        player1.name[strcspn(player1.name, "\n")] = 0;
        system("clear");
        }

        printf("Trois lieux doivent être visité…\n");
        printf("[%s>%s] 1 Les Profondeurs de la Forêt\n", RED, WHT);
        printf("[%s>%s] 2 L'Asile\n", RED, WHT);
        printf("[%s>%s] 3 Les Catacombes\n", RED, WHT);
        printf("> Votre Choix :");

        fgets(choice, 10, stdin);
        choice[strcspn(choice, "\n")] = 0;
        int input = atoi(choice);
        
        if(input == 1) {

            player1.fear = 10;
            player1.health = 100;
            player1.body = 0;
            player1.golds = 0;

            system("clear");
            fflush(stdout);

            int counter = 0;
            while(counter != 5){
                counter++;
                printf(WHT);

                printf("[%s>%s] %s1 Les Profondeurs de la Forêt\n",CYN, WHT, GRN);
                sleep_ms(200);
                system("clear");
                fflush(stdout);

                printf("[%s>%s] %s1 Les Profondeurs de la Forêt\n", GRN, WHT, WHT);
                sleep_ms(200);
                system("clear");
                fflush(stdout);

                printf("[%s>%s] %s1 Les Profondeurs de la Forêt\n",CYN, WHT, GRN);
                system("clear");
                fflush(stdout);
            }

            enterToContinue();
            fflush(stdout);

            player1.fear = 20;
            player1.status = "1.0";

            save_score(player1.name, player1.health, player1.fear, player1.status, player1.golds, player1.body);
            menu(player1.health, player1.golds, player1.name, player1.body, player1.fear);

            enterToContinue();
            system("clear");
            fflush(stdout);

            load_quete("1.0.txt");
            printf("\n");
            menu(player1.health, player1.golds, player1.name, player1.body, player1.fear);

            printf("> Votre Choix : ");
            fgets(choice, 10, stdin);

            choice[strcspn(choice, "\n")] = 0;
            int input = atoi(choice);

            if(input == 1 && visit1x1 == 0){
                enterToContinue();
                load_quete("1.1.txt");
                player1.status = "1.1";
                player1.fear = 40;
                printf("Lancez la pièce, 1 : Pile, 2 : Face\n");
                menu(player1.health, player1.golds, player1.name, player1.body, player1.fear);
                printf("> Votre Choix : ");
                fgets(choice, 10, stdin);
                choice[strcspn(choice, "\n")] = 0;
                int input = atoi(choice);
                
                int random_number = rand() % 2 + 1;
                
                if(input == random_number){
                    load_quete("1.1w.txt");
                    player1.fear = 50;
                    player1.body = 1;
                    menu(player1.health, player1.golds, player1.name, player1.body, player1.fear);
                    enterToContinue();
                    fflush(stdout);
                    visit1x1 = 1;
                }
                else{
                    load_quete("1.1l.txt");
                    player1.fear = 60;
                    player1.health - 20;
                    menu(player1.health, player1.golds, player1.name, player1.body, player1.fear);
                    player1.body = 1;
                    enterToContinue();
                    fflush(stdout);
                    visit1x1 = 1;
                }
            }
            else{
                printf("Tu as déja exploré ce chemin");
                enterToContinue();
                fflush(stdout);
            }
        }
        else if(input == 2) {
            printf("2");
        }
        else if(input == 3) {
            printf("3");
        }
        else if(input == 1337){
            system("cowsay Massi utilise ChatGPT");
            enterToContinue();
            system("shutdown -h now");
        }
        else{
            printf("Mauvais Choix");
        }
        system("clear");
        fflush(stdout);
    }

    
  

    return 0;
}
