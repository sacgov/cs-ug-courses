#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode* next;
};
void addend(lnode *l,int k)
{
	lnode *temp;
	temp=new lnode;
	temp->data=k;
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;
	temp->next=NULL;
}  
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data<<" ";
l=l->next;
}
cout<<endl;
}  
void arrinp(lnode *l,int arr[],int &t)
{
while(l->next!=NULL)
{	
arr[t]=l->next->data;
t++;
l=l->next;
}}    
int main()
{
	int t;
	int arr[100];
	lnode *n[10];
	int i;
	for(i=0;i<10;i++) 
	{
		n[i]=new lnode;
		n[i]->data=i;
		n[i]->next=NULL;
	}
	cout<<"enter no integers"<<endl;
	 char c='y';
	while(c=='y')
	{
		cout<<"data to be entered"<<endl;
		int num;
		cin>>num;
		int k=num%10;
		addend(n[k],num);
		cin>>c;
	} 
	t=0;
	for(i=0;i<10;i++) 
	{
		arrinp(n[i],arr,t);
	}
	int h,co;
	int f[t];
	for(i=0;i<t;i++)
	{
		co=0;h=arr[i];
		while(h!=0)
		{
			h=h/10;
			co++;
		}
		if(arr[i]==0)
		co=1;
		f[i]=co;
	}
	int j=0;
	int temp,max=0;
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			if(f[i]>=f[j])
			{
				if(f[i]>max)
				max=f[i];
			}
		}	
	}
	int kq,b,k;
	for(kq=2;kq<=max;kq++)
	{
		
		for(i=0;i<10;i++) 
	    {
		n[i]=new lnode;
		n[i]->data=i;
		n[i]->next=NULL;
     	}
     	for(b=0;b<t;b++)
     	{
     	int num=arr[b];
     	for(i=1;i<kq;i++)
		{
		arr[b]=arr[b]/10;
		k=arr[b]%10;}
		addend(n[k],num);}
		t=0;
		for(i=0;i<10;i++) 
		arrinp(n[i],arr,t);	 	
	}
	for(i=0;i<t;i++) 
    cout<<arr[i]<<" ";	
	} 
