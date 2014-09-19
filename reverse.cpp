// to show it's a C-style string so use the '\0'

#include <stdio.h>

void reverse(char str[])
{
    if(sizeof(str) == 0) return;
    int i = 0, j = 0;
    char tmp;
    if (str)
    {
        while (str[i] != '\0')
        {
            ++i;
        }
        --i;
        while (j < i)
        {
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i--;
            j++;
        }
    }
}

int main()
{
    char str[] = "abcdefghf";
    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);
    return 0;
}
