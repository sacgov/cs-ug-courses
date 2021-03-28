#include<iostream>
#include<fstream>
using namespace std;
struct files
{
    int parts[10];
    int size[10];
}s[4];
int emp;
int flag[4];
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

int filemin(int k)
{
    int m=-1;
    for(int i=0;i<4;i++)
    {
        if(s[i].parts[k]==0 && s[i].size[k]==0) emp=i;
        if(m<0 && s[i].parts[k]!=0)
        {
            m=i;
        }
        else if(m>=0 && s[i].parts[k]!=0 && s[i].parts[k]<s[m].parts[k])
        {
            m=i;
        }
    }
 //   cout<<"emp is"<<emp<<endl;
      return m;
}

void print(int t)
{
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<t;j++)
            cout<<s[i].parts[j]<<"-"<<s[i].size[j]<<" ";
        cout<<endl;
    }
}

int search(int flag[],int i)
{
    if(flag[i]==0)return 1;
    else
        return 0;

}
void clear(int flag[])
{
    for(int i=0;i<4;i++)
        flag[i]=0;
}
void polymerge(fstream F[],char b[][20],int t,int cl)
{
    if(t%2==0)clear(flag);
//    cout<<"entered:\n";
    int k=filemin(t);int i;
//    cout<<"k is "<<k<<endl;
//    cout<<"emp is "<<emp<<endl;
    flag[emp]=1;

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
    for(i=0;i<4;i++)
    {
        if(!search(flag,i))
        m[i]=9999;
    }
    int c[4];
//    cout<<"parts is "<<s[k].parts[t]<<endl;
    for(i=0;i<s[k].parts[t];i++)
    {

//        cout<<"starting\n";
        for(int l=0;l<4 ;l++)
        {
            if(search(flag,l))
            {F[l]>>m[l];c[l]=1;}
        }

        while(1)
        {

            int j=findmin(m,4);
            if(m[j]>=900)break;
            F[emp]<<m[j]<<endl;
 //           cout<<m[j]<<endl;
            if(c[j]==s[j].size[t])m[j]=9999+m[j];
            else
            {F[j]>>m[j];c[j]++;}

        }
    }
    s[emp].size[t+1]=0;
    for(i=0;i<4;i++)
    {
        if(search(flag,i))
        {
//		cout<<"file is "<<i<<endl;
        s[i].parts[t+1]=s[i].parts[t]-s[k].parts[t];
        if(s[i].parts[t+1]>0)
        s[i].size[t+1]=s[i].size[t];
        else
        s[i].size[t+1]=0;
        s[emp].size[t+1]+=s[i].size[t];
        }
    }
    s[emp].parts[t+1]=s[k].parts[t];
    if(t%2==0)
    {
        s[emp].parts[t+2]=s[emp].parts[t+1];
        s[emp].size[t+2]=s[emp].size[t+1];
    }

 //    cout<<endl;
    for(i=0;i<4;i++)
    {
        for(int j=0;j<t+2;j++)
            cout<<s[i].parts[j]<<"-"<<s[i].size[j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    F[k].close();
    F[emp].close();
    if(t<6)
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
    char b[4][20];int i,ch;
    for(i=0;i<4;i++)
    {
//        cout<<"Enter file name:";
        cin>>b[i];
        F[i].open(b[i],ios::out);
    }
    f.open("cascadeinp.txt",ios::out);
    int z=1;int x=31;
    for(i=1;i<=15;i++)
    {
        f<<z<<" "<<x<<" ";  z++;x--;
    }
    f<<16<<" "<<-1;
    f.close();
    f.open("cascadeinp.txt",ios::in);
    int h=0;int j=0;int p=1;
    int* a=new int[p];
    while(!f.eof())
    {
        i=0;
        while(i<p && !f.eof())
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
            if(j<14)
                h=0;
            if(j>=14 && j<25)
                h=1;
            else if(j>=25)
                h=2;
            F[h]<<a[k]<<endl;
//            cout<<a[k];
        }
//        cout<<endl;
          j++;
          if(ch==-1)break;
    }
    s[0].parts[0]=14;s[0].size[0]=1;
    s[1].parts[0]=11;s[1].size[0]=1;
    s[2].parts[0]=6;s[2].size[0]=1;
    s[3].parts[0]=0;s[3].size[0]=0;
    for(i=0;i<4;i++)
    F[i].close();
    polymerge(F,b,0,0);
return 0;
}
