#include<iostream>
#include<algorithm>
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
	cout<<endl;
	q.enqueue(n);
	while(t!=NULL)
	{
    for(int i=0;i<t->count;i++)
    cout<<t->key[i]<<" ";
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
	{
		l->child[i]=NULL;
		l->key[i]=-1;
	}
	l->child[2*d1+1]=NULL;
	l->parent=NULL;
	l->count=0;
	return l;
}
void nodesplit(bdtree *&m)
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
		{
			cout<<"nspm ";
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
		bool flagl=false;
		/*
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
		cout<<"rp ";
		if(!(flagr||flagl))
		{
			cout<<"ns ";
			nodesplit(m);
		}*/
		int k=-1;
		for(int i=a1-1;i>=0;i--)
		{
			if(m->parent->child[i]->count<2*d1)
			{
				k=i;break;
			}
		}
		cout<<"k= "<<k<<endl;
		cout<<"a1 "<<a1<<endl;
		if(k!=-1)
		for(int i=k+1;i<=a1;i++)
		{
		flagl=left(m,i);
		cout<<"kg"<<endl;
	//	printorder(root);
		cout<<"l";}
		if(!flagl)
		{
			cout<<"a";
			for(int i=a1+1;i<=m->parent->count;i++)
		{
		    k=-1;cout<<"l"<<i<<"l";
			if(m->parent->child[i]->count<2*d1)
			{
				k=i;break;
			}
		}
		cout<<":"<<k<<";";
		if(k!=-1)
		for(int i=k-1;i>=a1;i--)
		bool flagr=right(m,i);
		}
		sort(m->parent->key,m->parent->key+m->parent->count);
		if(k==-1)
		{
			cout<<"ad ";
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
int main()
{
	bdtree *l=NULL;
	int a=40,y=0;
	
//	cout<<"enter the starting no "<<endl;;
//	cin>>a;
	int q[40]={100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,1,2,3,4,5,6,7,8,9,101};
	int q2[40]={2,3,4,5,6,7,12,18,25,27,30,37,32};
	while(a!=32)
	{
		a=q2[y++];
		create(l,a);
		l=root;
	//	cout<<"enter the next no "<<endl;
	//    cin>>a;
		cout<<endl;
        printorder(root);
	//	a--;
	}

return 0;
}
