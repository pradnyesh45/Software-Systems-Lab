%{
#include<stdio.h>
int count=0;
%}
op [+-*/]
letter [a-zA-Z]
digitt [0-9]
id {letter}*|({letter}{digitt})+
notid ({digitt}{letter})+

%option noyywrap

%%
[\t\n]+

{id} {printf("%s is an identifier\n", yytext); count++;}
{notid} {printf("%s is not an identifier\n", yytext);}
%%
int main()
{
FILE *fp;
char file[10];
printf("\nEnter the filename: ");
scanf("%s", file);
fp=fopen(file,"r");
yyin=fp;
yylex();
printf("Total identifiers are: %d\n", count);
return 0;
}