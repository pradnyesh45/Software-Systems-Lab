#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char str[100];
    fp = fopen("2018BCS034_1.1.txt", "r");
    if (fp == NULL)
    {
        printf("\nerror: Cannot open file");
        exit(1);
    }
    char str1;
    str1 = fgetc(fp);
    int i = 1;
    printf("%d ", i);
    while (str1 != EOF)
    {
        printf("%c", str1);
        if (str1 == '\n')
        {
            printf("%d ", ++i);
        }
        str1 = fgetc(fp);
    }
    printf("\n");
    fclose(fp);
    return 0;
}