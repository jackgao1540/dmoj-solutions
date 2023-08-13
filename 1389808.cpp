#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    long long int d;
    scanf("%lld", &d);
    if((d & (d - 1)) == 0)printf("T\n");
    else printf("F\n");}
    return 0;
}