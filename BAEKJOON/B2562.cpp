#include "../header.h"
/*
https://www.acmicpc.net/problem/2562
*/


void ProblemSolved() {

	int Temp, Max=-1,Max_Time=0;

	for (int Time = 1; Time < 10; Time++) {
		cin >> Temp;
		if (Temp > Max) {
			Max = Temp;
			Max_Time = Time;
		}
	}
	cout << Max << "\n" << Max_Time;
	return;
}
