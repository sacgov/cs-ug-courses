#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void unpack(fstream & f)
{
	string s;
	getline(f,s);
	for(int i=0; i<s.length(); i++)
	{
		string s1="";
		while(s[i]!='|' && s[i]!='#')
		{
			s1+=s[i];
			i++;
		}
		cout<<s1<<endl;
	}
}
int main()
{
	fstream f1;
	f1.open("text.txt");
	unpack(f1);
	f1.close();
	return 0;
}
