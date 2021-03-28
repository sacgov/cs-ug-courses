#include <iostream>
#include <fstream>
using namespace std;

ifstream in("graph.txt");

void display(int **a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}

struct bstNode{
	int data;
	int from;
	int to;
	bstNode* lChild;
	bstNode* rChild;

	bstNode()
	{
		lChild = rChild= NULL;
	}
};

bstNode* addTree(bstNode* &t, int k, int f,int d)
{
	if(t == NULL)
	{
		t = new bstNode;
		t->data = k;
		t->from = f;
		t->to = d;
	}
	else if(t->data>k)
    {
        addTree(t->lChild,k,f,d);
    }
    else
    {
        addTree(t->rChild,k,f,d);
    }
}

void getMinimum(bstNode* t,bstNode &temp)
{
    while(t->lChild!=NULL)
    {
        t = t->lChild;
    }
    temp.data = t->data;
    temp.from = t->from;
    temp.to = t->to;
}

void remove(bstNode* &t, int k)
{
    if(t==NULL)
    {
        return;
    }
    else if(t->data>k)
    {
        remove(t->lChild,k);
    }
    else if(t->data<k)
        remove(t->rChild,k);
    else
    {
        if(t->lChild==NULL&&t->rChild==NULL)
            t = NULL;
        else if(t->lChild==NULL)
            t = t->rChild;
        else if(t->rChild==NULL)
            t = t->lChild;
        else
        {
            bstNode* a = t;
            a = a->lChild;
            while(a->rChild!=NULL)
            {
                a = a->rChild;
            }
            t->data = a->data;
            remove(t->lChild,t->data);
        }
    }
}

void print(bstNode* T)
{
    if(T!=NULL)
    {
        print(T->lChild);
        cout<<T->data<<"\t";
        print(T->rChild);
    }
}


void findPath(int **weightedMatrix, int n)
{
	int source = 0;
	
	bstNode* root = NULL;
	bool *isVisited = new bool[n];
	
	int total = 0;
	for(int i=0;i<n;i++)
	{
		isVisited[i] = false;
	}

	int **treeMatrix = new int*[n];
	for(int i=0;i<n;i++)
	{
		treeMatrix[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			treeMatrix[i][j] = 0;
		}
	}

	int current = source;
	int count = 0;
	bstNode temp;

	while( count != n-1 )
	{
		count++;
	
		isVisited[current] = true;
	
		for(int i=0;i<n;i++)
		{
			if((isVisited[i]==false) && (weightedMatrix[current][i]>0))
			{
				addTree(root,weightedMatrix[current][i],current,i);
			}
		}
		
		do
		{
			getMinimum(root,temp);
			remove(root,temp.data);
		}while(isVisited[temp.to]==true);
	
		treeMatrix[temp.from][temp.to] = temp.data;
		treeMatrix[temp.to][temp.from] = temp.data;
		total = total + temp.data;
		current = temp.to;
	}
	cout<<"\n\nTree Matrix:\n";
	display(treeMatrix,n);
	cout<<endl;
	cout<<"Total cost: "<<total;
}

int main()
{
	int n, x, y,z;
	cout<<"Enter number of edges: ";
	in>>n;
	
	int **weightedMatrix = new int*[n];
	for(int i=0;i<n;i++)
	{
		weightedMatrix[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			weightedMatrix[i][j] = 0;
		}
	}

	cout<<"Enter edges(a b): ";
	while(1)
	{
		in>>x;
		if(x<0)
			break;
		in>>y;
		in>>z;
		weightedMatrix[x-1][y-1] = z;
		weightedMatrix[y-1][x-1] = z;
	}

	cout<<"weighted Matrix: \n";
	display(weightedMatrix,n);

	findPath(weightedMatrix,n);
}