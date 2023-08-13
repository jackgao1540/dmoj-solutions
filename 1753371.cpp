#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int N;
        scanf("%d", &N);
        stack <int> mountain;
        for(int i = 0, x; i < N; i++){
            scanf("%d", &x);
            mountain.push(x);
        }
        stack <int> branch;
        int next = 1;
        while(next < N + 1){
            if(!branch.empty() && branch.top() == next){
                branch.pop();
                next++;
                continue;
            }
            if(!mountain.empty() && mountain.top() == next){
                mountain.pop();
                next++;
                continue;
            }
            //move from mountain to branch
            if(mountain.empty()){
                //no solution
                cout << "N" << endl;
                break;
            }
            branch.push(mountain.top());
            mountain.pop();
        }
        if(next > N)cout << "Y" << endl;
    }
    return 0;
}