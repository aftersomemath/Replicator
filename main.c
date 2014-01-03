#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <string.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    if(fopen("STOP.txt", "r")){
        printf("I will stop");
        getch();
        return 0;
    }


    FILE *fp;
    FILE *thecopy;

    int old_number = atoi(argv[0]);

    fp = fopen(argv[0], "rb");
    if(fp == NULL)
    {
        printf("failed to open myself");
        getch();
        return 1;
    }

    char new_number[15];
    sprintf(new_number, "%d", old_number + 1);
    thecopy = fopen(strcat(new_number, ".exe"), "w+b");

    while(!feof(fp))
    {
        char ch = getc(fp);

            putc(ch, thecopy);
    }


    fclose(thecopy);
    spawnl(P_NOWAIT, new_number, new_number, NULL);
    fclose(fp);
    return 0;
}
