#include <iostream>
using namespace std;

int ones(int x)
{
	int b = 0;
	int n = 0;
	int p = 0;

	if(x == 0) return 0;
	if(x == 1) return 1;

	b = x % 2;
	n = x / 2;

	x = ones(n);
	return x + b;
}
int main( int argc, char *argv[])
{
	int n = 0;
	int a = 0;

	n = atoi(argv[1]);
	a = ones(n);
	cout << a << " 1s in binary of " << n << endl;
	return 0;
}
