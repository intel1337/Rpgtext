#include <stdio.h>
void save_score(char *name,  int health, int fear, int body, int golds) {
    FILE *fptr = fopen("save.txt", "w");
    if(fptr == NULL) {
        printf("Error opening save\n");
        return;
    }
    fprintf(fptr, "name : %s\n", name);
    fprintf(fptr, "health :%d\n", health);
    fprintf(fptr, "fear :%d\n", fear);
    fprintf(fptr, "body :%d\n", body);
    fprintf(fptr, "golds : %d\n", golds);
    fclose(fptr);
}
void load_score(char *name,  int health, int fear, int body, int golds) {
    FILE *fptr = fopen("save.txt", "r+");
    if(fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fptr, "name : %s\n", name);
    fscanf(fptr, "health :%d\n", health);
    fscanf(fptr, "fear :%d\n", fear);
    fscanf(fptr, "body :%d\n", body);
    fscanf(fptr, "golds : %d\n", golds);
    fclose(fptr);
}