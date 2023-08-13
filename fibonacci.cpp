#include <iostream>
using namespace std;
void multiply(unsigned long long int F[2][2], unsigned long long int M[2][2]);

void power(unsigned long long int F[2][2], unsigned long long int n);

/* function that returns nth Fibonacci number */
unsigned long long int fib(unsigned long long int n)
{
	unsigned long long int F[2][2] = { { 1,1 },{ 1,0 } };
	if (n <= 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(unsigned long long int F[2][2], unsigned long long int n)
{
	if (n == 0 || n == 1)
		return;
	unsigned long long int M[2][2] = { { 1,1 },{ 1,0 } };

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, M);
}

unsigned long long int mult(unsigned long long int a, unsigned long long int b){
  return a%1000000007 * b%1000000007;
}

void multiply(unsigned long long int F[2][2], unsigned long long int M[2][2])
{
	unsigned long long int x = mult(F[0][0] , M[0][0])%1000000007 + mult(F[0][1] , M[1][0])%1000000007;
	unsigned long long int y = mult(F[0][0] , M[0][1])%1000000007 + mult(F[0][1] , M[1][1])%1000000007;
	unsigned long long int z = mult(F[1][0] , M[0][0])%1000000007 + mult(F[1][1] , M[1][0])%1000000007;
	unsigned long long int w = mult(F[1][0] , M[0][1])%1000000007 + mult(F[1][1] , M[1][1])%1000000007;
	x %= 1000000007;
	y %= 1000000007;
	z %= 1000000007;
	w %= 1000000007;
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

/* Driver program to test above function */
int main()
{
	//long long int n;
	//cin >> n;
	/*for (long long int i = 0; i < 10000000000000000000; i++)
		if (i == 45) {
			cout << "first fibonacci number greater than 10^9 + 7: " << fib(i) % 1000000007 << endl;
		}else
			cout << i << ": " << fib(i) % 1000000007 << endl; */
unsigned long long int n;
	cin >> n;
	cout << fib(n) % 1000000007;
	cin.get();
	cin.get();
	cin.get();
	return 0;
}