#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int>> px, py;

int min(int a, int b){
  return a < b ? a : b;
}

int max(int a, int b){
  return a > b ? a : b;
}

//comparison
bool isGreaterX(pair <int, int> a, pair <int, int> b){
  if(a.first > b.first)return true;
  else if(a.first < b.first)return false;
  else{
    return a.second > b.second ? true : false;
  }
}
bool isGreaterY(pair <int, int> a, pair <int, int> b){
  if(a.second > b.second)return true;
  else if(a.second < b.second)return false;
  else{
    return a.first > b.first ? true : false;
  }
}
bool isLessX(pair <int, int> a, pair <int, int> b){
  if(a.first < b.first)return true;
  else if(a.first > b.first)return false;
  else{
    return a.second < b.second ? true : false;
  }
}
bool isLessY(pair <int, int> a, pair <int, int> b){
  if(a.second < b.second)return true;
  else if(a.second > b.second)return false;
  else{
    return a.first < b.first ? true : false;
  }
}
/*
//Quicksort 
void sortX(vector <pair <int, int>> arr, int left, int right) {
	int i = left, j = right;
	pair <int, int> tmp;
	pair <int, int> pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (isLessX(arr[i], pivot))
			i++;
		while (isGreaterX(arr[j], pivot))
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		sortX(arr, left, j);
	if (i < right)
		sortX(arr, i, right);
}

void sortY(vector <pair <int, int>> arr, int left, int right) {
	int i = left, j = right;
	pair <int, int> tmp;
	pair <int, int> pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (isLessY(arr[i], pivot))
			i++;
		while (isGreaterY(arr[j], pivot))
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		sortY(arr, left, j);
	if (i < right)
		sortY(arr, i, right);
}
*/
int main() {
  int numB, numP;
  cin >> numB;
  vector <pair <int, int>> buildings;
  for(int i = 0; i < numB; i++){
    int a, b;
    cin >> a >> b;
    buildings.push_back(make_pair(a, b));
    px.push_back(make_pair(a, b));
    py.push_back(make_pair(b, a));
  }
  sort(px.begin(), px.end());
  sort(py.begin(), py.end());
  cin >> numP;
  vector <pair <int, int>> turnPoints;
  for(int i = 0; i < numP; i++){
    int a, b;
    cin >> a >> b;
    turnPoints.push_back(make_pair(a, b));
  }
  long long ans = 0;
  //test
  /*
  for(int i = 0; i < numB; i++){
    cout << "( " << px[i].first << ", " << px[i].second << "),  ";
  }
  cout << endl;
  for(int i = 0; i < numB; i++){
    cout << "( " << py[i].first << ", " << py[i].second << "),  ";
  }
  */
  for(int i = 0; i < numP - 1; i++){
    int x1, y1, x2, y2;
    x1 = turnPoints[i].first;
    y1 = turnPoints[i].second;
    x2 = turnPoints[i + 1].first;
    y2 = turnPoints[i + 1].second;
    if(y1 == y2){
      //horizontal move
      //find first one that is 
      int lft = lower_bound(py.begin(), py.end(), make_pair(y1, min(x1, x2))) - py.begin();
      int rt = upper_bound(py.begin(), py.end(), make_pair(y1, max(x1, x2))) - py.begin();
      ans += rt - lft;
    }else{
      //vertical move
      int lft = lower_bound(px.begin(), px.end(), make_pair(x1, min(y1, y2))) - px.begin();
      int rt = upper_bound(px.begin(), px.end(), make_pair(x1, max(y1, y2))) - px.begin();
      ans += rt - lft;
    }
  }
  cout << ans;
}