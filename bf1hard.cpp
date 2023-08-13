#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main() {
	long int n;
	cin>>n;
	long long int nums[n];
	for (int i = 0; i < n; i++)cin >> nums[i];
	qsort(nums, n, sizeof(long long int), compare);
	for (int i = 0; i < n; i++)cout << nums[i] << endl;
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	return 0;
}