#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	int val;
};

vector <int> a, b;

int main() {
	int x, y;
  cin >> x >> y;
  for(int i = 0; i < x; i++){
    int d;
    cin >> d;
    a.push_back(d);
  }
  for(int i = 0; i < y; i++){
    int d;
    cin >> d;
    b.push_back(d);
  }
	vector<vector<node>> graph;
	node temp;
	temp.val = 0;
	vector<node> t;
	for (int i = 0; i < a.size(); i++) {
		t.push_back(temp);
	}
	for (int i = 0; i < b.size(); i++) {
		graph.push_back(t);
	}
	// graph filled with zeroes and empty strings
	// start from 0, 0 and progress towards b.size() - 1, a.size() - 1
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			// if b[i] = a[j] then do last diagonal++
			// else take the max of two adjacent
			if (b[i] == a[j]) {
				if (i > 0 && j > 0) {
					graph[i][j] = graph[i - 1][j - 1];
          graph[i][j].val++;
				} else{
					graph[i][j].val = 1;
        }
			} else {
				if (i > 0 && j > 0) {
					graph[i][j] = (graph[i - 1][j].val > graph[i][j - 1].val ? graph[i - 1][j] : graph[i][j - 1]);
				} else {
					if (j > 0 && !(i > 0)) {
            graph[i][j] = graph[i][j - 1];
					} else if (i > 0 && !(j > 0)) {
            graph[i][j] = graph[i - 1][j];
					} else {
            graph[i][j].val = 0;
					}
				}
			}
		}
	}
	cout << graph[b.size() - 1][a.size() - 1].val; //<< endl << "The sequence is: ";
  //for(int i = 0; i < graph[b.size() - 1][a.size() - 1].sequence.size(); i++){
  //  cout << graph[b.size() - 1][a.size() - 1].sequence[i] << " ";
  //}
	return 0;
}