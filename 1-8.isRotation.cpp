#include <string>
#include <iostream>

using namespace std;

bool isSubstring(string s1, string s2)
{
    if (s1.find(s2) != string::npos) {
        return true;
    }
    else {
        return false;
    }
}

bool isRotation(string s1, string s2)
{
    int len = s1.length();
    if (len == s2.length() && len > 0){
        string s1s1 = s1 + s1;
        return isSubstring(s1s1, s2);
    }
    return false;
}



int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    cout << s1 << "\n";
    cout << s2 << "\n";
    
    if (isRotation(s1, s2)){
        cout << "yes" << endl;
    }

    // system("pause");

    return 0;
}
