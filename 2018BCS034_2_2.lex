%{
#include <stdio.h>
    int lc = 0, sc = 0, nw = 0, ch = 0;
%}

%option noyywrap

%% 
. ch++;       //characters counter
([a-zA-Z0-9])* nw++; //words counter
\n lc++;    //line counter

%%

    main()
{
    yylex();

    printf("\nNo. of characters=%d", ch);
    printf("\nNo. of words=%d", nw);
    printf("\nNo. of lines=%d", lc);

}