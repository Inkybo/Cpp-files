#include <iostream>
using namespace std;

int fcount = 0;

int fib(int x)
{
	int b = 0;
	int c = 0;
	fcount++;
	if(x == 1)
	{
		return 1;
	}
	else if(x == 2)
	{
		return 1;
	}
	else
	{
		b = fib(x-1);
		c = fib(x-2);
		return b + c;
	}
}
int main()
{
	int n = 0;
	int f = 0;
	cin >> n;
	f = fib(n);
	cout << f << " " << fcount << endl;
	cout <<  endl;
}
