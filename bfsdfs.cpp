#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
struct branch{
    int from;
    int to;
};
/**************************Start of Breadth functions**************************/
void breadth_first_search(int edge[][100], int num)
{
    int mark_as[num+1] = {0};
    queue<int> declared_queue;
    int starting_node, c;
    cout << "starting node for breadth search: ";
    cin >> starting_node;
    cout << "Breadth First Search: ";
    if(starting_node > num)
    {
        cout << "Cannot start at node " << starting_node << endl;
        return;
    }
    declared_queue.push(starting_node);
    while(!declared_queue.empty())
    {
        c = declared_queue.front();
        declared_queue.pop();
        if(!mark_as[c])
        {
            for(int i = 1; i <= num; i++)
            {
                if(edge[c][i] && !mark_as[i])
                {
                    declared_queue.push(i);
                }
            }
            cout << c << "  ";
            mark_as[c] = 1;
        }
    }
    cout << endl << endl;
}
void breadth_spanning_tree(int edge[100][100], int num)
{
    int mark_as[num+1] = {0};
    queue<branch> declared_queue;
    int starting_node;
    branch c, tmp;
    cout << "start node for breadth spanning tree: ";
    cin >> starting_node;
    cout << "Breadth Spanning Tree: ";
    if(starting_node > num)
    {
        cout << "Cannot start at node " << starting_node << endl;
        return;
    }
    branch first;
    first.from = starting_node;
    first.to = starting_node;
    declared_queue.push(first);
    while(!declared_queue.empty())
    {
        c = declared_queue.front();
        declared_queue.pop();
        if(!mark_as[c.to])
        {
            for(int i = 1; i <= num; i++)
            {
                if(edge[c.to][i] && !mark_as[i])
                {
                    tmp.to = i;
                    tmp.from = c.to;
                    declared_queue.push(tmp);
                }
            }
            cout << c.from << "-" << c.to << "  ";
            mark_as[c.to] = 1;
        }
    }
    cout << endl << endl;
}
/***************************Start of Depth functions***************************/
void depth_first_search(int edge[][100], int num)
{
    int mark_as[num+1] = {0};
    stack<int> declared_stack;
    int starting_node, c;
    cout << "starting node for depth search: ";
    cin >> starting_node;
    cout << "Depth First Search: ";
    if(starting_node > num)
    {
        cout << "Cannot start at node " << starting_node << endl;
        return;
    }
    declared_stack.push(starting_node);
    while(!declared_stack.empty())
    {
        c = declared_stack.top();
        declared_stack.pop();
        if(!mark_as[c])
        {
            for(int i = num; i >= 1; i--)
            {
                if(edge[c][i] && !mark_as[i])
                {
                    declared_stack.push(i);
                }
            }
            cout << c << "  ";
            mark_as[c] = 1;
        }
    }
    cout << endl << endl;
}
void depth_spanning_tree(int edge[100][100], int num)
{
    int mark_as[num+1] = {0};
    stack<branch> declared_stack;
    int starting_node;
    branch c, tmp;
    
    cout << "starting node for depth spanning tree: ";
    cin >> starting_node;
    cout << "Depth Spanning Tree: ";
    if(starting_node > num)
    {
        cout << "Cannot start at node " << starting_node << endl;
        return;
    }
    branch first;
    first.from = starting_node;
    first.to = starting_node;
    declared_stack.push(first);
    while(!declared_stack.empty())
    {
        c = declared_stack.top();
        declared_stack.pop();
        if(!mark_as[c.to])
        {
            for(int i = num; i >= 1; i--)
            {
                if(edge[c.to][i] && !mark_as[i])
                {
                    tmp.to = i;
                    tmp.from = c.to;
                    declared_stack.push(tmp);
                }
            }
            cout << c.from << "-" << c.to << "  ";
            mark_as[c.to] = 1;
        }
    }
    cout << endl << endl;
}
/***************************Start of Table function***************************/
void table(int edge[][100], int node)
{
    for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <= node; j++)
        {
            cout << edge[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    ifstream fp;
    int node, e;
    int num_1, num_2, w;
    int edge[100][100];
    if(argc == 1)
    {
        cout << "Missing command line input file" << endl;
        return 1;
    }
    else if(argc > 2)
    {
        cout << "Incorrect number of arguments" << endl;
        return 1;
    }
    fp.open(argv[1]);
    if(! fp.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }
    fp >> node >> e;
    for(int i = 0; i < e; i++)
    {
        fp >> num_1 >> num_2 >> w;
        edge[num_1][num_2] = w;
        edge[num_2][num_1] = w;
    }
    table(edge, node);
    depth_first_search(edge, node);
    breadth_first_search(edge, node);
    depth_spanning_tree(edge, node);
    breadth_spanning_tree(edge, node);
    fp.close();
    return 0;
}
