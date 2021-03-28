#include<iostream> 
#include<fstream>
#include<cstring>
using namespace std;
class buffer{
public:
	char buf[1000];
	void pack(char[]);
	void unpack();
	
};
void buffer::pack(char c[]){
	strcat(buf,c);
	strcat(buf,"$");
}
void buffer::unpack(){
	int i=0;
	while(i<strlen(buf)){
		if(buf[i]!='$')
			cout<<buf[i];
		else
			cout<<" ";
		i++;
	}
}
union salary{
	char tmpsal[8];
	char permsal[12];
};
class employ{
public:
	char name[20],empno[4],child[30],childage[2],choice;
	int tag,num;
	salary sal;
};
void add(char c[]){
	int i=0;
	ofstream fout;
	fout.open("data.txt",ios::app);
	while(i<strlen(c)){
		fout<<c[i];
		i++;
	}
	fout.close();
}
void read(){
	ifstream fin;
	char c;
	fin.open("data.txt");
	fin>>c;
	while(!fin.eof()){
		if(c!='$')
			cout<<c;
		else
			cout<<" ";
		fin>>c;
		}
		fin.close(); 
	}
int main(){
	employ e;
	buffer buff;
	e.choice='y';
	while(e.choice=='y'||e.choice=='Y')
	{
	cout<<"Enter employ name:\t";
	cin>>e.name;
	buff.pack(e.name);
	cout<<"\nEnter employ number:\t";
	cin>>e.empno;
	buff.pack(e.empno);
	cout<<"Is employ a temporary(1) or permanent(2) one?\n";
	cin>>e.tag;
	if(e.tag==1){
		cout<<"Enter your salary:\t";
		cin>>e.sal.tmpsal;
		buff.pack(e.sal.tmpsal);
	}
	else if(e.tag==2){
		cout<<"Enter your payscale:\t";
		cin>>e.sal.permsal;
		buff.pack(e.sal.permsal);
	}
	cout<<"\nEnter the number of children employ has got?\t";
	cin>>e.num;
	cout<<"Enter name and age of each child\n";
	for(int i=0;i<e.num;i++){
		cin>>e.child;
		buff.pack(e.child);
		cin>>e.childage;
		buff.pack(e.childage);
	}
	
	char c,k;
	do
	{
		cout<<"Enter choice...(1).Add (2).Read \n";
	cin>>k;
		if(k=='1')add(buff.buf);
	else if(k=='2')read();
	else cout<<"wrong choice\n";
	cout<<"\ntry again yes or no!!\n";
	cin>>c;
	}
	while (c=='y'||c=='Y');
	cin>>e.choice;
}
buff.unpack();
	return 0;
}
