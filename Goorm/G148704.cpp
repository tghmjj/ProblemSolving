#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/**************/
	int n, k;
	cin >> n >> k;

	list<string>* l = new list<string>[101];
	int* arr_len = new int[101];
	for (int i = 0; i < 101; i++) {
		arr_len[i] = 0;
	}
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		l[temp.length()].push_back(temp);
		arr_len[temp.length()]++;
	}
	for (int i = 1; i < 101; i++) {
		if (k <= arr_len[i]) {
			l[i].sort();
			
			for (int j = 0; j < k-1; j++) {
				l[i].pop_front();
			}
			cout << l[i].front();
			return 0;
		}
		k -= arr_len[i];
	}
	


	/**************/
	return 0;
}