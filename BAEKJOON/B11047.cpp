#include "../header.h"
/*
https://www.acmicpc.net/problem/11047
*/

/*
void ProblemSolved() {
	int N=0, K=0,answer=0;
	cin >> N >> K;
	int* money_arr = new int[N];
	for (int times = N-1; times >= 0; times--) {
		cin >> money_arr[times];
	}
	
	int money_pointer = 0;
	while (K > 0) {
		if (money_arr[money_pointer] <= K) {
			answer += K / money_arr[money_pointer];
			K %= money_arr[money_pointer];
		}
		money_pointer++;
	}

	cout << answer;

	return;
}
*/