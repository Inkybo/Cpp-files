#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
//const int set = 2048;
void insert(int heap[],int x,int loc)
{
        int tmp;
        heap[loc] = x;
        if(loc == 1)
                return;
        while(loc != 1)
        {
                if(heap[loc] > heap[loc/2])
                {
                        tmp = heap[loc];
                        heap[loc] = heap[loc/2];
                        heap[loc/2] = tmp;
                }
                loc = loc/2;
        }
}
void sortHeap(int heap[], int len, int loc)
{
        int tmp;
        if(loc>=len)
                return;
        else
        {
                if(loc*2 < len && loc*2+1 <=len)
                {
                        if(heap[loc*2] > heap[loc*2+1])
                        {
                                if(heap[loc] < heap[loc*2])
                                {
                                        tmp = heap[loc];
                                        heap[loc] = heap[loc*2];
                                        heap[loc*2] = tmp;
                                        sortHeap(heap,len,loc*2);
                                }
                        }
                        else
                        {
                                if(heap[loc] < heap[loc*2+1])
                                {
                                        tmp = heap[loc];
                                        heap[loc] = heap[loc*2+1];
                                        heap[loc*2+1] = tmp;
                                        sortHeap(heap,len,loc*2);
                                }
                        }
                }
                else if(loc*2 < len)
                {
                        if(heap[loc] < heap[loc*2])
                        {
                                tmp = heap[loc];
                                heap[loc] = heap[loc*2];
                                heap[loc*2] = tmp;
                                sortHeap(heap,len,loc*2);
                        }
                }
                else
                        return;
        }
}
void deleteTop(int heap[],int len,int loc)
{
        heap[1] = heap[len-1];
        sortHeap(heap,len, 1);
}
void printHeap(int heap[], int len)
{
        for(int x = 1; x < len; x++)
        {
                cout << heap[x] << " ";
        }
}
int main(int argc, char *argv[]) {
        int i, x, cmd,len=1;
        int heap[1000000];
        ifstream ifp;
        if (argc != 2)
        {
                cout << "ERROR: no Heap CMD file " << endl;
        return 2;
        }
        ifp.open( argv[1] );
        if ( ! ifp.is_open() )
        {
                cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
                return 3;
        }
        while(ifp >> x)
        {
                switch(x)
                {
                        case 0:
                                printf("Quitting\n");
                                return 0;
                                break;
                        case 1:
                                ifp >> x;
                                insert(heap,x,len);
                                len++;
                                break;
                        case -1:
                                deleteTop(heap,len,1);
                                len--;
                                if(len < 1)
                                        len = 1;
                                break;
                        case 3:
                                if(len > 1)
                                        printHeap(heap,len);
                                else
                                        cout <<"No Values in Heap";
                                printf("\n");
                                break;
                }
        }
        return 0;
}
