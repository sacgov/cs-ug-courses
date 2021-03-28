#include <iostream>
using namespace std;
class extendible
{
      struct bucket
      {
             int data[10];
             int size;
             int d;
             bucket()
             {
                     size=0;
                     d=0;
             }
             bucket(int x)
             {
                        size=0;
                        d=x;
	         }
	};
      bucket* list[128];
      int depth;
      public:
      extendible()
      {
          depth=0;
          list[0]= new bucket;
          for(int i=1;i<100;i++)
          list[i]=NULL;
      }
      int hash(int x)
      {
          return((x%100)>>(7-depth));
      }0
      void insert(int x)
      {
           int pos=hash(x);
           bucket *p=list[pos];
           if(p->size==10)
           {
                 split(pos);
                 insert(x);
           }
           else
             p->data[p->size++]=x;
      }
      void split(int pos)
      {
           bucket* t=list[pos];
           bucket *p=new bucket(t->d+1);
           if(t->d==depth)
             expand();
           int first,last;
           first=pos;
           last=first+(1<<(depth-t->d))-1;
           first=first+((last-first+1)/2);
           for(int i=first;i<=last;i++)
             list[i]=p;
           for(int i=0;i<t->size;i++)
           {
               if(hash(t->data[i])>=first )//&& hash(t->data[i]<=last))
               {
                   p->data[p->size++]=t->data[i];
                   t->data[i]=t->data[--t->size];
                   i--;
               }
           }
           t->d++;
      }
      void expand()
       {
	    for(int i=(1<<depth)-1;i>=0;i--)
           {
                 list[2*i+1]=list[i];
                 list[2*i]=list[i];
           }
           depth++;

      }
      void display()
      {
           int k=1;
           for(int i=0;i<(1<<depth);i++)
           {
                   cout<<endl<<"Bucket"<<k<<endl;
                   for(int j=0;j<list[i]->size;j++)
                    cout<<list[i]->data[j]<<" ";
                   while(list[i+1]==list[i])
                     i++;
                   k++;
           }
      }
};
 int main()
{
    extendible ext;
    int h;
    cout<<"enter the size needed ";
    cin>>h;
    for ( int i = 0; i < h; i++ )
    ext.insert(i);
    ext.display();
}
