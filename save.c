#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_score(char name[20],  int health, int fear, char* status, int golds, int body) {
    FILE *fptr = fopen("save.txt", "w");
    if(fptr == NULL) {
        printf("Error opening save\n");
        return;
    }
    fprintf(fptr, "name : %s\n", name);
    fprintf(fptr, "health :%d\n", health);
    fprintf(fptr, "fear :%d\n", fear);
    fprintf(fptr, "status :%s\n", status);
    fprintf(fptr, "golds : %d\n", golds);
    fprintf(fptr, "body :%d\n", body);
    fclose(fptr);
}

void load_score(char* name[20],  int *health, int *fear, char* status, int *golds, int*body) {
    FILE *fptr = fopen("save.txt", "r+");
    if(fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fptr, "name : %s\n", &name);
    fscanf(fptr, "health :%d\n", health);
    fscanf(fptr, "fear :%d\n", fear);
    fscanf(fptr, "body :%d\n", body);
    fscanf(fptr, "status : %s\n", status);
    fscanf(fptr, "golds : %d\n", golds);
    fscanf(fptr, "body : %d\n", body);
    fclose(fptr);
}
