#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
class car {
public:
	int num=0;
	int v=0;
	int w=0;
	
	void push(int _num, int _v, int _w) {
		num = _num;
		v = _v;
		w = _w;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/**************/
	int n;
	cin >> n;
	car* c_arr = new car[1001];
	bool car_in_arr[1001];
	for (int i = 1; i < 1001; ++i) {
		car_in_arr[i] = false;
	}
	int v, w;

	for (int i = 1; i <= n; i++) {
		cin >> v >> w;
		if (c_arr[v].num == 0) {
			c_arr[v].push(i, v, w);
			car_in_arr[v] = true;
		}
		else if (c_arr[v].w <= w) {
			c_arr[v].push(i, v, w);
			car_in_arr[v] = true;
		}
	}
	int answer = 0;
	for (int i = 1; i < 1001; i++) {
		if (car_in_arr[i]) {
			answer += c_arr[i].num;
		}

	}
	cout << answer;

	/**************/
	return 0;
}