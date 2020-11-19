#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //One for text mode, and one for binary mode.
    FILE *f;
    FILE *fb;

    char fileName[100];
    printf("Enter file name : ");
    scanf("%s", fileName);
    char tempFileName[100];
    strcpy(tempFileName, fileName);

    f = fopen(strcat(fileName, ".txt"), "w");
    fb = fopen(strcat(tempFileName, ".bin"), "wb");

    for (int i = 0; i < 3; ++i)
    {
        char name[20];
        int roll;

        //Read name and roll
        printf("Enter name : ");
        scanf("%s", name);
        printf("Enter roll : ");
        scanf("%d", &roll);

        char outputString[100];
        strcpy(outputString, "");
        char rollInString[100];
        snprintf(rollInString, 10, "%d", roll);

        strcat(outputString, "Name : ");
        strcat(outputString, name);
        strcat(outputString, "; Roll : ");
        strcat(outputString, rollInString);
        strcat(outputString, "\n");

        fprintf(f, outputString);
        fwrite(outputString, sizeof(outputString), 1, fb);
    }
}