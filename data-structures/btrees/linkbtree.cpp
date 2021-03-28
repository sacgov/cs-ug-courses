#include<iostream>
using namespace std;
const int d1=2;
struct lnode
{
	int data=0;
	lnode* next=NULL;
};
void print(lnode *l,int count)
{
	int c=0;
	if(l==NULL)
	cout<<"null";
	while(l!=NULL&&c<count)
{
cout<<l->data<<" ";c++;
l=l->next;
}}
void addend(lnode *&l,int k)
{
	if(l==NULL)
	{
		l=new lnode;
		l->data=k;
		l->next=NULL;
	}
	else
	{
	lnode *temp;
	temp=l;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=new lnode;
	temp=temp->next;
	temp->data=k;
	temp->next=NULL;
	}
	
}
int get(lnode*l,int i)
{
	for(int j=0;j<i;j++)
	l=l->next;
	return(l->data);
}
void sort(lnode*l)
{
	lnode*temp;
	temp=l;
	int c=0;
	while(temp->next!=NULL)
	{
		if(temp->data>temp->next->data)
		{
			int k;
			k=temp->data;
			temp->data=temp->next->data;
			temp->next->data=k;
			c=1;
		}
		temp=temp->next;
	}
	if(c==1)
	sort(l);
}
struct bdtree
{
	bdtree *parent;
	lnode*key;
	bdtree *child[2*d1+2];
	int count;
};
bdtree *root;
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
void printorder(bdtree*t)
{
	bdtree*n=NULL;
	queue q;
	q.enqueue(n);
	while(t!=NULL)
	{
    print(t->key,t->count);
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
bdtree* newnode()
{
	bdtree *l;
	l=new bdtree;
	for(int i=0;i<2*d1+1;i++)
	l->child[i]=NULL;
	l->child[2*d1+1]=NULL;
	l->parent=NULL;
	l->count=0;
	l->key=NULL;
	return l;
}
void nodesplit(bdtree *&m)
{
	 bdtree *p,*n;
	 p=newnode();
     n=newnode();
     for(int i=0;i<d1;i++)
     {
     //n->key[i]=m->key[d1+1+i];
     addend(n->key,get(m->key,(d1+1+i)));
     n->child[i+1]=m->child[d1+2+i];
    // p->key[i]=m->key[i];
   addend(p->key,get(m->key,i));
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
     	//b1->key->data=m->key[d1];
     	addend(b1->key,get(m->key,d1));
     	b1->count=1;
     //	print(b1->key,b1->count);
     	b1->count=1;
     	b1->child[0]=p;
     	b1->child[1]=n;
     	n->parent=b1;
     	p->parent=b1;
     	root=b1;
     //	print(root->child[0]->key,root->child[0]->count);
     //	printorder(root);
     }
     else
     {
        n->parent=m->parent;
        p->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	//if(m->parent->key[i]>m->key[d1])
	 	if(get(m->parent->key,i)>get(m->key,d1))
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
	//	m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
	    m->parent->child[a1]=p;
	//	m->parent->key[a1]=m->key[d1];
	    addend(m->parent->key,get(m->key,d1));
	    sort(m->parent->key);
		(m->parent->count)++;
	//	m->count=d1;
	//	n->count=d1;
		if(m->parent->count>2*d1)
		nodesplit(m->parent);
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
		lnode*t1=t->key;
		while(t1->next!=NULL&&t1->next->data!=0)
		t1=t1->next;
		if(c>t1->data)
		return leaf(t->child[t->count],c);
		t1=t->key;	
	    while(t1->next!=NULL)
	    {
	    	if(c<t1->data)
	    	break;
	    	r++;
	    	t1=t1->next;
	    }
	    return leaf(t->child[r],c);
   }
}
void create(bdtree *&t,int c)
{
	static int k=0;
	bdtree *l,*m,*n;
	if(k==0)
	{
		t=newnode();
		k++;
		t->count=1;root=t;
		addend(t->key,c);
		
	}
	else
	{
		m=leaf(root,c);
		addend(m->key,c);
		cout<<"w"<<endl;
		sort(m->key);
		m->count++;
	//	print(m->key,m->count);
		if(m->count>2*d1)
		nodesplit(m);
	}
}

int main()
{
	bdtree *l=NULL;
	int a=1;int y=0;
//	cout<<"enter the starting no "<<endl;;
//	cin>>a;
	int q[40]={100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,1,2,3,4,5,6,7,8,9,101};
	while(a!=101)
	{
		a=q[y++];
		create(l,a);
		l=root;
	//	cout<<"enter the next no "<<endl;
	//	cin>>a;
	//	a++;
		printorder(root);
	}
cout<<endl;
//printorder(root);
return 0;
}




