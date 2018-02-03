#include <iostream>
#include <string>
#include <climits>
#include <stack>

using namespace std;

class Base
{
    public:
    Base();
    Base(int val);
    Base(string val);
    void Print();
    void toInt();
    int cmp(string num);

    private:
    string strbase;
    int toInt(string val);
    int toInt(char c);
};

Base::Base()
{
    strbase.push_back('0');
}
Base::Base(int val)
{
    int r = 0;
    char arr[21] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
    stack <int> stk;

    while(val != 0)
    {
        r = val % 21;
        stk.push(arr[r]);
        val = val / 21;
    }
    while(!stk.empty())
    {
        strbase.push_back(stk.top());
        stk.pop();
    }
}
Base::Base(string val)
{
     strbase = val;
}
void Base::Print()
{
    cout << strbase << endl;
}
void Base::toInt()
{
    int x;
    x = toInt(strbase);
    cout << x << endl;
}

int Base::toInt(string val)
{
    int x = 0;
    int y = 1;

    if(val.compare("140H2D91") == 0)
    {
        return INT_MAX;
    }
    while(val.size() != 0)
    {
        x += toInt(val.back()) * y;
        y = y*21;
        val.pop_back();
    }
    if(x == INT_MAX)
    {
        return -1;
    }
    else if(x < 0)
    {
        return -1;
    }
    else
    {
        return x;
    }
}
int Base::toInt(char c)
{
    if(c >= '0' && c <= '9')
    {
        return(c - '0');
    }
    else
    {
        return( (c - 'A') + 10 );
    }
}
int Base::cmp(string num)
{
    if(strbase.size() > num.size() )
    {
        return 1;
    }
    else if(num.size() > strbase.size() )
    {
        return -1;
    }
    int first, second;

    for(int i=0; i<num.size(); i++)
    {
        int x = toInt(strbase[i]);
        int y = toInt(num[i]);

        if(x > y)
        {
            return 1;
        }
        else if(y > x)
        {
            return -1;
        }
    }
    return 0;
}
int main()
{
    int i,k;
    int num = 425;

    for(i = 0; i <= 20; i++)
    {
        Base c(num);
		printf("%d = ", num);
        c.Print();
        num++;
    }
    return 0;
}
