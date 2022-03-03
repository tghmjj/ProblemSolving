#include "../header.h"
/*
https://www.acmicpc.net/problem/2884
*/


void ProblemSolved() {
	int Hour, Minute;
	cin >> Hour >> Minute;

	if (Minute < 45) {
		if (Hour == 0) {
			Hour = 23;
		}
		else {
			Hour--;
		}
		Minute += 15;
	}
	else {
		Minute -= 45;
	}

	cout << Hour << " " << Minute;

	return;
}
