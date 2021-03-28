#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
void add(int s,int k,int *H)
{
	int i=1;
	
//	ll c=k;
	while(1)
	{
		if(H[k]!=-1)
		{
			k=(k+i*i)%11;
			i++;
		/*	if(k==c)
			break;*/
		}
		else
		{
			H[k]=s;
			break;
		}
	}
}
/*void search(int s,int *H)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(H[i]==s)
		{
			cout<<"Element found"<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
	cout<<"Element not found"<<endl;
}*/
int main()
{
	//ll n;
	cout<<"how many numbers does file have : ";
	cin>>n;
	int H[11];
	int S[n];
	for(int j=0;j<11;j++)
	H[j]=-1;
	/*for(int j=0;j<n;j++)
	S[j]=-1;*/
	cout<<"enter number : \n";
	for(ll i=0;i<n;i++)
	{
		cin>>S[i];
	}
	//cout<<S[2];
	for(ll i=0;i<n;i++)
	{
	
	//	cout<<S[i]<<" ";
		//cout<<int(S[i][0])<<" ";*/
		int k=S[i]%11;
	//	cout<<k;
		int s=S[i];
		//cout<<s<<"O";
		add(s,k,H);
	}
	for(ll i=0;i<11;i++)
	{
		cout<<H[i]<<" ";
	}
	
	/*int t=1;
	while(t)
	{
		cout<<"enter element to search : ";
		cin>>s;
		int K=(int(s[0])-97)%12;
		search(s,H);
		cout<<"Search more?(1/0)"<<endl;
		cin>>t;
	}*/
	return 0;
}
