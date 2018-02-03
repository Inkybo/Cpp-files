#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define DBP 0

struct treenode
{
 int dat;
 treenode *lchild;
 treenode *rchild;
};

class bstree
{
 public:
  bstree();
  void in( );
  void pre( );
  void post( );
  void paren( );
  void insert( int x );
  void remove( int x );
  int numnodes();
  int height();
 private:
  treenode *root;
  void in( treenode *t );
  void pre( treenode *t );
  void post( treenode *t );
  void paren( treenode *t );
  void insert( treenode *t, treenode *n );
  treenode *findval( int x, treenode *t);
  int _numnodes(treenode *t);
  int _height(treenode *t);
};
/*
bstree::bstree()
{
  root = NULL;
}

void bstree::in(treenode * t)
{
 if ( t == NULL )
   return;

 in(t->lchild);
 printf("%2d ", t->dat);
 in(t->rchild);
}

void bstree::pre(treenode * t)
{
 if ( t == NULL )
   return;

 printf("%2d ", t->dat);
 pre(t->lchild);
 pre(t->rchild);
}

void bstree::post(treenode * t)
{
 // IN CLASS
}

void bstree::paren(treenode * t)
{
}

void bstree::in()
{
 in(root);
}

void bstree::pre()
{
 pre(root);
}

void bstree::post()
{
 // IN CLASS
}

void bstree::paren()
{
 paren(root);
}



void bstree::insert( int x )
{
 treenode *t1;

 t1 = new treenode();
 t1->dat = x;
 t1->lchild = NULL;
 t1->rchild = NULL;

 // INCLASS
}

void bstree::insert( treenode *t, treenode *n )
{
 // INCLASS
}

treenode *bstree::findval( int x, treenode *t)
{
 // INCLASS
}


void bstree::remove( int x )
{
 treenode *t;
 treenode *rem, *parent;

 rem = findval( x, root );

 // do the work
}


int bstree::_numnodes(treenode * t)
{
 // IN CLASS
}

int bstree::numnodes()
{
 int ans;
 ans = _numnodes(root);
 return ans;
}

int bstree::_height(treenode * t)
{
 // IN CLASS
}

int bstree::height()
{
 int ans;
 ans = _height(root);
 return ans;
}
*/


int main(int argc, char *argv[])
{
 bstree * t;
 int i, x, cmd;
 ifstream ifp;

 if (argc != 2)
 {
 	cout << "ERROR:  no BST CMD file " << endl;
    return 2;
 }

 ifp.open( argv[1] );

 if ( ! ifp.is_open() )
 {
   cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
   return 3;
 }

 t = new bstree();

 // read the command file

 while (ifp >> cmd >> x)
 {
    if(cmd == 0)
	{
		ifp.close();
	}
	if(cmd == 1)
	{
		//insert fucntion call
	}
	if(cmd == -1)
	{
		//remove function call
	}
	if(cmd == 3)
	{
		//preorder function call
	}
	if(cmd == 4)
	{
		//inorder function call
	}
	if(cmd == 5)
	{
		//postorder function call
	}
	if(cmd == 6)
	{
		//paren function call
	}
	if(cmd == 7)
	{
		//sarch function call
	}
 }

 return 0;
}
