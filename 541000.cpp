#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_intervals;
    int days;
    int num_jumps=2147483647;
    cin>>num_intervals>>days;
    if(days<0 ){
        days = -days;
    }
    int intervals[num_intervals];
    for (int i = 0; i < num_intervals; i++){
        cin>>intervals[i];
        if(!(days%intervals[i])){
        if (days/intervals[i] < num_jumps){
            num_jumps  = days/intervals[i];
        }
        }
    }
    if (num_jumps < 2147483647){
        cout<<num_jumps;
    }else{
        cout<<"This is not the best time for a trip.";
    }
    return 0;
}