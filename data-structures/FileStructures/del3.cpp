#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct trienode;
union trie
{
	trienode *ptr[27];
	char data[100];
};
struct trienode
{
	int l;
	trie u;
};
typedef trienode *tptr;
void initialise(tptr &T)
{
	T=new trienode;
	T->l=0;
	for(int i=0;i<27;i++)
	{
		T->u.ptr[i]='\0';
	}
}
void insert(tptr &T,char s[],int i)
{
		int k=s[i]-97;
		if(T->u.ptr[k]=='\0')
		{
			if(i<strlen(s))
			{
				T->u.ptr[k]=new trienode;
				T->u.ptr[k]->l=1;
				strcpy(T->u.ptr[k]->u.data,s);
			}
			else
			{
				T->u.ptr[26]=new trienode;
				T->u.ptr[26]->l=1;
				strcpy(T->u.ptr[26]->u.data,s);
			}
		}
		else 
		{
			i++;
			if(T->u.ptr[k]->l==1)
			{
				tptr t;
				char temp[100];
				t=new trienode;
				initialise(t);
				strcpy(temp,T->u.ptr[k]->u.data);
				T->u.ptr[k]=t;
				insert(T->u.ptr[k],temp,i);
				insert(T->u.ptr[k],s,i);
			}
			else
			{
				insert(T->u.ptr[k],s,i);	
			}
		}
}
int oneleft(tptr T)
{
	int c=0;
	for (int i=0;i<27;i++)
	{
		if(T->u.ptr[i]!='\0')
		c=i;
	}
	return(c);	
}
int anyleft(tptr T)
{
	int c=0;
	for (int i=0;i<26;i++)
	{
		if(T->u.ptr[i]!='\0')
		c++;
	}
	return(c);	
}
void del(tptr &T,char s[],int i);
void check(tptr &T)
{
	char temp[100];
	if(anyleft(T)<=1)
	{
		if(anyleft(T)==0)
		T='\0';	
		else
		{
			cout<<"single index remaining is "<<oneleft(T)<<"\n";
			strcpy(temp,T->u.ptr[oneleft(T)]->u.data);
			cout<<"temp is "<<temp<<"\n";
			cout<<"its going to delete "<<T->u.ptr[oneleft(T)]->u.data<<"\n";
			T=T->u.ptr[oneleft(T)];
		}
	}
}
void del(tptr &T, char s[], int i)
{
	int k=s[i]-97;
	if(T!='\0')
	{
		if(i==strlen(s)-1)
		{
			cout<<"deleting in blank\n";
			cout<<i<<","<<k<<"\n";
			if(T->u.ptr[k]->u.ptr[26]!='\0')
			{
				T->u.ptr[k]->u.ptr[26]='\0';
				cout<<"here\n";
				check(T->u.ptr[k]);
			}	
		}
		else if(T->u.ptr[k]->l==1)
		{
			cout<<"deleting in non blank\n";
			if(strcmp(T->u.ptr[k]->u.data,s)==0)
			{
				T->u.ptr[k]='\0';
				if(i>=1)
				check(T);
			}
		}
		else
		{
			++i;
			cout<<"deleting in lower level\n";
			del(T->u.ptr[k],s,i);
			check(T->u.ptr[k]);
		}
	}
}
void print(tptr T)
{
	if(T!='\0')
	{
		if(T->l==1)
		{
			cout<<T->u.data<<"\n";
		}
		else
		{
			for(int i=0;i<27;i++)
			{
				if(T->u.ptr[i]!='\0')
				cout<<i<<",";
				print(T->u.ptr[i]);
			}
		}
	}
}
int main()
{
	tptr T;
	initialise(T);
	int i=1,j;
	char s[100];
	while(i)
	{
		j=0;
		cout<<"enter name to be added to trie : ";
		cin>>s;
		insert(T,s,j);
		cout<<"enter 1 to continue adding elements any other to stop : ";
		cin>>i;
	}
	print(T);
	i=1;
	while(i)
	{
		j=0;
		cout<<"enter name to be deleted\n";
		cin>>s;
		del(T,s,j);
		print(T);
		cout<<"enter 1 to continue any other to exit \n";
		cin>>i;
	}
	print(T);
}
