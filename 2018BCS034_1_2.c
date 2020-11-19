#include <stdio.h>

int main()
{
    FILE *fp;
    char c;
    int n = 1;

    char nameOfFile[100];
    int number;
    printf("Enter the name of file: ");
    scanf("%s", nameOfFile);

    printf("Enter the field number : ");
    scanf("%d", &number);

    fp = fopen("2018BCS034_1_2.txt", "r");

    if (fp == NULL)
    {
        perror("File could not be opened");
        return (-1);
    }

    int curWord = 1;
    while (1)
    {
        c = fgetc(fp);
        if (feof(fp))
            break;

        if (curWord == number)
            printf("%c", c);
        if (c == '\n')
        {
            curWord = 1;
            printf("\n");
        }
        if (c == ' ')
            curWord++;
    }

    printf("\n");
    fclose(fp);
    return (0);
}