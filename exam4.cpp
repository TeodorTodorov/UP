/////////////////////////////////////////////////////////////
//
// Author: Teodor Todorov Valchev
// FN: 81475
// Program: Компютърни науки
// Date: 23.08.2017
//

#include <iostream>
using namespace std;


int isAlpha(char a) {
	if (a == 'A' || a == 'B' || a == 'C' || a == 'D') {
		return 1;
	}
	else {
		return 0;
	}
}
int isDigit(char a) {
	if (a == '1' || a == '2' || a == '3' || a == '4') {
		return 1;
	}
	else {
		return 0;
	}
}
int countAlphas(char** board, int rows, int cols, int rowX, int colY) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;

	if (rowX < rows && rowX >= 0 && colY + 1 < cols && colY + 1 >= 0) {
		a = isAlpha(board[rowX][colY + 1]);
	}
	if (rowX < rows && rowX >= 0 && colY - 1 < cols && colY - 1 >= 0) {
		b = isAlpha(board[rowX][colY - 1]);
	}
	if (rowX - 1 < rows && rowX - 1 >= 0 && colY - 1 < cols && colY - 1 >= 0) {
		c = isAlpha(board[rowX - 1][colY - 1]);
	}
	if (rowX - 1 < rows && rowX - 1 >= 0 && colY < cols && colY >= 0) {
		d = isAlpha(board[rowX - 1][colY]);
	}
	if (rowX - 1 < rows && rowX - 1 >= 0 && colY + 1 < cols && colY + 1 >= 0) {
		e = isAlpha(board[rowX - 1][colY + 1]);
	}
	if (rowX + 1 < rows && rowX + 1 >= 0 && colY < cols && colY >= 0) {
		f = isAlpha(board[rowX + 1][colY]);
	}
	if (rowX + 1 < rows && rowX + 1 >= 0 && colY + 1 < cols && colY + 1 >= 0) {
		g = isAlpha(board[rowX + 1][colY + 1]);
	}
	if (rowX + 1 < rows && rowX + 1 >= 0 && colY - 1 < cols && colY - 1 >= 0) {
		g = isAlpha(board[rowX + 1][colY - 1]);
	}
	return a + b + c + d + e + f + g;


}
int countDigits(char** board, int rows, int cols, int rowX, int colY) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;

	if (rowX < rows && rowX >= 0 && colY + 1 < cols && colY + 1 >= 0) {
		a = isDigit(board[rowX][colY + 1]);
	}
	if (rowX < rows && rowX >= 0 && colY - 1 < cols && colY - 1 >= 0) {
		b = isDigit(board[rowX][colY - 1]);
	}
	if (rowX - 1 < rows && rowX - 1 >= 0 && colY - 1 < cols && colY - 1 >= 0) {
		c = isDigit(board[rowX - 1][colY - 1]);
	}
	if (rowX - 1 < rows && rowX - 1 >= 0 && colY < cols && colY >= 0) {
		d = isDigit(board[rowX - 1][colY]);
	}
	if (rowX - 1 < rows && rowX - 1 >= 0 && colY + 1 < cols && colY + 1 >= 0) {
		e = isDigit(board[rowX - 1][colY + 1]);
	}
	if (rowX + 1 < rows && rowX + 1 >= 0 && colY < cols && colY >= 0) {
		f = isDigit(board[rowX + 1][colY]);
	}
	if (rowX + 1 < rows && rowX + 1 >= 0 && colY + 1 < cols && colY + 1 >= 0) {
		g = isDigit(board[rowX + 1][colY + 1]);
	}
	if (rowX + 1 < rows && rowX + 1 >= 0 && colY - 1 < cols && colY - 1 >= 0) {
		g = isDigit(board[rowX + 1][colY - 1]);
	}
	return a + b + c + d + e + f + g;


}


char **readInput(int rows, int cols) {

	char** result = new char*[rows];
	for (int i = 0; i < rows; i++) {
		result[i] = new char[cols];
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> result[i][j];
		}

	}

	return result;
}
int main()
{

	int m, n, games;
	cin >> m;
	cin >> n;
	int rows = m;
	int cols = n;
	char** board = readInput(m, n);
	cin >> games;
	//cout << "games" << games;
	for (int p = 0; p < games; p++)
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < n; j++) {
				if (isDigit(board[i][j])) {
					int digits = countDigits(board, rows, cols, i, j);
					int alphas = countAlphas(board, rows, cols, i, j);
					if (digits > alphas) {
						if (board[i][j] < '4') {
							board[i][j] ++;
						}
						if (digits < alphas) {
							if (board[i][j] > '1') {
								board[i][j] --;
							}
						}

					}
				}
					if (isAlpha(board[i][j])) {
						int digits = countDigits(board, rows, cols, i, j);
						int alphas = countAlphas(board, rows, cols, i, j);
						if (digits < alphas) {
							if (board[i][j] < 'D') {
								board[i][j]++;
							}

						}
						if (digits > alphas) {
							if (board[i][j] > 'A') {
								board[i][j]--;
							}

						}
					}
				}
			}

		}

	

	std::cout << "Hello world!\n";


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}