#include<iostream>
#include<string>
using namespace std; 
struct lnode
{
	int d1,d2;
	lnode* next;
}; 
void addend(lnode *l,int k,int l)
{
	lnode *temp;
	temp=new lnode;
	temp->d1=k;
	temp->d2=l;
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;
	temp->next=NULL;
}
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->d1<<" "<<l->d2<<endl;
l=l->next;
}} 
int arr(lnode *l,int a1[],int a2[])
{
	int i=0;
	while(l!=NULL)
{
a1[i]=l->d1;a2[i]=l->d2;
l=l->next;
i++;
}
return i;
} 
int main()
{
	int a1[50],a2[50];
	cout<<"enter number of bins"<<endl;
	lnode *l1;
	lnode *tem;
    tem=new lnode;
    int n,i,j,bin;
    l1=tem;
    cin>>n;
	for(i=0;i<n;i++)
{
	cin>>j;
	cin>>bin;
	tem->d1=j;
	tem->d2=bin;
	if(i!=n-1)
	{
	tem->next=new lnode;
	tem=tem->next;}
	else
	tem->next=NULL;
} 
int w=arr(l1,a1,a2);
int temp1,temp2;
for(i=0;i<w;i++)
{
for(j=0;j<w;j++)
{
if(a1[i]<a1[j])
{
temp1=a1[j];  
temp2=a2[j];                    
a1[j]=a1[i];
a2[j]=a2[i];
a1[i]=temp1;
a2[i]=temp2;
}}}
int s[10];
lnode *m;
m->d1=0;
m->d2=0;
m->next=NULL;

for(i=0;i<w;i++)
{ int k=0;
int d=a1[i];
while(a1[i]==d)
s[k++]=a2[i++];
for(int e=0;e<k;e++)
{
for(j=0;j<k;j++)
{
if(s[e]<s[j])
{
temp1=s[e];                     
s[e]=s[j];
s[j]=temp1;

}}}
for(int h=0;h<k;h++)
{
	addend(m,d,s[h]);
}
i--;
}
print(m);
}
