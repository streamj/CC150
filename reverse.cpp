// to show it's a C-style string so use the '\0'
#include <stdio.h>
#include <string.h>

void reverse(char str[])
{
    if (strlen(str) == 0)
    {
        printf("it's empty\n");
        return;
    }

    if (strlen(str) < 2)
    {
        printf("it's just one char\n");
        return;
    }

    int i = 0, j = 0;
    char tmp;

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

void test(char str[])
{
    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);
}

int main()
{
    char str[] = "abcdefghf";
    char str1[] = "";
    char str2[] = "a";
    
    test(str);
    test(str1);
    test(str2);
    
    return 0;
}
