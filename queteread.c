#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_quete() {
  
    FILE *file_ptr;
    char ch;
    file_ptr = fopen("quete.txt", "r");
    if (NULL == file_ptr) {
        printf("Error opening file\n");
          exit(0);
    }
    while ((ch = fgetc(file_ptr)) != EOF) {
        printf("%c", ch);
        sleep_ms(20);
        fflush(stdout);
    }

    // Closing the file
    fclose(file_ptr);
}