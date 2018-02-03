#include <iostream>
using namespace std;

struct node{
	node *prev;
	int data;
	node *next;
};

struct head{
	node *first;
	node *last;
};

class dll{
public:
	dll();
	void insertFront(int val);
	void insertBack(int val);
	void insertAfter(int val, node *ptr);
	void insertBefore(int val, node *ptr);
	void deleteFront();
	void deleteBack();
	void deleteThis(node *ptr);
	void print();
	void reversePrint();
	node *Find(int val);
private:
	head header;
};

dll::dll(){
	header.first = NULL;
	header.last = NULL;
}

void dll::insertFront(int val){
	node *tmp;
	tmp = new node;
	tmp->prev = NULL;
	tmp->data = val;
	tmp->next = header.first;
	if(header.first != NULL){
		header.first->prev = tmp;
	}
	header.first = tmp;
	if(header.last == NULL){
		header.last = tmp;
	}
}

void dll::insertBack(int val){
	node *tmp;
	tmp = new node;
	tmp->prev = header.last;
	tmp->data = val;
	tmp->next = NULL;
	if(header.last != NULL){
		header.last->next = tmp;
	}
	header.last = tmp;
	if(header.first == NULL){
		header.first = tmp;
	}
}

void dll::deleteFront(){
	node *tmp;
	if(header.first == header.last){
		free(header.first);
		header.first = NULL;
		header.last = NULL;
	}
	else{
		tmp = header.first;
		header.first = tmp->next;
		header.first->prev = NULL;
		free(tmp);
	}
}

void dll::deleteBack()
{
	node *tmp;
	if(header.first == header.last)
	{
		free(header.last);
		header.first = NULL;
		header.last = NULL;
	}
	else
	{
		tmp = header.last;
		header.last = tmp->prev;
		header.last->next = NULL;
		free(tmp);
	}
}

void dll::insertAfter(int val, node *ptr)
{
	if(ptr == header.last)
	{
		insertBack(val);
	}
	else
	{
		node *tmp;
		tmp = new node;
		tmp->prev = ptr;
		tmp->data = val;
		tmp->next = ptr->next;
		ptr->next = tmp;
		tmp->next->prev = tmp;
	}
}

void dll::insertBefore(int val, node *ptr)
{
	if(ptr == header.first)
	{
		insertFront(val);
	}
	else
{
		node *tmp;
		tmp = new node;
		tmp->prev = ptr->prev;
		tmp->next = ptr;
		tmp->prev->next = tmp;
		ptr->prev = tmp;
		tmp->data = val;
	}
}

node *dll::Find(int val)
{
	node *move;
	move = header.first;
	while(move != NULL){
		if(move->data == val)
		{
			return move;
		}
		move = move->next;
	}
	return NULL;
}

void dll::deleteThis(node *ptr)
{
	if(ptr == header.first)
	{
		deleteFront();
	}
	else if(ptr == header.last)
	{
		deleteBack();
	}
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
	}
}

void dll::print()
{
	node *move;
	move = header.first;
	while(move != NULL)
	{
		cout << move->data << " ";
		move = move->next;
	}
}
void dll::reversePrint(){
	node *move;
	move = header.last;

	while(move != NULL)
	{
		cout << move->data << " ";
		move = move->prev;
	}
	cout << endl;
}

int main()
{
	dll list;
	int k, x;
        srand(2);

        for ( k = 0; k < 20; ++k )
        {
                x = rand() % 1337 + 1;
                printf("%4d  ", x);
                if ( k % 2 == 0 )
					{
                        list.insertBack(x);
					}
                else
					{
                        list.insertFront(x);
					}
                if ( x % 7 == 0 )
					{
                        list.deleteBack();
					}
                if ( x % 11 == 0 )
					{
                        list.deleteFront();
					}
                printf("\n");
        }
		cout << "Print Forward list: ";
		list.print();
		cout << endl;
		cout << "Print Reverse list: ";
		list.reversePrint();

        return 0;
}
