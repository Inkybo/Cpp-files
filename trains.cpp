#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream trains;
ifstream stations;

struct station{
	int stationNum;
	string stationName;
};

struct train{
	int from;
	int to;
	int startTime;
	int endTime;
	int cost;
};

class Train{
	public:
	Train();
	bool isConnected();
	void shortestTime(int from, int to);

	private:
	struct station stationarray[100];
	struct train trainarray[100][100];
};

Train::Train()
{
	int tmp = 0;
	int x,y = 0;
	int junk = 0;

	for(int i=0; i<100; i++)
	{
		stationarray[i].stationNum = -1;
	}

	while(stations >> tmp)
	{
		stationarray[tmp].stationNum = tmp;
		stations >> stationarray[tmp].stationName;
	}

	for(int i=0; i<100; i++)
	{
		for(int k=0; k<100; k++)
		{
			trainarray[i][k].startTime = -1;
		}
	}
	while(trains >> x)
	{
		trains >> y;
		trainarray[x][y].from = x;
		trainarray[x][y].to = y;
		trains >> trainarray[x][y].startTime;
		trains >> trainarray[x][y].endTime;
		trains >> junk;
		trainarray[x][y].cost = (trainarray[x][y].endTime - trainarray[x][y].startTime);
	}
}

bool Train::isConnected()
{
	int from,to = 0;

	cout << "What station do you want to start from: ";
	cin >> from;
	cout << "What station do you want to go to: ";
	cin >> to;

	if(trainarray[from][to].startTime != -1)
	{
		cout << "There is a direct connection between " << stationarray[from].stationName << " and " << stationarray[to].stationName << endl;
		shortestTime(from,to);
		return true;
	}

  	int marked[101] = {0};
  	stack<int>stk;

	int start, b = 0;

	start = from;

	stk.push(start);

	while (!stk.empty())
	{
		b = stk.top();
		stk.pop();

		if(!marked[b])
		{
			for (int k = 100; k >= 0; k--)
			{
				if (trainarray[b][k].startTime != -1 && !marked[k])
				{
					stk.push(k);
				}
			}
			marked[b] = 1;
		}
	}
	if(marked[to])
	{
		cout << "There is a non-direct connection between " << stationarray[from].stationName << " and " << stationarray[to].stationName << endl;
		shortestTime(from,to);
		return true;
	}

	cout << "There is no connection between " << stationarray[from].stationName << " and " << stationarray[to].stationName << endl;
	return false;
}

void Train::shortestTime(int from, int to)
{
	int start;
	int tmp;
	int source;

	start = from;

	int marked[100];
	int length[100];

	for(int i=0; i < 100; i++)
	{
		length[i] = 1001;
		marked[i] = 0;
	}
	length[start] = 0;

	for(;;)
	{
		int min = 1000;
		int	minIndex = 0;

		for(int k=0; k<100; k++)
		{
			if(marked[k] == 0 && length[k] < min)
			{
				min = length[k];
				minIndex = k;
			}
		}
		if(min == 1000)
		{
			break;
		}
		start = minIndex;
		marked[start] = 1;

		for(int j=0; j < 100; j++)
		{
			if(trainarray[start][j].startTime != -1)
			{
				tmp = length[start] + trainarray[start][j].cost;

				if(tmp < length[j])
				{
					length[j] = tmp;
				}
			}
		}
	}
	if(marked[to])
	{
		cout << stationarray[from].stationName << " - " << stationarray[to].stationName <<  " " << length[to] <<  endl;
		cout << endl;
	}
	else
	{
		cout << stationarray[from].stationName << " - " << stationarray[to].stationName <<  " " << " No path " <<  endl;
		cout << endl;
	}
}

int main(int argc,char *argv[])
{
	stations.open(argv[1]);
	trains.open(argv[2]);
	Train list;
	list.isConnected();

	return 0;
}
