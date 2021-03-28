#include <iostream>
#include <cstring>
using namespace std;
struct tod;
union trie
{
	tod *ptr[27];
	char data[15];
};
struct tod
{
	int tag;
	trie u;
};
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size=150;
	tod* e[500];
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
	void enqueue(tod* k)
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
	tod* dequeue()
	{
		tod*t;
		if(isqempty())
		{
			cout<<"queue is empty ";
			exit(1);
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
void printorder(tod*t)
{
	tod*n=NULL;
	queue q;
	q.enqueue(n);
	while(t!=NULL)
	{
	if(t->tag==1)
	cout<<t->u.data<<" ";
	else
	for(int i=0;i<27;i++)
	if(t->u.ptr[i]!=NULL)
    {q.enqueue(t->u.ptr[i]);}
	tod*k=q.dequeue();
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
void create(tod* &T)
{
	T=new tod;
	T->tag=0;
	for(int i=0;i<27;i++)
		T->u.ptr[i]='\0';
}
void insert(tod* T,char data[],int i)
{
	int k=data[i]-97;
	if(T->u.ptr[k]=='\0')
	{
		if(i<=strlen(data)-1)
		{
			T->u.ptr[k]=new tod;
			T->u.ptr[k]->tag=1;
			strcpy(T->u.ptr[k]->u.data,data);
		}
		else
		{
			T->u.ptr[26]=new tod;
			T->u.ptr[26]->tag=1;
			strcpy(T->u.ptr[26]->u.data,data);
		}
	}
	else 
	{
		i++;
		if(T->u.ptr[k]->tag==1)
		{
			tod* t;
			char temp[15];
			create(t);
			strcpy(temp,T->u.ptr[k]->u.data);
			T->u.ptr[k]=t;
			insert(T->u.ptr[k],temp,i);
			insert(T->u.ptr[k],data,i);
		}
		else
		insert(T->u.ptr[k],data,i);	
	}
}
int main()
{
	tod* T;
	create(T);
	char data[15];
	while(1)
	{
		cout<<"enter name to be added to trie : ";
		cin>>data;
		if(data[0]!='0')
		insert(T,data,0);
		else
		break;
	}
	printorder(T);
}
