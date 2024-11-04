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

int main(){
    struct player
    {
        char* name;
        int health;
        int fear;
        int body;
        int golds;
    };
    load_quete();

    return 0;
}