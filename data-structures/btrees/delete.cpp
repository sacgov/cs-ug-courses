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
	int size=250;
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
	}
	l->child[2*d1+1]=NULL;
	l->parent=NULL;
	l->count=0;
	return l;
}
int gh=1;int gh1;
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
		nodesplit(m);
	}
}
void printorder(bdtree*t)
{
	bdtree*n=NULL;
	queue q;
	q.enqueue(n);
	cout<<endl;
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
void parset(bdtree*t)
{
	bdtree*n=NULL;
	queue q;
	q.enqueue(n);
	cout<<endl;
	t->parent=NULL;
	while(t!=NULL)
	{
    for(int i=0;i<=t->count;i++)
    {
    if(t->child[i]!=NULL)
    {
    	t->child[i]->parent=t;
		q.enqueue(t->child[i]);
    }
    }
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
int getindex(bdtree*t,int k)
{
	int x=-1;
		for(int i=0;i<t->count;i++)
		{
			if(t->key[i]==k)
			{
				x=i;break;
			}
		}
		return x;
}
int getpp(bdtree*m)
{
	for(int i=0;i<m->parent->count+1;i++)
	    {
	 	if(m->parent->child[i]==m)
	 	{
	 		cout<<"imp"<<m->parent->count<<root->count<<root->child[1]->key[0]<<m->key[0]<<"imp";
	 		return i;
	 	}
	    }
}
bdtree*search(bdtree*t,int k)
{
	if(t==NULL)
	return NULL;
	int c=-1;
	cout<<"s1";
	for(int i=0;i<t->count;i++)
	{
		if(k==t->key[i])
		{
			cout<<"sr"<<i;
			return t;
		}
	} 
	cout<<"s2";
	if(k>t->key[t->count-1])
	return(search(t->child[t->count],k));
	else
	{
		cout<<"s3";
		for(int i=0;i<t->count;i++)
		{
			if(k<t->key[i])
			return(search(t->child[i],k));
		}
	}
}
bool leftd(bdtree*&m,int a1)
{
	bdtree*mp=m->parent;
	if(a1==0)
	return false;
	a1--;
	if(mp->child[a1]==NULL)
	return false;
	else
	{
	if(mp->child[a1]->count<=d1)
	return false;
	else
	{
		cout<<"a1"<<a1<<"a1";
		for(int i=0;i<2*d1;i++)
		m->key[i+1]=m->key[i];
		m->key[0]=mp->key[a1];
		mp->key[a1]=mp->child[a1]->key[mp->child[a1]->count-1];
		mp->child[a1]->count--;
		m->count++;
		return true;
	}	}
}
bool rightd(bdtree*&m,int a1)
{
	bdtree*mp=m->parent;
	if(a1==2*d1)
	return false;
	int k=a1+1;
	if(mp->child[k]==NULL)
	return false;
	else
	{
	if(mp->child[k]->count<=d1)
	return false;
	else
	{
		m->key[m->count]=mp->key[a1];
		mp->key[a1]=mp->child[k]->key[0];
		for(int i=0;i<mp->child[k]->count;i++)
		mp->child[k]->key[i]=mp->child[k]->key[i+1];
		mp->child[k]->count--;
		m->count++;
		return true;
	}}	
}
bool isroot(bdtree*m)
{
	if(m->parent==NULL)
	return true;
	else
	return false;
}
void nodecomb(bdtree*d)
{
	if(d->parent!=NULL)
	{
		cout<<"k";
		int a1=getpp(d);
		if(a1!=0)
		{
			a1=a1-1;
			d->parent->child[a1]->key[d->parent->child[a1]->count++]=d->parent->key[a1];
			for(int i=0;i<d->count;i++)
			{
				d->parent->child[a1]->key[d->parent->child[a1]->count]=d->key[i];
				d->parent->child[a1]->child[d->parent->child[a1]->count]=d->child[i];
				d->parent->child[a1]->count++;
			}
			d->parent->child[a1]->child[d->parent->child[a1]->count]=d->child[d->count];
			for(int i=a1;i<d->parent->count;i++)
			{
				d->parent->key[i]=d->parent->key[i+1];
				d->parent->child[i+1]=d->parent->child[i+2];
			}
			d->parent->count--;
		}
		else
		{
			d->key[d->count++]=d->parent->key[a1];
			for(int i=0;i<d->parent->child[a1+1]->count;i++)
			{
				d->key[d->count]=d->parent->child[a1+1]->key[i];
				d->child[d->count]=d->parent->child[a1+1]->child[i];
				d->count++;
			}
			d->child[d->count]=d->parent->child[a1+1]->child[d->parent->child[a1+1]->count];
				for(int i=a1;i<d->parent->count;i++)
			{
				d->parent->key[i]=d->parent->key[i+1];
				d->parent->child[i+1]=d->parent->child[i+2];
			}
			d->parent->count--;
		}
		if(d->parent->count<d1)
		{
			cout<<"par";
			nodecomb(d->parent);
			cout<<"par";
		}
		
	}
	else
	{
		cout<<"kk";
		if(d->count==0)
		{
			cout<<"oo";cout<<d->child[0]->key[0]<<d->child[0]->key[1]<<d->child[0]->count<<"oo";
			root=d->child[0];
		}
		if(root->count>2*d1&&!isleaf(root))
		{
			cout<<"l";
			nodesplit(d);
		}
		return;
	}
}
bool getpre(bdtree*m,int k,bdtree *&leaf)
{
	bdtree*t=m;
	while(!isleaf(t))
	t=t->child[t->count];
	leaf=t;
	cout<<"lk"<<leaf->key[0]<<"lk";
	if(leaf->count<=d1)
	return false;
	else
	return true;
}
void del(bdtree*&root,int k)
{
	cout<<"01";
	bdtree* d=search(root,k);
	if(d==NULL)
	{
		cout<<"not found";
//		return false;
	}
	if(isleaf(d))
	{
		cout<<"1";
		int in=getindex(d,k);
		if(d->count>d1||isroot(d))
		{
			for(int i=in;i<d->count;i++)
			d->key[i]=d->key[i+1];
			d->count--;cout<<"2"<<d->count<<d->key[0];
			cout<<"2";
//			return true;
		}
		else
		{
			int a1=getpp(d);
			cout<<"a1"<<d->key[0]<<a1<<"a1";
			bool l=leftd(d,a1);
			if(l)
			{
				parset(root);
				cout<<"3";cout<<root->key[1]<<"3";del(root,k);
			}
			else
			{
				cout<<"4";
				bool r=rightd(d,a1);cout<<"5";
				if(r)
				{
					cout<<"jk";
					parset(root);
					del(root,k);
				}
				else
				{
					nodecomb(d);
					parset(root);
					printorder(root);
					del(root,k);
				}
			}
		}
		
	}
	else
	{
		cout<<"lol";
		int in=getindex(d,k);
		cout<<in;
		cout<<d->key[in];cout<<"k";
		bdtree*leaf;
		bool p=getpre(d->child[in],k,leaf);
		if(p)
		{
			cout<<"dk"<<d->key[in]<<"dk";
			d->key[in]=leaf->key[leaf->count-1];
			cout<<endl<<"pp";printorder(root);cout<<"pp"<<endl;
			cout<<"o";printorder(leaf);cout<<"o"<<endl;
			del(leaf,d->key[in]);
		}
		else
		{
		    cout<<"dk"<<d->key[in]<<"dk";
			d->key[in]=leaf->key[leaf->count-1];
			cout<<"o";printorder(leaf);cout<<"o"<<endl;
			gh1=d->key[in];
			del(leaf,d->key[in]);
			gh=0;
		}
		
	}
}
int main()
{
bdtree *l=NULL;
	int a=1;int y;
//	cout<<"enter the starting no "<<endl;;
//	cin>>a;
    int q[40]={100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,1,2,3,4,5,6,7,8,9,101};
	while(a!=101)
	{
	//	cout<<"enter the next no "<<endl;
	//	cin>>a;
	a=q[y++];
		if(a==-1)
		break;
		create(l,a);
		l=root;
	//	printorder(root);
	//	a++;
	}
cout<<endl;
printorder(root);a=0;
while(a!=-1)
{
	cout<<"value to delete ";
	cin>>a;
	del(root,a);
//	bool d=del(root,a);
    cout<<"gh"<<gh<<"gh";
	if(!gh)
	{
		cout<<"ooooooooo";
		gh=1;
		del(root,gh1);
		if(root->child[1]==NULL&&root->child[0]!=NULL)
		root=root->child[0];
		del(root,gh1);
		if(root->child[1]==NULL&&root->child[0]!=NULL)
		root=root->child[0];
		parset(root);
	}
	if(root->child[1]==NULL&&root->child[0]!=NULL)
		root=root->child[0];
	printorder(root);
}
return 0;
}
