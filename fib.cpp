#include <iostream>
using namespace std;

int res[50] = {0};
int fcount = 0;

int fib( int x )
{
	int b,c;

	fcount++;

	if(res[x] > 0)
		return res[x];
	if ( x == 1 )
	{
		res[1] = 1;
		return 1;
	}
	else if ( x == 2 )
	{
		res[2] = 1;
		return 1;
	}
	else
	{
		b = fib(x-1);
		c = fib(x-2);
		res[x] = b+c;
		return b + c;
	}
}

int main(int argc, char *argv[])
{
	int n, f;
	n = atoi( argv[1] );
	//cin >> n;
	f = fib( n );
	cout << f << " " << fcount << endl;
	cout << endl;
	return 0;
}
