#include<iostream>
using namespace std;
struct dnode
{
	char digit;
	int freq;
};
union u
{
	dnode *d;
	hnode *h;
};
struct hnode
{
	lchild u;
	rchild u;
	int tferq;
};
typedef hnode *hptr;

