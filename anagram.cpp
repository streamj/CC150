#include <string>
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

bool isAnagram(string s, string t)
{
    if (s == "" || t == "") return false;
    if (s.size() != t.size()) return false;
    if (s == t) return false;

    int letter[256];
    memset(letter, 0, sizeof(letter));
    for (size_t i = 0; i < s.size(); i++){
        ++letter[(int)s[i]];
        --letter[(int)t[i]];
    }

    for (int i = 0; i < 256; i++) {
        if (letter[i] != 0) {
            return false;
        }
    }
    return true;
} 


void compare(string s, string t)
{
    if (isAnagram(s, t)){
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}

int main()
{
    string s1 = "abcd";
    string s2 = "cbda";
    string s3 = "abcde";
    string s4 = "";
    string s5 = "";
    string s6 = "abcd";

    compare(s1, s2); // should be yes
    compare(s1, s3); // should be no
    compare(s1, s4); // should be no
    compare(s4, s5); // should be no
    compare(s1, s6); // should be no
    
    return 0;
}
