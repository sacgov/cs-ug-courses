#include <iostream>
using namespace std;

void display(int **a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void display(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}

void assignNum(bool **matrix, int e, int **am, int *num, int k, int &count)
{
	num[k] = count++;
	for(int i=0;i<e;i++)
	{
		if(matrix[k][i] == true)
		{
			if(num[i] == -1)
			{
				am[k][i] = 1;
				assignNum(matrix, e, am, num, i, count);
			}
			else if(am[i][k] == 0)
			{
				am[k][i] = 2;
			}
		}
	}
}
int min(int a, int b, int c)
{
	int min = a<b ? a: b;
	min = min<c ? min : c;

	return min;
}

int calLow(bool **matrix, int e, int **am, int *num, int *low, int i)
{
	int childMin = e;
	int backMin = e;

	for(int j=0;j<e;j++)
	{
		if((am[i][j]==1) && (childMin > calLow(matrix, e, am, num, low, j)))
		{
			childMin = calLow(matrix, e, am, num, low, j);
		}
		
		if((am[i][j]==2) && (backMin > num[j]))
		{
			backMin = num[j];
		}
	}

	return min(num[i],childMin,backMin);
}

void findPoints(bool **matrix, int e, int *low, int *num, int start, bool root, bool *artiPoint)
{
	cout<<"\nArticulation Points: ";
	for(int i=0;i<e;i++)
	{
		for(int j=0;j<e;j++)
		{
			if((matrix[i][j]==true) && (low[j]>=num[i]))
			{
				if(i!=start)
				{
					artiPoint[i] = true;
					cout<<i+1<<"   ";
					break;
				}
				else if(root)
				{
					artiPoint[i] = true;
					cout<<i+1<<"   ";
					break;
				}
			}
		}
	}
	cout<<endl;
}
void printTreeEdges(int **a, int e)
{
	cout<<"Tree Edges:\n";
	for(int i=0;i<e;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(a[i][j]==1)
				cout<<i+1<<" - "<<j+1<<endl;
		}
	}
}

void printBackEdges(int **a, int e)
{
	cout<<"Back Edges:\n";
	for(int i=0;i<e;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(a[i][j]==2)
				cout<<i+1<<" - "<<j+1<<endl;
		}
	}
}
int findBackEdge(int **a, int e, int k)
{
	for(int i=0;i<e;i++)
	{
		if(a[k][i] == 2)
			return i;
	}
	return -1;
}
int findParent(int **a, int e, int k)
{
	for(int i=0;i<e;i++)
	{
		if(a[i][k] == 1)
			return i;
	}
	return -1;
}


void printMinimumEdges(int **a, int e, int *low, bool *artiPoint)
{
	cout<<"Edges required to make graph bi-connected:\n";
	for(int i=0;i<e;i++)
	{
		if(artiPoint[i] == true)
		{
			for(int j=0;j<e;j++)
			{
				if((a[i][j]>0) && (low[j] > low[i]))
				{
					if(findBackEdge(a,e,i) >= 0)
					{
						cout<<findBackEdge(a,e,i)+1<<" - "<<j+1<<endl;
					
					}
					else if(findParent(a,e,i) >= 0)
					{
						cout<<findParent(a,e,i)+1<<" - "<<j+1<<endl;
					
					}
				}
			}
		}
	}
}

void findArticulationPoints(bool **matrix, int e)
{

	int **articulationMatrix = new int*[e];
	int *num = new int[e];
	int *low = new int[e];
	bool *artiPoint = new bool[e];
	for(int i=0;i<e;i++)
	{
		num[i] = -1;
		low[i] = e;
		artiPoint[i] = false;
		articulationMatrix[i] = new int[e];
		for(int j=0;j<e;j++)
		{
			articulationMatrix[i][j] = 0;
		}
	}

	int k;
	cout<<"Enter starting point: ";
	cin>>k;
	k--;

	int count =1;

	assignNum(matrix, e, articulationMatrix, num, k, count);
	display(articulationMatrix, e);
	display(num, e);

	for(int i=0;i<e;i++)
	{
		low[i] = calLow(matrix, e, articulationMatrix, num, low, i);	
	}
	cout<<endl;
	display(low, e);
	
	count = 0;
	for(int i=0;i<e;i++)
	{
		if(articulationMatrix[k][i] == 1)
			count++;
	}

	findPoints(matrix, e, low, num, k, count>1, artiPoint);

	printTreeEdges(articulationMatrix, e);
	printBackEdges(articulationMatrix, e);
	printMinimumEdges(articulationMatrix, e, low, artiPoint);

}

int main()
{
	int e,a,b;
	bool **matrix;

	cout<<"Enter number of edges: ";
	cin>>e;

	matrix = new bool*[e];
	for(int i=0;i<e;i++)
	{
		matrix[i] = new bool[e];
		for(int j=0;j<e;j++)
		{
			matrix[i][j] = false;
		}
	}

	cout<<"Enter edges(a b):\n";
	while(1)
	{
		cin>>a;
		if(a<0)
			break;

		cin>>b;
		matrix[a-1][b-1] = true;
		matrix[b-1][a-1] = true;
	}

	findArticulationPoints(matrix,e);

}
