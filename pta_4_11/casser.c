#include <stdio.h>

int main()
{
    char s[1000];
    gets(s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = ((s[i] - 'A') + 21) % 26 + 'A';
        }
    }
    if (s[0] == '\0')
    {
        printf("NULL");
    }
    else
    {
        printf("%s", s);
    }

    return 0;
}