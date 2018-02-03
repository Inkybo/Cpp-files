#include <iostream>
using namespace std;

int main()
{
	string x = "";
	string y = "";

	cout << "Hi" << endl << "This is fun" << endl;

	cout << "Enter value: ";
	cin >> x;
	cin >> y;

	cout << "Your value is " << x << " and " << y << endl;

	if(x == y)
	{
		cout << "words match" << endl;
	}
	else
	{
		cout << "words are different" << endl;
	}

	for(int i = 0; i < 10; ++i)
	{
		cout << i << endl;
	}

	return 0;
}
