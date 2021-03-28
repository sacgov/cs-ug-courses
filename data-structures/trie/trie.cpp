#include<iostream>
#include<string>
using namespace std;
struct trie;
union un
{
	string* data;
	trie* next[27];
};
struct trie
{
	int tag;
	un u;
};
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size=150;
	trie* e[500];
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
	void enqueue(trie* k)
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
	trie* dequeue()
	{
		trie*t;
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
void printorder(trie*t)
{
	trie*n=NULL;
	queue q;
	q.enqueue(n);
	while(t!=NULL)
	{
	if(t->tag==0)
	cout<<*t->u.data<<" ";
	else
	for(int i=0;i<27;i++)
	if(t->u.next[i]!=NULL)
    {q.enqueue(t->u.next[i]);}
	trie*k=q.dequeue();
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
void create(trie*&t)
{
	t=new trie;
	for(int i=0;i<27;i++)
    t->u.next[i]=NULL;
    t->tag=1;

}
void create(trie*&t,string data)
{
	t=new trie;
	t->tag=0;
	t->u.data=new string;
	*t->u.data=data;
}
trie *root;
void insert(string data,int in,trie *& t)
{
	if(t==NULL)
	{
		create(t);
		cout<<"1"<<endl;	
	}
	int ind=data[in++]-97;
	cout<<endl<<"ind ="<<ind<<endl;
	cout<<"in="<<in<<endl;
	if(in == data.length())
	{
		cout<<"2";
		if(t->u.next[ind]==NULL)
		{
			create(t->u.next[ind],data);
			cout<<"3";
		}
		else
		{
			cout<<"4";
			if(t->u.next[ind]->tag==0)
			{
				string x=*t->u.next[ind]->u.data;
				create(t->u.next[ind]);
				int q=x[in]-97;
				create(t->u.next[ind]->u.next[q],x);
				create(t->u.next[ind]->u.next[26],data);
				cout<<"5";
			}
			else
				{
					cout<<"7";
					create(t->u.next[ind]->u.next[26],data);
					cout<<"6";
					
				}
		}
	}
	else
	{
		cout<<"9";
		if(t->u.next[ind]==NULL)
		{
			create(t->u.next[ind],data);
			cout<<"8";
		}	
		else
		{
			cout<<" 10 ";
			if(t->u.next[ind]->tag==0)
			{
				cout<<" 11 ";
				string x=*t->u.next[ind]->u.data;
				create(t->u.next[ind]);
				cout<<"p"<<endl;
				printorder(root);
				cout<<"p"<<endl;
				int q=x[in]-97;
				cout<<"q ="<<q<<endl;
				create(t->u.next[ind]->u.next[q],x);
				insert(data,in,t->u.next[ind]);
				cout<<" 12 ";
			}
			else
			{
				cout<<" 13 ";
				insert(data,in,t->u.next[ind]);
				cout<<" 14 ";
				
			}
				
		}

	}
}

int main()
{
	trie *t=NULL;
	while(1)
w	{
		string s;
		cin>>s;
		int g=0;
		if(s!="y")
		insert(s,g,t);
		else
		break;
		cout<<endl<<"print ";
		root  =t;
		printorder(t);
	}



}
