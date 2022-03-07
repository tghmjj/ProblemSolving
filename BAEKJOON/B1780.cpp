#include "../header.h"
/*
https://www.acmicpc.net/problem/1780
*/

int** paper_arr, N;
int minus_one = 0, zero = 0, plus_one = 0;

// arr[row , col]

void Paper(int row_start, int row_end, int col_start, int col_end, int size) {
	bool check_paper = true;
	int start_num = paper_arr[row_start][col_start];


	for (int row = row_start; row <= row_end; row++) {
		for (int col = col_start; col <= col_end; col++) {
			if (start_num != paper_arr[row][col]) {
				check_paper = false;
				break;
			}
		}
		if (!check_paper)break;
	}

	//채워지지 않았을경우 9등분
	if (!check_paper) {
		int gap = (size / 3) - 1;

		Paper(row_start, row_start + gap, col_start, col_start + gap, gap + 1); //1번
		Paper(row_start, row_start + gap, col_start + gap + 1, col_start + gap * 2 + 1, gap + 1); //2번
		Paper(row_start, row_start + gap, col_start + (gap + 1) * 2, col_end, gap + 1); //3번

		Paper(row_start + gap + 1, row_start + gap * 2 + 1, col_start, col_start + gap, gap + 1); //4번
		Paper(row_start + gap + 1, row_start + gap * 2 + 1, col_start + gap + 1, col_start + gap * 2 + 1, gap + 1); //5번
		Paper(row_start + gap + 1, row_start + gap * 2 + 1, col_start + (gap + 1) * 2, col_end, gap + 1); //6번

		Paper(row_start + (gap + 1) * 2, row_end, col_start, col_start + gap, gap + 1); //7번
		Paper(row_start + (gap + 1) * 2, row_end, col_start + gap + 1, col_start + gap * 2 + 1, gap + 1); //8번
		Paper(row_start + (gap + 1) * 2, row_end, col_start + (gap + 1) * 2, col_end, gap + 1); //9번
	}
	else {
		switch (start_num)
		{
		case -1:minus_one++; break;
		case 0:zero++; break;
		case 1:plus_one++; break;
		default:
			break;
		}
	}

}

void ProblemSolved() {
	cin >> N;

	paper_arr = new int* [N];
	for (int index = 0; index < N; index++) {
		paper_arr[index] = new int[N];
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> paper_arr[row][col];
		}
	}

	Paper(0, N - 1, 0, N - 1, N);


	cout << minus_one << "\n" << zero << "\n" << plus_one;
	return;
}

