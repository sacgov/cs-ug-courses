#include <iostream>
using namespace std;

int points = 0;

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

int findParent(int **a, int e, int k)
{
	for(int i=0;i<e;i++)
	{
		if(a[i][k]==1)
			return i;
	}
	return -1;
}

void findPoints(int **a, int e)
{
	bool *isVisited = new bool[e];
	for(int i=0;i<e;i++)
	{
		isVisited[i] = false;
	}

	cout<<"Bi-connected components:\n";
	
	for(int i=0;i<e;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(a[i][j]==2)
			{
				int curr = i;
				cout<<"{ ";
				while(curr != j)
				{
					isVisited[curr] = true;
					cout<<curr+1<<"  ";
					curr = findParent(a, e, curr);
				}
				cout<<j+1;
				cout<<" }\n";
				isVisited[j] = true;
			}
		}
	}
	for(int i=0;i<e;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(a[i][j] == 1)
			{
				if(isVisited[i] == false)
					cout<<"{ "<<i+1<<" "<<j+1<<" }"<<endl;
				else if(isVisited[j] == false)
					cout<<"{ "<<i+1<<" "<<j+1<<" }"<<endl;
			}
		}
	}
}

void findArticulationPoints(bool **matrix, int e)
{

	int **articulationMatrix = new int*[e];
	int *num = new int[e];
	int *low = new int[e];
	for(int i=0;i<e;i++)
	{
		num[i] = -1;
		low[i] = e;
		articulationMatrix[i] = new int[e];
		for(int j=0;j<e;j++)
		{
			articulationMatrix[i][j] = 0;
		}
	}

	int count =1;
	int k=0;
	assignNum(matrix, e, articulationMatrix, num, k, count);
	
	for(int i=0;i<e;i++)
	{
		low[i] = calLow(matrix, e, articulationMatrix, num, low, i);	
	}
	
	findPoints(articulationMatrix, e);

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
