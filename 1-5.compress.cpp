#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string my_itoa(int num)
{
	stringstream sstrm;
	sstrm << num;
	return sstrm.str();
}

string compression(string str)
{
	string buffer;
	char c = str[0];
	int count = 1;
	for (string::size_type i = 1; i < str.size(); i++){
		if (str[i] == c) {
			count++;
		}
		else{
			buffer.push_back(c);
			buffer += my_itoa(count);
			c = str[i];
			count = 1;
		}
	}
	buffer.push_back(c);
	buffer += my_itoa(count);

	return buffer.size() < str.size() ? buffer : str;
}



int main()
{
	string a1 = "aabbccdd"; // a2b2c2d2
	string a2 = "abc";      // a1b1c1
	string a3 = "aaabbbccccddddeee"; // a3b3c3
	string a4 = "";

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;

	cout << compression(a1) << endl;
	cout << compression(a2) << endl;
	cout << compression(a3) << endl;
	cout << compression(a4) << endl;


	return 0;
}
