#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void swap(int& a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void trans(int a[][4], int n)
{
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			// 交换对角线的元素
			swap(a[i][j], a[j][i]);
		}
	}
	for (int i = 0; i < n / 2; ++i){
		for (int j = 0; j < n; ++j){
			swap(a[i][j], a[n - 1 - i][j]);
		}
	}
}


int main()
{
	int square[4][4] = {
		{1, 2,  3,  4},
		{5, 6,  7,  8},
		{9, 10, 11, 12},
		{13,14, 15, 16}
	};
	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << square[i][j] << ",";
		}
		cout << endl;
	}

	trans(square, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << square[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
