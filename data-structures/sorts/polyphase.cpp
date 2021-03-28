#include<iostream>
#include<fstream>
using namespace std;
struct sachin
{
    int partiton[10];
    int size[10];
}s[4];
int emp;
void swap(int& a,int& b)
 {
     int t;
     t=a;
     a=b;
     b=t;
 }
void sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
	    j=i;
        while(j>0 && a[j]<a[j-1])
        {
            swap(a[j],a[j-1]);
            j=j-1;
        }
    }
}
int findmin(int m[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]<m[j])
          {
             j=i;
          }
    }
    return j;
}
int filemin(int k)
{
    int m=-1;
    for(int i=0;i<4;i++)
    {
        if(s[i].partiton[k]==0 && s[i].size[k]==0) emp=i;
        if(m<0 && s[i].partiton[k]!=0)
        {
            m=i;
        }
        else if(m>=0 && s[i].partiton[k]!=0 && s[i].partiton[k]<s[m].partiton[k])
        {
            m=i;
        }
    }
//    cout<<"emp is"<<emp<<endl;
    return m;
}
void print(int t)
{
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<t;j++)
            cout<<s[i].partiton[j]<<"->"<<s[i].size[j]<<" ";
        cout<<endl;
    }
}
void polymerge(fstream F[],char b[][20],int t,int cl)
{
//    cout<<"entered:\n";
    int k=filemin(t);int i;
 //   cout<<"k is "<<k<<endl;
 //   cout<<"emp is "<<emp<<endl;
    if(t==0)
    {
        for(i=0;i<4;i++)
        {
            if(i!=emp)
            F[i].open(b[i],ios::in);
        }
    }
    else
    F[cl].open(b[cl],ios::in);
    F[emp].open(b[emp],ios::out);
    int m[4];
    m[emp]=9999;int c[4];
//    cout<<"partiton is "<<s[k].partiton[t]<<endl;
    for(i=0;i<s[k].partiton[t];i++)
    {

//        cout<<"starting\n";
        for(int l=0;l<4 ;l++)
        {
            if(l!=emp)
            {F[l]>>m[l];c[l]=1;}
        }

        while(1)
        {

            int j=findmin(m,4);
            if(m[j]>=900)break;
            F[emp]<<m[j]<<endl;
            cout<<m[j]<<" ";
            if(c[j]==s[j].size[t])m[j]=9999+m[j];
            else
            {F[j]>>m[j];c[j]++;}

        }
//        cout<<"running\n";

    }
    s[emp].size[t+1]=0;
    for(i=0;i<4;i++)
    {
        if(i!=emp)
        {
	//	cout<<"file is "<<i<<endl;
        s[i].partiton[t+1]=s[i].partiton[t]-s[k].partiton[t];
        if(s[i].partiton[t+1]>0)
        s[i].size[t+1]=s[i].size[t];
        else
        s[i].size[t+1]=0;
        s[emp].size[t+1]+=s[i].size[t];
        }
    }
    s[emp].partiton[t+1]=s[k].partiton[t];
     cout<<endl;
    for(i=0;i<4;i++)
    {
        for(int j=0;j<t+2;j++)
         cout<<s[i].partiton[j]<<"->"<<s[i].size[j]<<" ";
        cout<<endl;
    }
    F[k].close();
    F[emp].close();
    if(s[0].size[t+1]<68)
    polymerge(F,b,t+1,emp);
    else
    {
        for(i=0;i<4 && i!=emp&&i!=k;i++)
            F[i].close();return;
    }
    return ;
}

int main()
{
    fstream F[4];fstream f;
    char b[4][20];int i,ch,a[4];
    for(i=0;i<4;i++)
    {
        cout<<"Enter file name:";
        cin>>b[i];
        F[i].open(b[i],ios::out);
    }
    f.open("d2.txt",ios::out);
    int z=1;int x=68;
    for(i=1;i<=34;i++)
    {
        f<<z<<" "<<x<<" ";z++;x--;
    }
    f<<-1;
    f.close();
    f.open("d2.txt",ios::in);
    int h=0;int j=0;
    while(!f.eof())
    {

        i=0;
        while(i<4 && !f.eof())
        {
    	f>>ch;
    	if(ch==-1)break;
        a[i]=ch;
//		cout<<ch<<endl;
        i++;
        }
        sort(a,i);
        for(int k=0;k<i;k++)
        {
            if(k!=0)cout<<" ";
            if(j<7)
                h=0;
            if(j>=7 && j<13)
                h=1;
            else if(j>=13)
                h=2;
            F[h]<<a[k]<<endl;
//            cout<<a[k];
        }
 //       cout<<endl;
          j++;
          if(ch==-1)break;
    }

    s[0].partiton[0]=7;s[0].size[0]=4;
    s[1].partiton[0]=6;s[1].size[0]=4;
    s[2].partiton[0]=4;s[2].size[0]=4;
    s[3].partiton[0]=0;s[3].size[0]=0;
    for(i=0;i<4;i++)
        F[i].close();
    polymerge(F,b,0,0);
return 0;
}
