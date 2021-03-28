/********************************************************
* Author 	: Sachin Govind
* Date   	: 05 February 2016 (Friday)
* Title		: remove left recursion
********************************************************/
// Info :  removes left recursion in the given set of grammar productions
#include <iostream>
#include <string>
using namespace std;
string str[100][100];
int np;
void print()
{
	for(int i=0;i<np;i++)
	{cout<<endl;
	for(int j=0;j<10;j++)
		cout<<str[i][j]<<" ";
	}
	cout<<endl;
}
void skip_space()
{
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(str[i][j] == "")
			{
				for(int k = j;k<9;k++)
				{
					str[i][k] = str[i][k+1];
					str[i][k+1] = "";
				}
			}
		}
	}
}
int main()
{
	
	
	cout<<"enter the number of productions"<<endl;
	
	cin >> np;
	for(int i=0;i<np;i++)
	{
		string prod;
		cin>>prod;
		int p=1;
		int ind;
		str[i][0] =  prod.substr(0,prod.find("->"));
		prod = prod.substr(prod.find("->")+2, prod.length());
		while(prod.length())
    	{
    		
        	ind=prod.find("|");
        	if(ind>prod.length())
        	{
            	str[i][p++] = prod;
            	prod="";
        	}
        	else
        	{
            	str[i][p++] = prod.substr(0,ind);
            	prod=prod.substr(ind+1,prod.length());
        	}
    	}
	}	
	print();
	string comm ="";
	char c = 'M';
	for(int i=0;i<np;i++)
	{
		int fl =0;
		string q = str[i][0];
		for(int j=1;j<10;j++)
		{
			int ind2 =1;
			if(str[i][j].length()==0)
				break;
			if(str[i][j][0] == q[0])
			{
				str[i][j][0] = c;
				fl =1;
				str[np][ind2] +=str[i][j].substr(1,str[i][j].length());
				str[np][ind2] +=c;
				str[np][ind2] +=" ";
				ind2++;
				
			}
			
		}
		
		if(fl)
		{
			str[np][0] += c;
			np++;
			cout<<i;
			print();
			for(int j=1;j<10;j++)
			{
				if(str[i][j].length()==0)
					break;
				if(str[i][j][0] == c)
				{
				str[i][j] ="" ;
				}
				else
				str[i][j]+=c;
			
			}
			c++;
		}
		print();
	}

	
	skip_space();
	print();
}
/*
 4
 A->AU|AV|AW|B|BX|BT
 B->BB|BBA
 C->AC
 A->CA
 * */