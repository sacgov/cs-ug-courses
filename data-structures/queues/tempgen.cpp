#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct dnode
{
	int data;
	dnode* right;
	dnode* left;
};
void addend(dnode *l,int k)
{
	dnode *temp;
	temp=new dnode;
	temp->data=k;
	temp->right=NULL;
	temp->left=NULL;
	while(l->right!=NULL)
	l=l->right;
	l->right=temp;
	temp->left=l;	
} 
void print(dnode *l)
{
	l=l->right;
	while(l!=NULL)
{
cout<<l->data;
l=l->right;
}} 
class stack
{
	public:
	string s;
void push(char x)
{
	top++;
	s[top]=x;
	
}	
char pop()
{
	char t;
	t=s[top];
	top--;
	return t;
}
int top=-1;
char atop()
{
	return s[top];
}};
class queue
{
	public:
	int front=-1;
	int rear=-1;
	int size;
	int e[50];
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
	void enqueue(int k)
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
	int dequeue()
	{
		int t;
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
int stoi(string s)
{
	int sum=0,j;
	int k=0;
	int len=s.length();
	for(j=len-1;j>=0;j--)
	{
		int y=s[j]-48;
		sum=sum+y*pow(10,k++);
	}
	return sum;
} 

struct node
{
    dnode *d;
	stack st;
	queue q;
}; 
int main()
{
	node n;
n.d=new dnode;
n.d->right=NULL;
n.d->left=NULL;
int i,j;
n.d->data=1;
string s;
int r=0;
 	getline(cin,s);
 	int len=s.length();
 	for(j=0;j<len;j++)
 	{
 		int y=s[j]-48;
 		if(y>9)
 		r=1;
 	} 
 	if(r==0)
 	{    int y=stoi(s);
 		addend(n.d,y);
 	}
 	for(j=0;j<len;j++)
 	{
 		int y=s[j]-48;
 		if((y<10&&y>-1)||y==-2)
 		w=1;
 	}
 		if(w==1)
 		{
 			float z=stof(s);
 			
 		}
 	} 
 	
 	
print(n.d);

}
