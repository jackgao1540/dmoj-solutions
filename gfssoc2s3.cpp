#include <bits/stdc++.h>

using namespace std;

int n;
double a, b; 

int main()
{
    scanf("%d%lf%lf", &n, &a, &b);
    printf("%.9f\n", (-b/a)/n);
    return 0;
}