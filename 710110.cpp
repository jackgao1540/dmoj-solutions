#include <iostream>
#include <vector>

using namespace std;

char grid[25][25];
int SquareMetres, roomSize, rooms, x, y;
vector <int> roomSizes;
bool canFind() {
	for (int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++)
			if (grid[i][j] == '.') {
				return 1;
			}
	}
	return 0;
}

void dfs(int c, int d, int rooms) {
	grid[c][d] = 'X';
	roomSize++;
	if (c - 1 >= 0 && grid[c - 1][d] == '.') dfs(c - 1, d, rooms);
	if (c + 1 <= x && grid[c + 1][d] == '.') dfs(c + 1, d, rooms);
	if (d - 1 >= 0 && grid[c][d - 1] == '.') dfs(c, d - 1, rooms);
	if (d + 1 <= y && grid[c][d + 1] == '.') dfs(c, d + 1, rooms);
}

void quickSort( int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = roomSizes[(left + right) / 2];
	while (i <= j) {
		while (roomSizes[i] < pivot)
			i++;
		while (roomSizes[j] > pivot)
			j--;
		if (i <= j) {
			tmp = roomSizes[i];
			roomSizes[i] = roomSizes[j];
			roomSizes[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort( i, right);
}

int main(void) {
	rooms = 0;
	roomSize = 0;
	cin >> SquareMetres >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> grid[i][j];
	while (canFind() == true) {
		int emptyX, emptyY;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++)
				if (grid[i][j] == '.') {
					emptyX = i;
					emptyY = j;
					break;
					break;
				}
		}
		roomSize = 0;
		dfs(emptyX, emptyY, rooms);
		roomSizes.push_back(roomSize);
		rooms++;
	}
	quickSort(0, roomSizes.size() - 1);
	int m = SquareMetres;
	int cnt = 0;
	for (int i = roomSizes.size() - 1; i >= 0; i--) {
		if (m >= roomSizes[i]) { m -= roomSizes[i]; cnt++; }
		else break;
	}
	if(cnt != 1)cout << cnt << " rooms, " << m << " square metre(s) left over" << endl;
	else cout << cnt << " room, " << m << " square metre(s) left over" << endl;
}