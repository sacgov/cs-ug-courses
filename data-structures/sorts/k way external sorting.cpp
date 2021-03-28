#include<iostream>
#include<fstream>
using namespace std;

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
    {j=i;
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
int complete(int flag[],int k)
{
    for(int i=0;i<k;i++)
        if(flag[i]==0)return 1;

    return 0;
}
void merge(fstream A[],fstream B[],char* N[20],int tag,int s,int k,int count)
{
    cout<<"\n\nentered\n\n";

    if(tag==0)
    {
        for(int i=0;i<2*k;i++)
        {
        if(i<k)
        A[i].open(N[i],ios::in);
        else
        B[i-k].open(N[i-k],ios::out);
        }
    }
    else if(tag==1)
    {
        for(int i=0;i<2*k;i++)
       {
        if(i<k)
        B[i].open(N[i],ios::out);
        else
        A[i-k].open(N[i-k],ios::in);

       }

    }
    int emp=0;int ch;
    int *m=new int[k];
    int *c=new int[k];
    int *flag=new int[k];
    for(int i=0;i<k;i++)
    {
        flag[i]=0;
    }
    while(complete(flag,k))
    {
        cout<<"starting\n";
        for(int l=0;l<k;l++)
        {
            if(flag[l]==0)
            {A[l]>>m[l];
            if(m[l]==-1){m[l]=9999;flag[l]=1;}
            c[l]=1;
            }
        }
        while(1)
        {
            int j=findmin(m,k);
            if(m[j]>=900)break;
            B[emp%k]<<m[j]<<endl;
            cout<<m[j]<<endl;
            if(c[j]==s*k)m[j]=9999+m[j];
            else
            {
                if(flag[j]==0)
                {A[j]>>m[j];
                if(m[j]==-1){m[j]=9999;flag[j]=1;}
                c[j]++;
                }
            }

        }
        cout<<"running\n";
        emp++;
    }
    ch=-1;
    for(int i=0;i<k;i++)
    {
        B[i]<<ch;
        A[i].close();
        B[i].close();
    }
    if(s*k>count)return;
    merge(B,A,N,(tag+1)%2,s*k,k,count);
    return ;
}

int main()
{
    fstream f;int i,k,s,ch;
    fstream* A;fstream* B;
    cout<<"Enter k:\n";
    cin>>k;
    cout<<"Enter s:\n";
    cin>>s;
    int* a=new int[s];
    A=new fstream[k];
    B=new fstream[k];
    char** N=new char*[2*k];
    for(i=0;i<2*k;i++)
    {
        N[i]=new char[20];
        cout<<"Enter file name:\n";
        cin>>N[i];
        if(i<k)
        A[i].open(N[i],ios::out);
        else
        B[i-k].open(N[i],ios::out);
    }
     /* f.open("data.txt",ios::out);int N;
   cout<<"Enter no.of elements:\n";
  cin>>N;
    while(N>0)
   {
    cout<<"Enter number:";
    cin>>b;
    if(b!=-1)
    f<<b<<" ";
    N--;
   }
   b=-1;
   f<<b;
   f.close();*/
   f.open("data.txt",ios::in);
    int j=0;int count=0;
    while(!f.eof())
    {

        i=0;
        while(i<s && !f.eof())
        {
    	f>>ch;
    	if(ch==-1)break;
        a[i]=ch;count++;
		cout<<ch<<endl;i++;
        }

        sort(a,i);
        cout<<"asdlas\n";
        for(int k=0;k<i;k++)
        {
            if(k!=0)cout<<" ";
            A[j%k]<<a[k]<<endl;
            cout<<a[k];
        }
        cout<<endl;
          j++;
          if(ch==-1)break;
    }
    ch=-1;
     f.close();
     for(i=0;i<k;i++)
   {
        if(i<k)
        {
            A[i]<<ch;
            A[i].close();
        }
        else
        {
            B[i-k]<<ch;
            B[i-k].close();
        }
   }
    merge(A,B,N,0,s,k,count);

return 0;
}

