#include<iostream>
#include<algorithm>
#define d 2
using namespace std;
struct bdnode
{
	int count;
	int key[2*d];
	bdnode *ptr[2*d+1];
};
typedef bdnode *bdptr;
void initialise(bdptr &T)
{
	T=new bdnode;
	T->count=0;
	for(int i=0;i<2*d;i++)
	T->key[i]=-1;
	for(int i=0;i<2*d+1;i++)
	T->ptr[i]='\0';
}
int getHeight(bdptr T)
{
   if(T=='\0')
   return 0;
   return getHeight(T->ptr[0])+1;
}
void printLevel(bdptr T,int l)
{
	if(T=='\0')
	return;
	if(l==0)
	{
		cout<<"[";
		for(int j=0;j<T->count;j++)
		cout<<T->key[j]<<",";
		cout<<"]";
	}
	else
	{
		for(int j=0;j<T->count+1;j++)
		printLevel(T->ptr[j],l-1);
	}
}
void print(bdptr T)
{
	int h=getHeight(T);
	for(int i=0;i<h;i++)
	{
	    printLevel(T,i);
	    cout<<endl;
	}
}
void printnode(bdptr t)
{
	cout<<t->count<<" is the count of t \n";
	for(int i=0;i<2*d;i++)
	cout<<t->key[i]<<",";
	cout<<"\n";
}
bdptr search(bdptr T,int k)
{
	if(T!='\0')
	{
		int i,j;
		for(i=0;i<T->count;i++)
		{
			if(T->key[i]>k)
			{
				j=1;
				if(T->ptr[i]!='\0')
				return(search(T->ptr[i],k));
				else
				return(T);
			}
		}
		if(T->ptr[i]!='\0')
		search(T->ptr[i],k);
		else
		return(T);
	}
}
bdptr getparent(bdptr T,bdptr t)
{
	int i;
	if(T!='\0')
	{
		if(T==t)
		{
			bdptr L='\0';
			return(L);
		}
		else
		{
			for(i=0;i<T->count;i++)
			{
				if(t->key[0]<=T->key[i])
				{
					if(t==T->ptr[i])
					return(T);
					else
					return(getparent(T->ptr[i],t));
				}
			}
			if(i==T->count)
			{
				if(T->ptr[i]==t)
				return(T);
				else
				return(getparent(T->ptr[i],t));
			}
		}
	}
}
void sort(bdptr &T)
{
	int c=0;
	for(int i=0;i<2*d-1;i++)
	{
		if(T->key[i]>T->key[i+1])
		{
			swap(T->key[i],T->key[i+1]);
			c++;
		}
	}
	if(c>0)
	sort(T);
}
int mid(bdptr &T,int k)
{
	if(k>T->key[d-1]&&k<T->key[d])
	{
		return(k);
	}
	else if(k<T->key[d-1])
	{
		swap(k,T->key[d-1]);
		sort(T);
		return(k);
	}
	else
	{
		swap(k,T->key[d]);
		sort(T);
		return(k);
	}
}
void insertsort(bdptr &T,int k)
{
	int p=T->count;
	for(int i=0;i<T->count;i++)
	{
		if(k<T->key[i])
		{
			p=i;
			break;
		}
	}
	for(int i=T->count;i>p;i--)
	{
		T->key[i]=T->key[i-1];
	}
	T->key[p]=k;
	T->count++;
}
void overflow(bdptr &T,bdptr t,bdptr xtra,int k,int p)
{
	int m=mid(t,k);
	bdptr temp=new bdnode;
	initialise(temp);
	for(int i=0;i<2*d;i++)
	{
		if(i<d)
		{
			temp->key[i]=t->key[d+i];
			t->key[d+i]=-1;
		}
	}			
	t->count=d;
	temp->count=d;
	if(p!=-1)
	{
		if(p==d)
		{
			for(int i=1;i<=d;i++)
			{
				temp->ptr[i]=t->ptr[i+d];
				t->ptr[i+d]='\0';
			}
			temp->ptr[0]=xtra;
		}
		else if(p<d)
		{
			for(int i=0;i<=d;i++)
			{
				temp->ptr[i]=t->ptr[i+d];
				t->ptr[i+d]='\0';
			}
			for(int i=d;i>p+1;i--)
			{
				t->ptr[i]=t->ptr[i-1];
			}
			t->ptr[p+1]=xtra;
		}
		else
		{
			for(int i=0;i<d;i++)
			{
				temp->ptr[i]=t->ptr[i+d+1];
				t->ptr[i+d+1]='\0';
			}
			p=p-d-1;
			for(int i=d;i>p+1;i--)
			temp->ptr[i]=temp->ptr[i-1];
			temp->ptr[p+1]=xtra;
		}
	}
	bdptr L=getparent(T,t);
	if(L=='\0')
	{
		bdptr L=new bdnode;
		L->key[0]=m;
		for(int i=1;i<2*d;i++)
		{
			L->key[i]=-1;
		}
		L->count=1;
		L->ptr[0]=t;
		L->ptr[1]=temp;
		for(int i=2;i<=2*d;i++)
		{
			L->ptr[i]='\0';
		}
		T=L;
	}
	else
	{
		if(L->count<2*d)
		{
			int i=0;
			while(L->ptr[i]!=t)
			{
				i++;
			}
			for(int j=L->count;j>i;j--)
			{
				L->ptr[j+1]=L->ptr[j];
				L->key[j]=L->key[j-1];
			}
			L->key[i]=m;
			L->ptr[i+1]=temp;
			L->count++;	
		}
		else
		{
			xtra=temp;
			for(int i=0;i<=2*d;i++)
			{
				if(L->ptr[i]==t)
				p=i;
			}
			overflow(T,L,xtra,m,p);
		}
	}
}
void addnode(bdptr &T,int k)
{
	if(T=='\0')
	{
		initialise(T);
		T->key[T->count++]=k;
	}
	else
	{
		bdptr t=search(T,k);
		if(t->count<2*d)
		{
			insertsort(t,k);
		}
		else
		{
			bdptr xtra;
			xtra='\0';
			overflow(T,t,xtra,k,-1);
		}
	}
}
void printorder(bdptr t)
{
	if(t!='\0')
	{
		for(int i=0;i<2*d;i++)
		{
			printorder(t->ptr[i]);
			if(t->key[i]!=-1)
			cout<<t->key[i]<<",";	
		}
		printorder(t->ptr[2*d]);
	}
}
int main()
{
	bdptr T='\0';
	int i=1;
	while(i!=-1)
	{
		cout<<"enter element to be added to bd tree\n";
		cin>>i;
		if(i!=-1)
		addnode(T,i);
		print(T);
		cout<<"\n";
		printorder(T);
		cout<<"\n";
	}
	print(T);
	
}
/*
100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 76 75 74 73 72 71 1 2 3 4 5 6 7 8 9
*/
