#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



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

void menu(int health, int golds, char name[20], int body, int fear){
    int i;
    printf("[-%s-]\n", name);
    printf("|----------------------------------|\n");
    printf("Health : [");
    if(health<35){
        printf(RED);
    }
    else{
        printf(GRN);
    }
    while(i != health/10){
        printf("██");
        i++;
    }
    if(health/10 != 10){
        while(i != 10){
            printf(WHT);
            printf("██");
            sleep_ms(100);
            fflush(stdout);
            i++;
        }

    }
    printf(COLOR_RESET);
    printf("]\n");
    i = 0;
    printf("Fear   : [");
    printf(MAG);
    while(i != fear/10){
        printf("██");
        i++;
    }
    if(fear/10 != 10){
        while(i != 10){
            printf(WHT);
            printf("██");
            sleep_ms(100);
            fflush(stdout);
            i++;
        }

    }
    printf(COLOR_RESET);
    printf("]\n");
    i = 0;
    printf("Bodies found : %d / 5\n", body);
    printf("Money Withdrawn : %d\n", golds);
    printf("|----------------------------------|\n");




}
