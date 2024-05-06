#include <stdio.h>

int main()
{
    char a = 48;
    unsigned char b = 48;
    int c1 = a;
    int c2 = b;
    char s1[20];
    char s2[20];
    sprintf(s1, "aa is %3d", a);
    sprintf(s2, "bb is %3d", b);
    printf("%3d", c2);
    printf("%3d", c1);
    printf("%s", s1);
    printf("%s", s2);
    return 0;
}