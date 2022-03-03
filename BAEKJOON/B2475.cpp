#include "../header.h"
/*
https://www.acmicpc.net/problem/2475
*/


void ProblemSolved() {
	int temp = 0, answer = 0;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		answer += temp*temp;
	}
	cout << answer %10;

	return;
}
