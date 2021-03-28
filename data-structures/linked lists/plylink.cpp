#include<iostream>
#include<string>
using namespace std;
struct lnode
{
	int data;
	int exp;
	lnode* next;
};
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data<<"X"<<l->exp<<"+";
l=l->next;
}}
void addend(lnode *l,int cf,int e)
{
	lnode *temp;
	temp=new lnode;
	temp->data=cf;
	temp->exp=e;
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;
	temp->next=NULL;
}
void add(lnode *l1,lnode *l2,lnode *l3)
{
	int cf,e;
	if(l1->exp>l2->exp)
	{
	l3->data=l1->data;
	l3->exp=l1->exp;
	l3->next=NULL;
	l1=l1->next;
	}
	else if(l2->exp>l1->exp)
	{
	l3->data=l2->data;
	l3->exp=l2->exp;
	l3->next=NULL;
	l2=l2->next;
	}
	else
	{
	l3->data=l2->data+l1->data;
	l3->exp=l2->exp;
	l3->next=NULL;
	l2=l2->next;
	l1=l1->next;
    }
	while(l1!=NULL&&l2!=NULL)
	{
	if(l1->exp>l2->exp)
	{
	cf=l1->data;
	e=l1->exp;
	l1=l1->next;
	}
	else if(l2->exp>l1->exp)
	{
	cf=l2->data;
	e=l2->exp;
	l2=l2->next;
	}
	else
	{
	cf=l2->data+l1->data;
	e=l2->exp;
	l2=l2->next;
	l1=l1->next;
	}
	addend(l3,cf,e);
	}
	if(l1==NULL)
	{
		while(l2!=NULL)
		{
			cf=l2->data;
	e=l2->exp;
	l2=l2->next;
	addend(l3,cf,e);
		}
	}
		else
	{
		while(l1!=NULL)
		{
			cf=l1->data;
	e=l1->exp;
	l1=l1->next;
	addend(l3,cf,e);
		}
	}}
	void sub(lnode *l1,lnode *l2,lnode *l3)
{
	int cf,e;
	if(l1->exp>l2->exp)
	{
	l3->data=l1->data;
	l3->exp=l1->exp;
	l3->next=NULL;
	l1=l1->next;
	}
	else if(l2->exp>l1->exp)
	{
	l3->data=l2->data;
	l3->exp=l2->exp;
	l3->next=NULL;
	l2=l2->next;
	}
	else
	{
	l3->data=l2->data-l1->data;
	l3->exp=l2->exp;
	l3->next=NULL;
	l2=l2->next;
	l1=l1->next;
    }
	while(l1!=NULL&&l2!=NULL)
	{
	if(l1->exp>l2->exp)
	{
	cf=l1->data;
	e=l1->exp;
	l1=l1->next;
	}
	else if(l2->exp>l1->exp)
	{
	cf=l2->data;
	e=l2->exp;
	l2=l2->next;
	}
	else
	{
	cf=l2->data-l1->data;
	e=l2->exp;
	l2=l2->next;
	l1=l1->next;
	}
	addend(l3,cf,e);
	}
	if(l1==NULL)
	{
		while(l2!=NULL)
		{
			cf=l2->data;
	e=l2->exp;
	l2=l2->next;
	addend(l3,cf,e);
		}
	}
		else
	{
		while(l1!=NULL)
		{
			cf=l1->data;
	e=l1->exp;
	l1=l1->next;
	addend(l3,cf,e);
		}
	}
	}
int main()
{
	lnode *l1;
	lnode *l2;
	lnode *l3;
	l1=new lnode;
	l2=new lnode;
	l3=new lnode;
	char c;
	int e;
	int cf;
	cout<<"enter cofficient and exponent"<<endl;
	cin>>cf;
	l1->data=cf;
	cin>>e;
	l1->exp=e;
	l1->next=NULL;
	cout<<"enter y to continue"<<endl;
	cin>>c;
	
	while(c=='y')
	{
		cin>>cf;
		cin>>e;
		addend(l1,cf,e);
	    cout<<"to continue press y"<<endl;
	    cin>>c;	     
    }
	cout<<"enter cofficient and exponent"<<endl;
	cin>>cf;
	l2->data=cf;
	cin>>e;
	l2->exp=e;
	l2->next=NULL;
	cout<<"enter y to continue"<<endl;
	cin>>c;
	while(c=='y')
	{
		cin>>cf;
		cin>>e;
		addend(l2,cf,e);
	    cout<<"to continue press y"<<endl;
	    cin>>c;	     
	}
	cout<<"first ";print(l1);
	cout<<endl;
	cout<<"second ";print(l2);
    cout<<endl;
	add(l1,l2,l3);
	cout<<"added ";print(l3);
	l1=new lnode;
	l2=new lnode;
	l3=new lnode;
	cout<<"enter cofficient and exponent"<<endl;
	cin>>cf;
	l1->data=cf;
	cin>>e;
	l1->exp=e;
	l1->next=NULL;
	cout<<"enter y to continue"<<endl;
	cin>>c;
	
	while(c=='y')
	{
		cin>>cf;
		cin>>e;
		addend(l1,cf,e);
	    cout<<"to continue press y"<<endl;
	    cin>>c;	     
    }
	cout<<endl<<"enter cofficient and exponent"<<endl;
	cin>>cf;
	l2->data=cf;
	cin>>e;
	l2->exp=e;
	l2->next=NULL;
	cout<<"enter y to continue"<<endl;
	cin>>c;
	while(c=='y')
	{
		cin>>cf;
		cin>>e;
		addend(l2,cf,e);
	    cout<<"to continue press y"<<endl;
	    cin>>c;	     
	}
	cout<<"first ";print(l1);
	cout<<endl;
	cout<<"second ";print(l2);
    cout<<endl;
	sub(l1,l2,l3);
	cout<<"sub ";print(l3);
	
}
