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


void merge(fstream A[],fstream B[],int tag,int s)
{
    cout<<"\n\nentered\n\n";

    if(tag==0)
    {int ch=0;
    A[0].open("a1.txt",ios::in);
    A[1].open("a2.txt",ios::in);
    B[0].open("b1.txt",ios::out|ios::trunc);
    B[1].open("b2.txt",ios::out|ios::trunc);
    }
    else if(tag==1)
    {
    A[0].open("b1.txt",ios::in);
    A[1].open("b2.txt",ios::in);
    B[0].open("a1.txt",ios::out|ios::trunc);
    B[1].open("a2.txt",ios::out|ios::trunc);
    cout<<"\ntagged2\n";
    }
    int p=0,q=0;
    int c=0;int k=2;int ch;int c1=0;int c2=0;
    cout<<"initiated\n";
            A[0]>>p;
            A[1]>>q;

    while(1)
    {
         if(c1<s && c2<s)
        {
            int m[2];
            m[0]=p;
            m[1]=q;

            if(p==-1)
            {
                while(1)
                {
                    ch=q;cout<<"jhgkj";
                    if(ch==-1)break;
                    B[c]<<ch<<endl;
                    cout<<ch<<endl;
                    A[1]>>q;
                }
                 break;
            }
            else if(q==-1)
            {
                while(1)
                {
                    ch=p;cout<<"jhgkj";
                    if(ch==-1)break;
                    B[c]<<ch<<endl;
                    cout<<ch<<endl;
                    A[0]>>p;
                }
                 break;
            }

        int t=findmin(m,2);
        B[c]<<m[t]<<endl;
        cout<<m[t]<<endl;
            if(t==0)
            {A[0]>>p;c1++;}
            else
            {A[1]>>q;c2++;}

        }
        else if(c1==s && c2<s)
        {
            ch=q;cout<<"ats";
        if(ch==-1)break;
        B[c]<<ch<<endl;
        cout<<ch<<endl;
        A[1]>>q;c2++;
        }
        else if(c2==s && c1<s)
        {
        ch=p;cout<<"kb";
        if(ch==-1)break;
        B[c]<<ch<<endl;
        cout<<ch<<endl;
        A[0]>>p;c1++;
        }
        else if(c1==s && c2==s)
        {
            cout<<"clear\n";
            c1=0;c2=0;c=(c+1)%2;
        }

    }

    ch=-1;
    B[0]<<ch;
    B[1]<<ch;
    for(int i=0;i<2;i++)
    {
        A[i].close();
        B[i].close();
    }
    if(s*2>30)return;
    merge(B,A,(tag+1)%2,s*k);
    return ;
}

int main()
{
    fstream f;int i;int a[4];
    fstream A[2];int b;
    fstream B[2];
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
    A[0].open("a1.txt",ios::out);
    A[1].open("a2.txt",ios::out);

    int j=0;int ch;
    while(!f.eof())
    {

        i=0;
        while(i<4 && !f.eof())
        {
    	f>>ch;
    	if(ch==-1)break;
        a[i]=ch;
		cout<<ch<<endl;i++;
        }

        sort(a,i);
        cout<<"asdlas\n";
        for(int k=0;k<i;k++)
        {
            if(k!=0)cout<<" ";
            A[j%2]<<a[k]<<endl;
            cout<<a[k];
        }
        cout<<endl;
          j++;
          if(ch==-1)break;
    }
    ch=-1;
    A[0]<<ch;
    A[1]<<ch;
    f.close();
    A[0].close();
    A[1].close();

    merge(A,B,0,4);
