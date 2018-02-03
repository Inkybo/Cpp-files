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
void search(int x);
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
void bstree::search(int x)
{
findval(x, root);
}
void bstree::post(treenode * t)
{ //first in-class part.
if (t == NULL)
return;
post(t->lchild);
post(t->rchild);
printf("%2d ", t->dat);
}
void bstree::paren(treenode * t)
{
if (t == NULL)
return;
printf("(%2d) ", t->dat);
paren(t->lchild);
paren(t->rchild);
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
post(root);
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
insert(root,t1);
}
void bstree::insert( treenode *t, treenode *n )
{
if(t == NULL)
{
root = n;
return;
}
if(n->dat < t ->dat)
{
if(t->lchild == NULL)
t->lchild = n;
else
insert(t->lchild,n);
}
else if(n->dat > t->dat)
{
if(t->rchild == NULL)
t->rchild = n;
else
insert(t->rchild,n);
}
}
treenode *bstree::findval( int x, treenode *t)
{
while(t!=NULL)
{
if(x == t->dat)
{
printf("Found value %d\n",x);
return t;
}
else
{
if(x < t->dat)
t = t->lchild;
else
t = t->rchild;
}
}
return NULL;
}
void bstree::remove( int x )
{
treenode *t;
treenode *rem, *parent;
int p = 0;
rem = findval( x, root ); //assigns the memory address of findval(x,root) into

if(rem == NULL)
{
return;
}
parent = root;
while(parent->lchild != rem && parent->rchild != rem)
{
if(parent->dat == x)
{
break;
}
else if(x < parent->dat)
{
parent = parent->lchild;
}
else
{
parent = parent->rchild;
}
}
if(rem->lchild == NULL && rem->rchild == NULL)
{
if(parent->lchild == rem){
delete(rem);
parent->lchild = NULL;
}
else if(parent->rchild == rem)
{
delete(rem);
parent->rchild = NULL;
}
}
else if(rem->lchild == NULL || rem->rchild == NULL)
{
if(rem == root)
{
if(rem->lchild == NULL)
{
root = rem->rchild;
}
else
{
root = rem->rchild;
}
}
else if(parent->lchild == rem)
{
if(rem->lchild != NULL)
{
parent->lchild = rem->lchild;
}
else
{
parent->lchild = rem->rchild;
}
}
else if(parent->rchild == rem)
{
if(rem->lchild != NULL)
{
parent->rchild = rem->lchild;
}
else
{
parent->rchild = rem->rchild;
}
}
}
else
{
t=rem->lchild;
while(t->rchild != NULL)
{
t = t->rchild;
}
p = t->dat;
remove(t->dat);
rem->dat = p;
}
}
int bstree::_numnodes(treenode * t)
{
int count = 1;
if (t->lchild != NULL)
{
count+=_numnodes(t->lchild);
}
if (t->rchild != NULL)
{
count+=_numnodes(t->rchild);
}
return count;
}
int bstree::numnodes()
{
int ans;
ans = _numnodes(root);
return ans;
}
int bstree::_height(treenode * t)
{
int res = 0;
int L = 0, r = 0;
if( t == NULL )
return 0;
L = _height( t -> lchild );
r = _height( t-> rchild );
if( L >= r )
res = L + 1;
else
res = r + 1;
return res;
}
int bstree::height()
{
int ans;
ans = _height(root);
return ans;
}
int main(int argc, char *argv[])
{
bstree * t;
int i, x, cmd;
ifstream ifp;
if (argc != 2)
{
cout << "ERROR: no BST CMD file " << endl;
return 2;
}
ifp.open( argv[1] ); //this opens the file for editing, using the C++ fstream
if ( ! ifp.is_open() )
{
 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
 return 3;
}
t = new bstree();
ifp >> cmd;
cin >> cmd;
printf("Read in command %d\n",cmd);
while (cmd != 0)
{
if(cmd == 1)
{
ifp >> x;
t->insert(x);
}
if(cmd == -1)
{
ifp >> x;
t->remove(x);
}
if(cmd == 3)
{
t->pre();
printf("\n");
}
if(cmd == 4)
{
t->in();
printf("\n");
}
if(cmd == 5)
{
t->post();
printf("\n");
}
if(cmd == 6)
{
t->paren();
printf("\n");
}
if(cmd == 7)
{
ifp >> x;
t->search(x);
}
ifp >> cmd;
}
return 0;
}
