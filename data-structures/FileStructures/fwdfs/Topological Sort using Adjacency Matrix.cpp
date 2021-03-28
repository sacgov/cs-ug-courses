#include <iostream>
#include <string>
using namespace std;

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

void TopoPrint(int **a, int n, int *inCount, bool* isVisited, string s)
{
	for(int i=0;i<n;i++)
	{
		if(inCount[i] == 0 && isVisited[i]==false)
		{
			s.append(1,char(i+49));
			isVisited[i] = true;

			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
					inCount[j]--;
			}

			TopoPrint(a,n,inCount,isVisited,s);
			if(s.length()==n)
				cout<<s<<endl;


			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
					inCount[j]++;
			}

			s.erase(s.length()-1,1);
			isVisited[i] = false;
		}													
	}
}

void TopoSort(int **a, int n)
{
	int *inCount = new int[n];

	for(int i=0;i<n;i++)
	{
		inCount[i] = 0;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]==1)
				inCount[i]++;
		}
	}


	cout<<"Possible Orders: \n";
	string s = "";

	bool *isVisited = new bool[n];
	for(int i=0;i<n;i++)
	{
		isVisited[i] = false;
	}
	TopoPrint(a,n,inCount,isVisited,s);
}

int main()
{
	int n, x, y;
	cout<<"Enter number of vertices: ";
	cin>>n;
	
	int **adjacencyMatrix = new int*[n];
	for(int i=0;i<n;i++)
	{
		adjacencyMatrix[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			adjacencyMatrix[i][j] = 0;
		}
	}

	cout<<"Enter edges(a b): ";
	while(1)
	{
		cin>>x;
		if(x<0)
			break;
		cin>>y;
		adjacencyMatrix[x-1][y-1] = 1;
	}

	cout<<"Adjacency Matrix: \n";
	display(adjacencyMatrix,n);

	TopoSort(adjacencyMatrix,n);
}