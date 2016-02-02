
#include <iostream>
#include <cstring>

using namespace std;

char* replace(char* s)
{
    if (s == NULL) return NULL;
    int len = strlen(s);
    if (len == 0) return NULL;
    int spacecount = 0;
    for(int i = 0; i < len; i++) {
        if (s[i] == ' ')
            spacecount++;
    }
    int newlen = 2 * spacecount + len;
    s[newlen-1] = '\0';

    for (int i = len-1; i != 0; i--) {
        if (s[i] == ' ') {
            s[newlen -1] = '0';
            s[newlen -2] = '2';
            s[newlen -3] = '%';
            newlen = newlen -3;
        } else {
            s[newlen-1] = s[i];
            newlen = newlen -1;
        }
    }
    return s;
}

int main()
{
    char s[1024];
    strcpy(s, "en aaa ZZZ");

    cout << s << endl;

    cout << replace(s) << endl;

    return 0;
}
              
