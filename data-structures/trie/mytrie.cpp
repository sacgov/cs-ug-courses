#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct tod;
union un
{
	tod *ptr[27];
	char data[15];
};
struct tod
{
	int tag;
	un u;
};
void create(tod*&t)
{
	t=new tod;
	t->tag=0;
	for(int i=0;i<27;i++)
	t->u.ptr[i]=NULL;
}
void insert(tod* t,char data[],int index)
{
	int k=data[index]-97;
	if(t->u.ptr[k]==NULL)
	{
		if(index<=strlen(data)-1)
		{
			t->u.ptr[k]=new tod;
			t->u.ptr[k]->tag=1;
			strcpy(t->u.ptr[k]->u.data,data);
		}
		else
		{
			t->u.ptr[26]=new tod;
			t->u.ptr[26]->tag=1;
			strcpy(t->u.ptr[26]->u.data,data);
		}
	}
	else 
	{
		index++;
		if(t->u.ptr[k]->tag==1)
		{
			char temp[15];
			tod*t=new tod;
			create(t);
			strcpy(temp,t->u.ptr[k]->u.data);
			t->u.ptr[k]=t;
			insert(t->u.ptr[k],temp,index);
			insert(t->u.ptr[k],data,index);
		}
		else
		insert(t->u.ptr[k],data,index);	
	}
}
int main()
{
	tod* t;
	create(t);
	char data[300];
	while(1)
	{
		cout<<"enter data to be added : ";
		cin>>data;
		if(data[0]=='0')
		break;
		insert(t,data,0);
	}
//	print(t);
}
