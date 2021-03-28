#include<iostream>
using namespace std;
const int d=2;
struct bd
{
	int count=0;
	bd*child[2*d+1];
	int arr[2*d];
	bd*pptr=NULL;
};
int med=-1;bd*one=NULL;bd*two=NULL;
bool isleaf(bd*t,int med,int k)
{
	int count=0;
	for(int i=0;i<2*d+1;i++)
	{
		if(t->child[i]!=NULL)
		{
			count=1;
		}
	}
	if(count==0)
	{
	med=k;
	return true;
    }
	else
	return false;
}
void insertsort(bd*&head,int k)
{
	int temp[head->count];
	for(int i=0;i<head->count-1;i++)
	temp[i]=head->arr[i];
	temp[head->count-1]=k;
	for(int i=0;i<head->count;i++)
	{
		for(int j=i+1;j<head->count;j++)
		{
			if(temp[i]>temp[j])
			{
				int t=temp[i];
				temp[i]=temp[j];
				temp[j]=t;
			}
		}
	}
	for(int i=0;i<head->count;i++)
	{
		head->arr[i]=temp[i];
	}
}
void makenode(bd*&h)
{
	h=new bd;
	for(int i=0;i<2*d+1;i++)
	h->child[i]=NULL;
}
void splitnode(bd*&head,int k)
{
	int temp[head->count+1];
	for(int i=0;i<head->count;i++)
	temp[i]=head->arr[i];
	temp[head->count]=k;
	for(int i=0;i<=head->count;i++)
	{
		for(int j=i+1;j<=head->count;j++)
		{
			if(temp[i]>temp[j])
			{
				int t=temp[i];
				temp[i]=temp[j];
				temp[j]=t;
			}
		}
	}
	makenode(one);
	makenode(two);
	for(int i=0;i<d;i++)
	{
		one->arr[i]=temp[i];
		two->arr[i+d+1]=temp[i+d+1];
	}
	med=temp[d];
}
void add(bd*&head,int k)
{
	while(!isleaf(head,med,k))
	{
		if(k>head->arr[head->count-1])
		add(head->child[head->count],k);
		else
		for(int i=0;i<head->count;i++)
		{
			if(k<head->arr[i])
			add(head->child[i],k);
		}
	}
	if(med!=-1)
		{
			if(head->count<2*d)
			{
			head->count++;
			insertsort(head,k);
			med=-1;
		   }
		   else
		   {
		   	  splitnode(head,k);
		   }
        }
    if(one!=NULL)
    {
    	int h=one->arr[0];
    	for(int i=0;i<head->count;i++)
    	if(head->arr[i]>h)
    	{
    	head->child[i]=one;
    	head->child[i+1]=two;
    	one =new bd;
    	two=new bd;
    	one =NULL;
    	two=NULL;
    	break;
        }
        if(head->count==2*d&&k!=-1)
        splitnode(head,med);
    }
}
/*void print(bd*head)
{
	if(head!=NULL)
	{
		
	}
}*/
int main()
{
	bd*head;
	makenode(head);
	cout<<"____________btree creation____________";
	int k;
	for(int i=0;i<10;i++)
	{
		cin>>k;
		add(head,k);
	}
	cout<<
}
