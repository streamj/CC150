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

int main()
{
    char str[] = "abcdefghf";
    char str1[] = "";
    char str2[] = "a";

    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);

    printf("%s\n", str1);
    reverse(str1);
    printf("%s\n", str1);

    printf("%s\n", str2);
    reverse(str2);
    printf("%s\n", str2);
    
    return 0;
}
