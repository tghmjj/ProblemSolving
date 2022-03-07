#include "../header.h"
/*
https://www.acmicpc.net/problem/1074
*/

int N, r, c;
int counter = 0;
int squ_two(int N) {
	if (N == 0)
		return 1;
	else
		return squ_two(N - 1) * 2;
}
void SetZNum(int arr_size, int row = 0, int col = 0) {
	if (arr_size >= 4) {
		int half_size = arr_size / 2;

		if (r < row+half_size && c < col+half_size) {//1
			SetZNum(half_size, row , col );
		}
		else if (r < row + half_size && c >= col + half_size) {//2
			counter += half_size * half_size;
			SetZNum(half_size, row, col+half_size);
		}
		else if (r >= row + half_size && c < col + half_size) {//3
			counter += half_size * half_size*2;
			SetZNum(half_size, row + half_size, col );
		}
		else if (r >= row + half_size && c >= col + half_size) {//4
			counter += half_size * half_size*3;
			SetZNum(half_size, row + half_size, col + half_size);
		}
		
	}
	else {
		if (row == r && col == c) {
			cout << counter;
			exit(0);
		}
		else counter++;
		if (row == r && col+1 == c) {
			cout << counter;
			exit(0);
		}
		else counter++;
		if (row+1 == r  && col == c) {
			cout << counter;
			exit(0);
		}
		else counter++;
		if (row+1 == r && col+1 == c) {
			cout << counter;
			exit(0);
		}
		else counter++;
	}
}
void ProblemSolved() {
	cin >> N >> r >> c;
	int arr_size = squ_two(N);
	SetZNum(arr_size);
	return;
}

