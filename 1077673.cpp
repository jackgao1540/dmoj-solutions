#include <iostream>
#include <climits>

using namespace std;

int n, m;
int pieces[201] = {0}, numPieces[201] = {0}, dp[201][20001] = {0};
int used[201][20001] = {0};

int min(int a, int b){
  return a < b ? a : b;
}
/*
//Quicksort 
void quickSort(int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = pieces[(left + right) / 2];
	while (i <= j) {
		while (pieces[i] < pivot)
			i++;
		while (pieces[j] > pivot)
			j--;
		if (i <= j) {
			tmp = pieces[i];
			pieces[i] = pieces[j];
			pieces[j] = tmp;
      tmp = numPieces[i];
      numPieces[i] = numPieces[j];
      numPieces[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}
*/

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> pieces[i];
  }
  //quickSort(1, n);
  for(int i = 1; i <= n; i++){
    cin >> numPieces[i];
  }
  cin >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      dp[i][j] = -1;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(pieces[i] > j){
        //dp is equal to the last one
        if(i > 1){
          //equal to last one
          dp[i][j] = dp[i - 1][j];
          used[i][j] = 0;
        }//equal to -1
        else {
          dp[i][j] = -1;
          used[i][j] = 0;
        }
      }else{
        if(i > 1){
          //equal to the minimum of (i - 1, j), 1 + (i, j - pieces[i]), 1 + (i - 1, j - pieces[i])
          int a = dp[i - 1][j], b = dp[i][j - pieces[i]], c = dp[i - 1][j - pieces[i]];
          int A = 0, B = used[i][j - pieces[i]], C = 0;
          if(a == -1 && b == -1 && c == -1){
            dp[i][j] = -1;
            used[i][j] = 0;
          }else if(a == -1){
            //min of b and c, check both
            if(b == -1){
              if(c == -1){
                dp[i][j] = -1;
                used[i][j] = 0;
              }else{
                dp[i][j] = 1 + c;
                used[i][j] = 1 + C;
              }
            }else if(c == -1){
              //is b
              if(B < numPieces[i]){dp[i][j] = 1 + b;
              used[i][j] = 1 + B;
              }else{
                dp[i][j] = -1;
                used[i][j] = 0;
              }
            }else{
              //min of both
              if(B  < numPieces[i]){
                dp[i][j] = min(1 + b, 1 + c);
                if(dp[i][j] == 1 + b){
                  used[i][j] = 1 + B;
                }else used[i][j] = 1 + C;
              }else{
                 dp[i][j] = c + 1;
                 used[i][j] = C + 1;
              }
            }
          }else if(b == -1){
            //min of a and c, check c
            if(c == -1){
              //is a
              dp[i][j] = a;
              used[i][j] = A;
            }else{
              //is min of both
              dp[i][j] = min(a, 1 + c);
              if(dp[i][j] == a){
                used[i][j] = A;
              }else used[i][j] = 1 + C;
            }
          }else if(c == -1){
            //min of a and b
            if(B < numPieces[i]){
              dp[i][j] = min(a, 1 + b);
               if(dp[i][j] == a){
                used[i][j] = A;
              }else used[i][j] = 1 + B;
            }else{
              dp[i][j] = a;
              used[i][j] = A;
            }
          }else{
            //min of all three
            if(B < numPieces[i]){
              dp[i][j] = min(min(1 + b, 1 + c), a);
              if(dp[i][j] == a){
                used[i][j] = A;
              }else if(dp[i][j] == 1 + b){
                used[i][j] = 1 + B;
              }else{  
                used[i][j] = 1 + C;
             }
            }else{
              dp[i][j] = min(a, 1 + c);
              if(dp[i][j] == a){
                used[i][j] = A;
              }else used[i][j] = 1 + C;
            }
          }
        }//equal to current one
        else{
          int b = dp[i][j - pieces[i]];
          if(b == -1){
            dp[i][j] = -1;
            used[i][j] = 0;
          }else{
            if(used[i][j - pieces[i]] < numPieces[i]){
              dp[i][j] = 1  + dp[i][j - pieces[i]];
              used[i][j] = used[i][j - pieces[i]] + 1;
            }else{
              dp[i][j] = -1;
              used[i][j] = 0;
            }
          }
        }
      }
      //cout << dp[i][j] << " ";
    }
    //cout << endl;
  }
  //cout << endl;
 // for(int i = 1; i <= n; i++){
   // for(int j = 1; j <= m; j++){cout << used[i][j];
  //}cout << endl;}
  cout << dp[n][m];
}