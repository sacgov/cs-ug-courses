#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
const int d1=1;
struct bdtree
{
	bdtree *parent;
	int key[2*d1+1];
	int off[2*d1+1];
	bdtree *child[2*d1+2];
	int count;
};
bdtree *root;
int offset=0;
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size=150;
    bdtree* e[500];
	int isqfull()
	{
		if((rear+1)%size==front)
		return(1);
		else
		return(0);
	}
	int isqempty()
	{
		if(front==-1)
		return(1);
		else
		return(0);
	}
	void enqueue(bdtree *k)
	{
		if(isqfull())
		cout<<"queue is full ";
		else
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			e[rear]=k;
		}
	}
	bdtree* dequeue()
	{
		bdtree* t;
		if(isqempty())
		{
			cout<<"queue is empty ";
			return NULL;
		}
		else
		{
			if(front==rear)
			{
				t=e[front];
				front=-1;
				rear=-1;
			}
			else
			{
				t=e[front];
				front=(front+1)%size;
			}
			return(t);
		}
	}
	int ndq()
	{
		if(rear>=front)
		{
			return(rear-front+1);
		}
		else
		return(size-front+rear+1);
	}
};
bdtree* newnode()
{
	bdtree *l;
	l=new bdtree;
	for(int i=0;i<2*d1+1;i++)
	{
		l->child[i]=NULL;
		l->key[i]=-1;
		l->off[i]=0;
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
     n->off[i]=m->off[d1+1+i];
     n->child[i+1]=m->child[d1+2+i];
     p->key[i]=m->key[i];   
     p->off[i]=m->off[i];
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
     if(m->parent==NULL)
     {
     	bdtree *b1=newnode();
     	b1->key[0]=m->key[d1];
     	b1->off[0]=m->off[d1];
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
		m->parent->off[j]=m->parent->off[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
	    m->parent->child[a1]=p;
		m->parent->key[a1]=m->key[d1];
		m->parent->off[a1]=m->off[d1];
		(m->parent->count)++;
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
     n->off[i+1]=m->off[d1+1+i];
     p->key[i]=m->key[i];
     p->off[i]=m->off[i];
     p->child[i]=m->child[i];
     }
     n->key[0]=m->key[d1];
     n->off[0]=m->off[d1];
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
     if(m->parent==NULL)
     {
     	bdtree *b1=newnode();
     	b1->key[0]=m->key[d1];
     	b1->off[0]=m->off[d1];
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
		m->parent->off[j]=m->parent->off[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
	    m->parent->child[a1]=p;
		m->parent->key[a1]=m->key[d1];
		m->parent->off[a1]=m->off[d1];	
		(m->parent->count)++;
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
bdtree* gleaf(bdtree *t,int c)
{
	int r=0;
	if(t==NULL)
		return NULL;
	else
	{
		if(c>=t->key[t->count-1])
		return gleaf(t->child[t->count],c);
	    for(int i=0;i<t->count;i++)
	    {
	    	if(c<t->key[i])
	    	break;
	    	r++;
	    	if(c==t->key[i])
	    		if(isleaf(t))
	    		return t;
	    }
	    return gleaf(t->child[r],c);

	}
}
int getoffset(bdtree *root,int n)
{
	bdtree*t=gleaf(root,n);
	if(t==NULL)
		return -1;
	for(int i=0;i<t->count;i++)
	{
		if(t->key[i]==n)
			return t->off[i];
	}
	return 0;
}
void create(bdtree *&t,int c)
{
	static int k=0;
	bdtree *l,*m,*n;
	if(k==0)
	{
		t=newnode();
		t->key[0]=c;
		t->off[0]=offset++;
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
		{
			m->key[j]=m->key[j-1];
			m->off[j]=m->off[j-1];
		}
		m->key[k1]=c;
		m->off[k1]=offset++;
		m->count++;
		if(m->count>2*d1)
		nodesplit(m);
	}
}
void printorder(bdtree*t)
{
	bdtree*n=NULL;
	queue q;
	q.enqueue(n);
	while(t!=NULL)
	{
    for(int i=0;i<t->count;i++)
    cout<<t->key[i]<<","<<t->off[i]<<" ";
    for(int i=0;i<=t->count;i++)
    if(t->child[i]!=NULL)
    q.enqueue(t->child[i]);
    cout<<"   ";
	bdtree*k=q.dequeue();
	if(k==NULL)
	{
	q.enqueue(n);
	cout<<endl;
	k=q.dequeue();
	if(k==NULL)
	break;
	else
	t=k;
    }
    else
    t=k;
    }
}
void printforder(ofstream &out,bdtree*t)
{
	bdtree*n=NULL;
	queue q;
	q.enqueue(n);
	int u=0;
	int u1=-1;
	while(t!=NULL)
	{
    for(int i=0;i<2*d1;i++)
    {
    	if(t->child[i]!=NULL)
    	{
    		u++;
    		out<<u<<"|";
    	}
    	else
    	{
    		out<<u1<<"|";
    	}
    	if(i<t->count)
    	{
    		out<<t->key[i]<<"|"<<t->off[i]<<"|";
    	}
    	else
    	{
    		out<<u1<<"|"<<u1<<"|";
    	}
    }
    if(t->child[2*d1]!=NULL)
    	{
    		u++;
    		out<<u<<"|";
    	}
    	else
    	{
    		out<<u1<<"|";
    	}
    out<<"#"<<endl;
    for(int i=0;i<=t->count;i++)
    if(t->child[i]!=NULL)
    q.enqueue(t->child[i]);
    cout<<"   ";
	bdtree*k=q.dequeue();
	if(k==NULL)
	{
	q.enqueue(n);
	cout<<endl;
	k=q.dequeue();
	if(k==NULL)
	break;
	else
	t=k;
    }
    else
    t=k;
    }
}
void wdata(ifstream &in,int n,bdtree *root)
{
	string s;
	getline(in,s);
	int oset=getoffset(root,n);
	cout<<endl<<"oset :"<<oset<<endl;
	if(oset<0)
		cout<<"data not found "<<endl;
	else
	{
	oset=oset*9;
	for(int i=0;i<8;i++)
		cout<<s[oset++];
	}
	cout<<endl;
}
int main()
{
	bdtree *l=NULL;
	int a=-11;
	int y=0;
	ofstream out;
	out.open("input.txt");
//	cout<<"enter the starting no "<<endl;;
//	cin>>a;
    int q[40]={10,11,22,33,44,55,66,88,77,99,91,90,89,88,87,86,85,84,1,2,3,4,5,6,7,8,9,101};
    string q1[40]={"abc","bcd","cde","def","efg","fgh","ghi","hij","ijk","jkl","klm","lmn"};
	while(a!=99)
	{
//		cout<<"enter the next no "<<endl;
//		cin>>a;
		a=q[y];
		if(a==-1)
		break;
	    string s;
	    s=q1[y++];
//	    cout<<"enter a three letter word";
//	    getline(cin,s);
	    out<<a<<" "<<s<<"#";
		create(l,a);
		l=root;
		printorder(root);
	//	a++;
	}
out.close();
out.open("btreef.txt");
printforder(out,root);
out.close();
cout<<endl;
printorder(root);
cout<<endl;
ifstream in;
int n=0;
while(n!=-1)
{
	cout<<"enter roll number :";
	cin>>n;
	in.open("input.txt");
    wdata(in,n,root);
    in.close();
}
return 0;
}
