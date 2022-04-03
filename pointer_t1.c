#include <stdio.h>
void geeks()
{
    char a;
    char *b;
    char **c;
    a = 'g';
    b = &a;
    c = &b;
    **c = 'h';
    printf("%c\n", **c);
    printf("%d", &c);
}

int main()
{
    geeks();
}