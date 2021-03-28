#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct tnode;
union node
{
    tnode* a[4];
    char* l;
};
struct tnode
{
    int tag;
    node p;
};

int findptr(char new_key[],int i)
{
    if(new_key[i]=='\0')
        return 3;
    else
    {
        char k=new_key[i];
        return k-65;
    }
}
void retrieve(tnode* T,char new_key[])
{
    if(T==NULL)
        cout<<"Record not found\n";
    else
    {
        int i=0;int k=findptr(new_key,i);
        while(T->tag==1 && T->p.a[k]!=NULL)
        {
            T=T->p.a[k];
            i=i+1;
            k=findptr(new_key,i);
        }
        if(T==NULL)
           cout<<"Record not found\n";
        else
        {
            char* s=T->p.l;
            if(strcmp(s,new_key)!=0)
                 cout<<"Record not found\n";
            else
             {
                cout<<"Record found\n";
                cout<<s<<endl;
             }
        }
    }

}

void insert(tnode*& T,char new_key[])
{
    tnode *Z=T;
    int i;cout<<"kjh";
    if(T==NULL)
    {
        cout<<"entered\n";
        T=new tnode;
        T->tag=1;
        for(i=0;i<4;i++)
            T->p.a[i]=NULL;
        tnode *L=new tnode;
        L->tag=0;
        i=0;
        int k=findptr(new_key,i);
        T->p.a[k]=L;
        L->p.l=new_key;
        cout<<"adding finished\n";
        return ;
    }
    i=0;tnode *P=NULL;
    int k=findptr(new_key,i);
    if(T->p.a[k]!=NULL)
    cout<<"jhvcjb ";
    while(T->tag==1 && T->p.a[k]!=NULL)
    {
            P=T;
            T=T->p.a[k];
            i=i+1;
            k=findptr(new_key,i);
            if(k!=3)
            cout<<char(65+k)<<endl;
            else    cout<<"-"<<endl;
    }
    cout<<"jmhgi";
    if(T->tag==1&&T->p.a[k]==NULL)
    {
        cout<<"attached\n";
        T->p.a[k]=new tnode;
        T->p.a[k]->tag=0;
        T->p.a[k]->p.l=new_key;
        T=Z;
        return ;
    }

     if(!strcmp(T->p.l,new_key))
    {
        T=Z;
        cout<<"Duplicate record\n";return ;
    }
    char* data=T->p.l;
    tnode *save1=T;int v;
    tnode *save2=new tnode;
    for(v=0;v<4;v++)save2->p.a[v]=NULL;
    int j=min(strlen(new_key),strlen(data));
    cout<<j<<endl;
     i=i-1;
    while(i<j && data[i]==new_key[i])
    {
        tnode *Q=new tnode;
        for( v=0;v<4;v++)
            Q->p.a[v]=NULL;
        k=findptr(new_key,i);
        P->p.a[k]=Q;
        Q->tag=1;
        P=Q;
        i=i+1;
    }

        k=findptr(data,i);
        P->p.a[k]=save1;
        k=findptr(new_key,i);
        save2->tag=0;
        save2->p.l=new_key;
        P->p.a[k]=save2;
        T=Z;
        return ;

}

void cdelete(tnode*& T,tnode*& P,char del_key[],int i,int k)
{
    if(T->tag==0)
    {
        P->p.a[k]=NULL;
        return;
    }
    int c=k;int count=0;int ptr=0;
     k=findptr(del_key,i);
     if(T->tag==1 && T->p.a[k]!=NULL)
      {
        i=i+1;
        cdelete(T->p.a[k],T,del_key,i,k);
        for(int j=0;j<4;j++)
            if(T->p.a[j]!=NULL){count++;ptr=j;}
        if(P!=T && count==1)
        {

            P->p.a[c]=T->p.a[ptr];
        }
        return;
      }


}
void deletet(tnode*& T,char del_key[])
{
    tnode *Z=T;
    if(T==NULL)
        cout<<"Record not found\n";
    else
    {
        int i=0;int k=findptr(del_key,i);tnode *P=NULL;int j=k;
        while(T->tag==1 && T->p.a[k]!=NULL)
        {
            P=T;
            T=T->p.a[k];
            i=i+1;
            j=k;
            k=findptr(del_key,i);
        }
        if(T==NULL)
           cout<<"Record not found(NULL)\n";
        else
        {
            char* s=T->p.l;
            if(strcmp(s,del_key)!=0)
                 cout<<"Record not found\n";
            else
             {
                cout<<"Record found\n";
                cout<<s<<endl;
                P->p.a[j]=NULL;
                cout<<"Record deleted\n";
                T=Z;
                return ;
             }
        }
    }

}

void levelorder(tnode *T)
{
    cout<<"in level order\n";
    queue<tnode*> q;
    q.push(T);
     tnode* S;
     S=new tnode;
    S->tag=50;
    q.push(S);
    while(!q.empty()&& q.front()->tag!=50)
     {int i;
        while(q.front()->tag!=50)
        {
            T=q.front();
            q.pop();

             if(T->tag==1)
            {
                for(i=0;i<4;i++)
                {
                    if(T->p.a[i]!=NULL)
                    {
                        if(i!=3)
                        cout<<char(i+65)<<" ";
                        else cout<<"-"<<" ";
                        q.push(T->p.a[i]);
                    }
                }
            }
            else if(T->tag==0)
            {
                cout<<T->p.l<<" ";
            }

        }
        cout<<endl<<endl;
        T=q.front();
        q.pop();
        q.push(S);
    }
}


int main()
{
    tnode *T=NULL;char new_key[8][20];int k=8;
    while(k>0)
    {cout<<"enter the string";
    cin>>new_key[k-2];
    cout<<"going to insert";
    insert(T,new_key[k-2]);
    cout<<T->tag<<endl;
    levelorder(T);
    k--;
    }
   /* do
    {
        char* del_key=new char[20];
        cout<<"Enter record to be deleted\n";
        cin>>del_key;
        deletet(T,del_key);
        levelorder(T);
        cout<<"enter 1 or 0:";
        cin>>k;
        delete del_key;
    }while(k);
    */
    char del_key[20];
    cout<<"Enter record to be deleted\n";
    cin>>del_key;
    cdelete(T,T,del_key,0,0);
    levelorder(T);

return 0;
}
