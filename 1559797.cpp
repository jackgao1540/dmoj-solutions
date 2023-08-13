#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  double odds1Score = 0.0, odds2Score = 0.0;
  vector <double> odds1, odds2;
  for(int i = 0; i < n; i++){
    double x, y;
    cin >> x >> y;
    odds1.push_back(x);
    odds2.push_back(y);  
    odds1Score += x;
    odds2Score += y;
  }
  //cout << "sum of all 1's: " << odds1Score << endl << "sum of all 2's: " << odds2Score << endl;
  sort(odds1.begin(), odds1.end());
  sort(odds2.begin(), odds2.end());
  cout << fixed;
  cout << setprecision(4);
 // cout << "ODDS1: ";
  //for(int i = 0; i < odds1.size(); i++)cout << odds1[i] << ' ';
  //cout << endl;
  //cout << "ODDS2: ";
  //for(int i = 0; i < odds2.size(); i++)cout << odds2[i] << ' ';
  //cout << endl;
  n *= 2;
  double bestScore = max(0.0, min(odds1Score, odds2Score) - (double)n);
  int odds1Pos = 0, odds2Pos = 0;
  while(odds1Pos < odds1.size() && odds2Pos < odds2.size()){
    //remove lowest
    if(odds1Pos < odds1.size() && odds2Score < odds1Score){
      //increment odds1Pos
      odds1Score -= odds1[odds1Pos];
      n -= 1;
      odds1Pos++;
      bestScore = max(bestScore, min(odds1Score, odds2Score) - (double)n);
    }else{
      //increment odds2Pos
      odds2Score -= odds2[odds2Pos];
      n -= 1;
      odds2Pos++;
      bestScore = max(bestScore, min(odds1Score, odds2Score) - (double)n);
    }
    //cout << "ODDS1POS: " << odds1Pos << " ODDS2POS: " << odds2Pos << endl;
  }
  cout << bestScore << endl;
}