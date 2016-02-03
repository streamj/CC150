#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

void setZero(int matrix[][5], int m, int n) 
{
	bool row[4];
	bool col[5];
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			if (matrix[i][j] == 0) {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main()
{
	int square[4][5] = {
		{ 1, 2, 3, 4, 3 },
		{ 5, 6, 7, 8, 0 },
		{ 9, 10, 11, 12, 3 },
		{ 13, 14, 15, 16, 3 }
	};

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			cout << square[i][j] << ",";
		}
		cout << endl;
	}

	setZero(square, 4, 5);

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			cout << square[i][j] << ",";
		}
		cout << endl;
	}

	return 0;
}
