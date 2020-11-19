#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int number = 0;

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

bool validIdentifier(char *str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}

bool isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") || !strcmp(str, "main") ||
        !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isInteger(char *str)
{
    int i, len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

bool isRealNumber(char *str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

char *subString(char *str, int left, int right)
{
    int i;
    char *subStr = (char *)malloc(
        sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

void parse(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right)
    {
        if (isDelimiter(str[right]) == false)
            right++;
        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
            {
                number++;
                printf("%d\t ", number);
                printf("%c\t\t ", str[right]);
                printf("an operator\n");
            }
            else if (str[right] != ' ')
            {
                number++;
                printf("%d\t ", number);
                printf("%c\t\t ", str[right]);
                printf("a special symbol\n");
            }
            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);
            if (isKeyword(subStr) == true)
            {
                number++;
                printf("%d\t ", number);
                printf("%s\t\t ", subStr);
                printf("a keyword\n");
            }
            else if (isInteger(subStr) == true)
            {
                number++;
                printf("%d\t ", number);
                printf("%s\t\t ", subStr);
                printf("an integer\n");
            }
            else if (isRealNumber(subStr) == true)
            {
                number++;
                printf("%d\t ", number);
                printf("%s\t\t ", subStr);
                printf("a real number\n");
            }
            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false)
            {
                number++;
                printf("%d\t ", number);
                printf("%s\t\t ", subStr);
                printf("a valid identifier\n");
            }
            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
            {
                number++;
                printf("%d\t ", number);
                printf("%s\t\t ", subStr);
                printf("not a valid identifier\n");
            }
            left = right;
        }
    }
    return;
}
int main()
{
    char str[100] = "void main(){ int a=5; }";
    printf("TOKEN SEPARATION\n");
    printf("token no. token name token-type\n");
    parse(str);
    return (0);
}