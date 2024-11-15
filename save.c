#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_score(char name[20], int health, int fear, char* status, int golds, int body, int visit1x1, int visit1x2, int visit1x3, int visit2x1, int visit2x2, int visit2x3) {
    FILE *fptr = fopen("save.txt", "w");
    if (fptr == NULL) {
        printf("Error opening save\n");
        return;
    }
    fprintf(fptr, "name : %s\n", name);
    fprintf(fptr, "health : %d\n", health);
    fprintf(fptr, "fear : %d\n", fear);
    fprintf(fptr, "status : %s\n", status);
    fprintf(fptr, "golds : %d\n", golds);
    fprintf(fptr, "body : %d\n", body);
    fprintf(fptr, "visit1x0 : %d\n", visit1x1);
    fprintf(fptr, "visit1x2 : %d\n", visit1x2);
    fprintf(fptr, "visit1x3 : %d\n", visit1x3);
    fprintf(fptr, "visit2x1 : %d\n", visit2x1);
    fprintf(fptr, "visit2x2 : %d\n", visit2x2);
    fprintf(fptr, "visit2x3 : %d\n", visit2x3);
    fclose(fptr);
}

void load_score(char name[20], int *health, int *fear, char* status, int *golds, int *body, int *visit1x1, int *visit1x2, int *visit1x3, int *visit2x1, int *visit2x2, int *visit2x3) {
    FILE *fptr = fopen("save.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fptr, "name : %s\n", name);
    fscanf(fptr, "health : %d\n", health);
    fscanf(fptr, "fear : %d\n", fear);
    fscanf(fptr, "status : %s\n", status);
    fscanf(fptr, "golds : %d\n", golds);
    fscanf(fptr, "body : %d\n", body);
    fscanf(fptr, "visit1x0 : %d\n", visit1x1);
    fscanf(fptr, "visit1x2 : %d\n", visit1x2);
    fscanf(fptr, "visit1x3 : %d\n", visit1x3);
    fscanf(fptr, "visit2x1 : %d\n", visit2x1);
    fscanf(fptr, "visit2x2 : %d\n", visit2x2);
    fscanf(fptr, "visit2x3 : %d\n", visit2x3);
    fclose(fptr);
}

