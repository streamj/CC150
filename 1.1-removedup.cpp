/*
*Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
*FOLLOW UP
*Write the test cases for this method.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <algorithm>

/*
string removeDup(string &str)
{
	str.erase(unique(str.begin(), str.end()), str.end());         // C++ STL算法秒杀
	return str;
}
*/

void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++) {
            if (s[i] != c){
		s[j++] = s[i];
            }
        }
	s[j] = '\0';
}

void removeDup(char s[])
{
	int len = strlen(s);
	if (len < 2) return;

	int i, j, k;
	for (i = 0; i < len; i++) {
            for (j = i + 1; j < len; j++){
                if (s[j] == s[i]) {
                    s[j] = '0';
                }
            }
        }
	squeeze(s, '0');
}
int main()
{
	char str1 [] ="abcde";
	char str2 [] ="aaabbbb";
	char str3 [] = " ";
	char str4 [] = "abababc";
	char str5 [] = "ccccc";

	printf("before removeDup %s\n", str1);
	printf("before removeDup %s\n", str2);
	printf("before removeDup %s\n", str3);
	printf("before removeDup %s\n", str4);
	printf("before removeDup %s\n", str5);

	removeDup(str1);
	removeDup(str2);
	removeDup(str3);
	removeDup(str4);
	removeDup(str5);

	printf("after removeDup %s\n", str1);
	printf("after removeDup %s\n", str2);
	printf("after removeDup %s\n", str3);
	printf("after removeDup %s\n", str4);
	printf("after removeDup %s\n", str5);

	system("pause");
	return 0;
}
