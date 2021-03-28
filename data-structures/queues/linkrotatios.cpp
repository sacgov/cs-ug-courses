#include<iostream>
#include<string>
using namespace std;
struct lnode
{
	char data;
	lnode* next;
};
void print(lnode *l)
{
	while(l!=NULL)
{
cout<<l->data;
l=l->next;
}} 
string getstring(lnode *l,int len)
{
	int i;string t="";
	for(i=0;i<len;i++)
	{
		t=t+l->data;
		l=l->next;
	}
	return t;
}
void addend(lnode *l,char k)
{
	lnode *temp;
	temp=new lnode;
	temp->data=k;
	while(l->next!=NULL)
	l=l->next;
	l->next=temp;
	temp->next=NULL;
}  
int main()
{
	cout<<"enter string one";
	string s1;
    getline(cin,s1);
    int len=s1.length();
    int i;char c;
    string s2;
    getline(cin,s2);
  lnode *l;
lnode *tem;
tem=new lnode;
int j;
l=tem;
for(i=0;i<len;i++)
{
	tem->data=s1[i];
	if(i!=len-1)
	{
	tem->next=new lnode;
	tem=tem->next;}
	else
	tem->next=l;
} 
string s[len];
for(i=0;i<len;i++)
{
s[i]=getstring(l,len);
l=l->next;
}
for(i=0;i<len;i++)
{
	if(s[i]==s2)
	{
		cout<<"it is obtained in "<<i<<" rotations"<<endl;
		exit(1);
	}
}
cout<<"not a rotation"<<endl;

}
