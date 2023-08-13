#include <iostream>

using namespace std;
int N, M;
char city[1000][1000];
int visit[1000][1000];
int MinTraps = 0;

bool notSearched() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (city[i][j] != 'X') return 1;
		}
	}
	return 0;
}

void search(int x, int y) {
	if (city[x][y] == 'X') {
		//searched
		if (visit[x][y] == 1) {
			MinTraps++;
		}
	}
	else {
		char c = city[x][y];
		city[x][y] = 'X';
		visit[x][y] = 1;
		if (c == 'N') {
			search(x - 1, y);
		}
		else if (c == 'W') {
			search(x, y - 1);
		}
		else if (c == 'S') {
			search(x + 1, y);
		}
		else {
			search(x, y + 1);
		}
		visit[x][y] = 2;

	}
}

int main(void) {
	cin >> N >> M;
	//do input for dmoj
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> city[i][j];
			visit[i][j] = 0;
		}
	}
	//done getting input
	while (notSearched()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (city[i][j] != 'X') {
					search(i, j);
				}
			}
		}
	}
	cout << MinTraps;
}