#include "../header.h"
/*
https://www.acmicpc.net/problem/18870
*/
#include <vector>
#include <algorithm>
void ProblemSolved() {
	int N;
	cin >> N;

	vector<int> sorted_arr, list_arr;
	int temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		sorted_arr.push_back(temp);
		list_arr.push_back(temp); 
	}

	sort(sorted_arr.begin(), sorted_arr.end()); //정렬
	sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end()); //중복값제거

	for (int i = 0; i < N; i++) {
		temp = lower_bound(sorted_arr.begin(), sorted_arr.end(), list_arr[i]) - sorted_arr.begin() ;
		cout << temp << " ";
	}

	return;
}

