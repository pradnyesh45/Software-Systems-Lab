#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
char l[10];
struct symb
{
    int add;
    char label[10];
} sy[11];
void search();
void main()
{
    int a[MAX], num, key, i, ch;
    char ans;
    int create(int);
    void lprob(int[], int, int);
    void display(int[]);
    for (i = 0; i < MAX; i++)
        sy[i].add = -1;
    do
    {
        printf("\nEnter your choice:\n1.create a symbol table\n2.exit\n::::");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            do
            {
                printf("\nEnter the address :");
                scanf("%d", &num);
                key = create(num);
                printf("Enter the label:");
                scanf("%s", l);
                lprob(a, key, num);
                printf("\ncontinue(y/n)?");
                ans = getche();
            } while (ans == 'y');
            display(a);
            break;
        case 2:
            exit(0);
        }
    } while (ch <= 2);
    getch();
}
int create(int num)
{
    int key;
    key = num % 10;
    return key;
}
void lprob(int a[MAX], int key, int num)
{
    int flag, i, count = 0;
    void display(int a[]);
    flag = 0;
    if (sy[key].add == -1)
    {
        a[key] = num;
        sy[key].add = num;
        strcpy(sy[key].label, l);
    }
    else
    {
        i = 0;
        while (i < MAX)
        {
            if (sy[i].add != -1)
                count++;
            i++;
        }
        if (count == MAX)
        {
            printf("\nHash table is full");
            display(a);
            getch();
            exit(1);
        }
        for (i = key + 1; i < MAX; i++)
            if (sy[i].add == -1)
            {
                a[i] = num;
                flag = 1;
                sy[i].add = num;
                strcpy(sy[i].label, l);
                break;
            }
        for (i = 0; i < key && flag == 0; i++)
            if (sy[i].add == 0)
            {
                a[i] = num;
                flag = 1;
                sy[key].add = num;
                strcpy(sy[key].label, l);
                break;
            }
    }
}
void display(int a[MAX])
{
    FILE *fp;
    int i;
    fp = fopen("symbol.txt", "w");
    printf("\nThe symbol Table is");
    printf("\nHashvalues\taddress label");
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d\t%d\t%s", i, sy[i].add, sy[i].label);
        fprintf(fp, "\n%d%d%s", i, sy[i].add, sy[i].label);
    }
    fclose(fp);
}