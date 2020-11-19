#include <stdio.h>

int main()
{
    FILE *fp;
    char str[100];

    fp = fopen("2018BCS034_1.1.txt", "r");
    if (fp == NULL)
    {
        perror("Error in opening the file");
        return -1;
    }
    int i = 1;
    while (i < 100)
    {

        if (fgets(str, 60, fp) != NULL)
        {
            printf("%d ", i);
            puts(str);
        }
        i++;
    }
    fclose(fp);
    return 0;
}