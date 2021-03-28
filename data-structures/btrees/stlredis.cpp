#include <iostream>
#include<queue>
using namespace std;
const int d1=2;
struct bdtree
{
	bdtree *parent;
	int key[2*d1+1];
	bdtree *child[2*d1+2];
	int count;
};
bdtree *root;

bdtree* newnode()
{
	bdtree *l;
	l=new bdtree;
	for(int i=0;i<2*d1+1;i++)
	{
		l->child[i]=NULL;
		l->key[i]=-1;
	}
	l->child[2*d1+1]=NULL;
	l->parent=NULL;
	l->count=0;
	return l;
}
int z=0;
void nodesplit(bdtree *&m)
{
	if(z==1)
	{
	 bdtree *p,*n;
	 p=newnode();
     n=newnode();
     for(int i=0;i<d1;i++)
     {
     n->key[i]=m->key[d1+1+i];
     n->child[i+1]=m->child[d1+2+i];
     p->key[i]=m->key[i];
     p->child[i]=m->child[i];
     }
     p->child[d1]=m->child[d1];
     n->child[0]=m->child[d1+1];
     n->count=d1;
     p->count=d1;
     for(int i=0;i<d1+1;i++)
     {
     	if(n->child[i]!=NULL)
	    n->child[i]->parent=n;
	    if(p->child[i]!=NULL)
	    p->child[i]->parent=p;
	    
     }
   // m->count=d1;
   // for(int i=0;i<d1+1;i++)
   // m->child[d1+1+i]=NULL;
     if(m->parent==NULL)
     {
     	bdtree *b1=newnode();
     	b1->key[0]=m->key[d1];
     	b1->child[0]=p;
     	b1->child[1]=n;
     	n->parent=b1;
     	p->parent=b1;
     	b1->count=1;
     	root=b1;
     }
     else
     {
        n->parent=m->parent;
        p->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	if(m->parent->key[i]>m->key[d1])
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
	    m->parent->child[a1]=p;
		m->parent->key[a1]=m->key[d1];
		(m->parent->count)++;
	//	m->count=d1;
	//	n->count=d1;
		if(m->parent->count>2*d1)
		nodesplit(m->parent);
     }
 }
 else
 {
 	bdtree *p,*n;
	 p=newnode();
     n=newnode();
     for(int i=0;i<d1;i++)
     {
     n->key[i+1]=m->key[d1+1+i];
     n->child[i+1]=m->child[d1+2+i];
     p->key[i]=m->key[i];
     p->child[i]=m->child[i];
     }
     n->key[0]=m->key[d1];
     p->child[d1]=m->child[d1];
     n->child[0]=m->child[d1+1];
     n->count=d1+1;
     p->count=d1;
     for(int i=0;i<d1+1;i++)
     {
     	if(n->child[i]!=NULL)
	    n->child[i]->parent=n;
	    if(p->child[i]!=NULL)
	    p->child[i]->parent=p;
	    
     }
   // m->count=d1;
   // for(int i=0;i<d1+1;i++)
   // m->child[d1+1+i]=NULL;
     if(m->parent==NULL)
     {
     	bdtree *b1=newnode();
     	b1->key[0]=m->key[d1];
     	b1->child[0]=p;
     	b1->child[1]=n;
     	n->parent=b1;
     	p->parent=b1;
     	b1->count=1;
     	root=b1;
     }
     else
     {
     	z=1;
        n->parent=m->parent;
        p->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	if(m->parent->key[i]>m->key[d1])
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
	    m->parent->child[a1]=p;
		m->parent->key[a1]=m->key[d1];
		(m->parent->count)++;
	//	m->count=d1;
	//	n->count=d1;
	    z=1;
		if(m->parent->count>2*d1)
		nodesplit(m->parent);
 }
}
}
bool isleaf(bdtree *t)
{
	int flag=0;
	for(int i=0;i<t->count+1;i++)
	{
		if(t->child[i]!=NULL)
		flag=1;
	}
	if(flag==0)
	return true;
	else
	return false;
}
bdtree* leaf(bdtree *t,int c)
{
	int r=0;
	if(isleaf(t))
	return (t);
	else
	{
		if(c>t->key[t->count-1])
		return leaf(t->child[t->count],c);
	    for(int i=0;i<t->count;i++)
	    {
	    	if(c<t->key[i])
	    	break;
	    	r++;
	    }
	    return leaf(t->child[r],c);
   }
}
bool left(bdtree*&m,int a1)
{
	bdtree*mp=m->parent;
	if(a1==0)
	return false;
	a1--;
	if(mp->child[a1]==NULL)
	return false;
	else
	{
	if(mp->child[a1]->count==2*d1)
	return false;
	else
	{
		mp->child[a1]->key[mp->child[a1]->count]=mp->key[a1];
		mp->key[a1]=m->key[1];
		mp->child[a1]->count++;
		for(int i=0;i<2*d1;i++)
		{
			m->key[i]=m->key[i+1];
			m->child[i]=m->child[i+1];
		}
		m->child[2*d1]=m->child[2*d1+1];
		m->count--;
		return true;
	}	}
}
bool right(bdtree*&m,int a1)
{
	bdtree*mp=m->parent;
	if(a1==2*d1)
	return false;
	int k=a1+1;
	if(mp->child[k]==NULL)
	return false;
	else
	{
	if(mp->child[k]->count==2*d1)
	return false;
	else
	{
		for(int i=mp->child[k]->count;i>0;i--)
		{
		mp->child[k]->key[i]=mp->child[k]->key[i-1];
		}
		mp->child[k]->key[0]=mp->child[a1]->key[mp->child[a1]->count-1];
		mp->key[a1]=m->key[m->count-1];
		mp->child[k]->count++;
		m->count--;
		return true;
	}}	
}
void key(bdtree *m)
{
	int a1=0;
	if(m->parent!=NULL)
	{
		for(int i=0;i<m->parent->count+1;i++)
	    {
	 	if(m->parent->child[i]==m)
	 	break;a1++;
	    }
	    bool flagr=false;
		bool flagl=left(m,a1);
		if(flagl)
		cout<<"lp ";
		if(!flagl)
		{
			cout<<"lnp ";
			flagr=right(m,a1);
			if(!flagr)
			cout<<"rnp ";
		}
		if(flagr)
		cout<<"rp ";cout<<root->child[1]->count<<"rp";
		if(!(flagr||flagl))
		{
			cout<<"ns ";
			nodesplit(m);
		}
	}
	else
	{
		cout<<"nsp ";
		nodesplit(m);
	}
	
}
void create(bdtree *&t,int c)
{
	static int k=0;
	bdtree *l,*m,*n;
	if(k==0)
	{
		t=newnode();
		t->key[0]=c;
		k++;
		t->count=1;root=t;
	}
	else
	{
		m=leaf(root,c);
		int k1=0;
		for(int i=0;i<m->count;i++)
		{
			if(c<m->key[i])
			break;
			k1++;
		}
		for(int j=m->count;j>k1;j--)
		m->key[j]=m->key[j-1];
		m->key[k1]=c;
		m->count++;
		if(m->count>2*d1)
		{
			cout<<"o";
			key(m);
		}
	}
}
void printorder(bdtree*t)
{
	bdtree*n=NULL;
	queue<bdtree*>q;
	cout<<endl;
	q.push(n);
	while(t!=NULL)
	{
    for(int i=0;i<t->count;i++)
    cout<<t->key[i]<<" ";
    for(int i=0;i<=t->count;i++)
    if(t->child[i]!=NULL)
    q.push(t->child[i]);
    cout<<"   ";
	bdtree*k=q.front();
	q.pop();
	if(k==NULL)
	{
	q.push(n);
	cout<<endl;
	k=q.front();
	q.pop();
	if(k==NULL)
	break;
	else
	t=k;
    }
    else
    t=k;
    }
}
int main()
{
	bdtree *l=NULL;
	int a=40,y=0;
	
//	cout<<"enter the starting no "<<endl;;
//	cin>>a;
//	int q[40]={100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,1,2,3,4,5,6,7,8,9,101};
	int q1[10]={5,9,2,4,8,1,7,3,6};
	int q2[40]={2,3,4,5,6,7,12,18,25,27,30,37,32};
	while(a!=32)
	{
		a=q2[y++];
		z=0;
		create(l,a);
		l=root;
	//	cout<<"enter the next no "<<endl;
	//   cin>>a;
		cout<<endl;
        printorder(root);
	//	a--;
	}

return 0;
}
