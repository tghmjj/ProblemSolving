#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int my_index = 0;
	Node** Connection_arr=NULL;
	int arr_index = 0;
	bool passed = false;
	int called_counter = 0;
	void init(int n,int i) {
		Connection_arr = new Node*[n];
		my_index = i;
	}
	void push(Node& n) {
		Connection_arr[arr_index] = &n;
		arr_index++;
	}

	void spread(int called_index) {

		passed = true;
		for (int i = 0; i < arr_index; i++) {
			if (Connection_arr[i]->my_index == called_index || Connection_arr[i]->passed == true) {
				continue;
			}
			
			Connection_arr[i]->spread(called_index);
		}

	}
};
class Graph {
private:
	int N=0,M=0;
	Node* Node_arr=NULL,*Temp_arr=NULL;
	int index=0;
	int answer = 0;
public:
	void init(int n, int m) {
		N = n;
		M = m;
		Node_arr = new Node[N];
		for (int i = 0; i < n; i++) {
			Node_arr[i].init(N,i);
		}
	}
	void push(int u, int v) {
		Node_arr[u - 1].push(Node_arr[v - 1]);
		Node_arr[v - 1].push(Node_arr[u - 1]);
	}
	void calc() {

		for (int i = 0; i < N; i++) {
			
			Node* next_node = &Node_arr[i];
			if (next_node->passed) {
				continue;
			}
			else {
				next_node->spread(i);
				answer++;
			}

		}
		delete Node_arr;
	}
	int get_answer() {
		return answer;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	Graph g;
	g.init(N, M);
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		g.push(u, v);
	}
	g.calc();
	cout << g.get_answer();
	return 0;
}
