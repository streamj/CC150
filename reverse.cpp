#include <stdio.h>

void reverse(char *str) {  
    char temp;  
    int len = strlen(str);  
    int i;  
      
    for (i = 0; i < len / 2; i++) {  
        temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
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
