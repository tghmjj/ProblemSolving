#include "../header.h"
/*
https://www.acmicpc.net/problem/1261
*/
#include <queue>
#define INF 987654321
#define endl "\n"
int row, col;
int** Map;
int** Dist;//거리 누계
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
void print() {
	cout << "-----------" << endl;
	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < col; ++y) {
			if (Dist[x][y] == INF) {
				cout << -1;
			}
			else {
				cout << Dist[x][y];
			}
		}
		cout << endl;
	}
	cout << "-----------" << endl;
}
void BFS(int x = 0, int y = 0) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	Dist[x][y] = 0;

	while (!Q.empty()) {
		int targetx = Q.front().first;
		int targety = Q.front().second;
		Q.pop();
		//print();
		for (int i = 0; i < 4; ++i) {
			int nx = targetx + dx[i]; //nx,ny = 상하좌우의 값들
			int ny = targety + dy[i];

			if (nx<0 || ny<0 || nx>row - 1 || ny>col - 1) continue;

			if (Map[nx][ny] == 1) { // 벽이 있을때
				if (Dist[nx][ny] > Dist[targetx][targety] + 1) {
					Dist[nx][ny] = Dist[targetx][targety] + 1;
					Q.push(make_pair(nx, ny));
				}

			}
			else { // 없을때
				if (Dist[nx][ny] > Dist[targetx][targety]) {
					Dist[nx][ny] = Dist[targetx][targety];
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
};

void ProblemSolved() {
	cin >> col >> row;
	Map = new int* [row];
	Dist = new int* [row];
	for (int r = 0; r < row; ++r) {
		Map[r] = new int[col];
		Dist[r] = new int[col];
	}

	char temp;
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			cin >> temp;
			Map[r][c] = temp - '0';
			Dist[r][c] = INF;
		}
	}

	BFS();

	cout << Dist[row - 1][col - 1];

	return;
}