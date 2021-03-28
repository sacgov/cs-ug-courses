#include<iostream>
using namespace std;
struct avlnode
{
	avlnode *lchild;
	int data;
	avlnode *rchild;
};
typedef avlnode *avlptr;
int hite(avlptr H)
{
	if(H=='\0')
	return(-1);
	else
	return(max(hite(H->lchild),hite(H->rchild))+1);
}
void LLR(avlptr &H,avlptr k1,avlptr k2)
{
	H->lchild=k1->rchild;
	k1->rchild=H;
	H=k1;
}
void RRR(avlptr &H,avlptr k1,avlptr k2)
{
	H->rchild=k1->lchild;
	k1->lchild=H;
	H=k1;
}
void RLR(avlptr &H,avlptr k1,avlptr k2)
{
	H->rchild=k2->lchild;
	k1->lchild=k2->rchild;
	k2->lchild=H;
	k2->rchild=k1;
	H=k2;
}
void LRR(avlptr &H,avlptr k1,avlptr k2)
{
	k1->rchild=k2->lchild;
	H->lchild=k2->rchild;
	k2->lchild=k1;
	k2->rchild=H;
	H=k2;
}
void insert(avlptr &H,int k)
{
	avlptr k1,k2;
	if(H=='\0')
	{
		H=new avlnode;
		H->lchild='\0';
		H->data=k;
		H->rchild='\0';
	}
	else if(k<H->data)
	{
		insert(H->lchild,k);
		if(hite(H->lchild)-hite(H->rchild)==2)
		{
			k1=H->lchild;
			if(hite(k1->lchild)>hite(k1->rchild))
			{
				k2=k1->lchild;
				LLR(H,k1,k2);
			}
			else
			{
				k2=k1->rchild;
				LRR(H,k1,k2);
			}
		}
	}
	else if(k>H->data)
	{
		insert(H->rchild,k);
		if(hite(H->rchild)-hite(H->lchild)==2)
		{
			k1=H->rchild;
			if(hite(k1->lchild)<hite(k1->rchild))
			{
				k2=k1->rchild;
				RRR(H,k1,k2);
			}
			else
			{
				k2=k1->lchild;
				RLR(H,k1,k2);
			}
		}
	}
}
void preorder(avlptr T)
{
	if(T!='\0')
	{
		cout<<T->data<<"\t";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void inorder(avlptr T)
{
	if(T!='\0')
	{
		inorder(T->lchild);
		cout<<T->data<<"\t";
		inorder(T->rchild);
	}
}
void postorder(avlptr T)
{
	if(T!='\0')
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data<<"\t";
	}
}
avlptr LRS(avlptr T)
{
	if(T!='\0')
	{
		if(T->lchild=='\0')
		return(T);
		else
		LRS(T->lchild);
	}
	else
	{
		avlptr t;
		t='\0';
		return(t);
	}
}
avlptr RLS(avlptr T)
{
	if(T!='\0')
	{
		if(T->rchild=='\0')
		return(T);
		else
		RLS(T->rchild);
	}
	else
	{
		avlptr t;
		t='\0';
		return(t);
	}
}
void del(avlptr &T,int k)
{
	if(T!='\0')
	{
		avlptr T1,T2;
		if(T->data==k)
		{
			T1=LRS(T->rchild);
			T2=RLS(T->lchild);
			if(T1=='\0'&&T2=='\0')
			{
				T='\0';
			}
			if(T1=='\0'&&T2!='\0')
			{
				int t;
				t=T2->data;
				del(T,T2->data);
				T->data=t;	
			}
			if(T2=='\0'&&T1!='\0')
			{
				int t;
				t=T1->data;
				del(T,T1->data);
				T->data=t;
			}
			if(T1!='\0'&&T2!='\0')
			{
				int n;
				cout<<"cout enter 1 to have "<<T1->data<<" at deleted place ,enter 2 for"<<T2->data<<" at deleted place ";
				cin>>n;
				if(n==1)
				{
					int k=T1->data;
					del(T,T1->data);
					T->data=k;
				}
				else
				{
					int k=T2->data;
					del(T,T2->data);
					T->data=k;
				}
			}
		}
		else
		{
			avlptr k1,k2;
			if(k<T->data)
			{
				del(T->lchild,k);
				if(hite(T->rchild)-hite(T->lchild)==2)
				{
					k1=T->rchild;
					if(hite(k1->rchild)-hite(k1->lchild))						
					{
						k2=k1->rchild;
						RRR(T,k1,k2);
					}
					else
					{
						k2=k1->lchild;							
						RLR(T,k1,k2);
					}
				}
				if(hite(T->lchild)-hite(T->rchild)==2)
				{
					k1=T->lchild;
					if(hite(k1->lchild)>hite(k1->rchild))
					{
						k2=k1->lchild;
						LLR(T,k1,k2);
					}
					else
					{
						k2=k1->rchild;
						LRR(T,k1,k2);
					}
				}	
			}
			else
			{
				del(T->rchild,k);
				if(hite(T->lchild)-hite(T->rchild)==2)
				{
					k1=T->lchild;
					if(hite(k1->lchild)>hite(k1->rchild))
					{
						k2=k1->lchild;
						LLR(T,k1,k2);
					}
					else
					{
						k2=k1->rchild;
						LRR(T,k1,k2);
					}
				}
				if(hite(T->rchild)-hite(T->lchild)==2)
				{
					k1=T->rchild;
					if(hite(k1->rchild)-hite(k1->lchild))						
					{
						k2=k1->rchild;
						RRR(T,k1,k2);
					}
					else
					{
						k2=k1->lchild;							
						RLR(T,k1,k2);
					}
				}					
			}
		}
	}
}
int main()
{
	int i=1,k;
	avlptr H;
	H='\0';
	while(i==1)
	{
		cout<<"enter element to be added to avl tree ";
		cin>>k;
		insert(H,k);
		cout<<"enter 1 to continue 0 to exit ";
		cin>>i;
	}
	cout<<endl;
	preorder(H);
	cout<<endl;
	inorder(H);
	cout<<endl;
	postorder(H);
	cout<<endl;
	i=1;
	while(i==1)
	{
		cout<<"enter element which u need to delete ";
		cin>>k;
		del(H,k);
		cout<<endl;
		preorder(H);
		cout<<endl;
		inorder(H);
		cout<<endl;
		postorder(H);
		cout<<endl;
		cout<<"enter 1 to continue deleting and 0 to stop ";
		cin>>i;
	}
	return(0);
}
