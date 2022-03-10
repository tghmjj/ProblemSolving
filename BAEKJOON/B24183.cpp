#include "../header.h"
/*
https://www.acmicpc.net/problem/24183
*/

void ProblemSolved() {
	double c4, a3, a4;
	c4 = 229.0 * 324.0 / 1000000.0;
	a3 = 297.0 * 420.0 / 1000000.0;
	a4 = 210.0 * 297.0 / 1000000.0;
	double a, b, c,answer;
	cin >> a >> b >> c;
	answer = c4 * a * 2;
	answer += a3 * b * 2;
	answer += a4 * c;
	cout << answer;
	
	return;
}