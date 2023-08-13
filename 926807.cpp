#include <bits/stdc++.h>

using namespace std;
    int n, m;
bool isSafe(int board[100][100], int row, int col){
    int i, j;
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;
    //check right
        for (i = col; i < n; i++)
        if (board[row][i])
            return false;
    // check top
    for (i = row; i >= 0; i--)
        if (board[i][col])
            return false;
    //check bottom
        for (i = row; i < n; i++)
        if (board[i][col])
            return false;
    //check right diag up
        for (i=row, j=col; i>=0 && j < n; i--, j++)
        if (board[i][j])
            return false;
    //check right diag down
        for (i=row, j=col; i < n && j < n; i++, j++)
        if (board[i][j])
            return false;
    return true;
}
int main() {
    int board[100][100] = {0};
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isSafe(board, i, j))count++;
        }
    }
    cout << count;
    return 0;
}