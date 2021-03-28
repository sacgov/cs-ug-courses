#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct Student{
    char rollNo[7];
    char name[16];
    char state[4];
};

struct States{
    char st[4];
    int nos;
    char records[10][4];
};

void pack(ofstream& out,Student& s)
{
    out<<s.rollNo<<"|"<<s.name<<"|"<<s.state<<"#";
}

void unpack(string& buffer, Student& s)
{
    char temp[16];
    int j=0;
    int tag=0;
    for(int i=0;i<buffer.length();i++)
    {
        j=0;
        while(buffer[i]!='|'&&i<buffer.length())
        {
            temp[j++] = buffer[i++];
        }
        temp[j]='\0';

        if(tag==0)
            strcpy(s.rollNo,temp);
        else if(tag==1)
            strcpy(s.name,temp);
        else if(tag==2)
            strcpy(s.state,temp);

        tag++;
    }
}

void update(States *rec, int count, Student s)
{
    int flag =0;
    int i = 0;
    for(i=0;i<count;i++)
    {
        if(rec[i].nos ==0)
            break;
        if(strcmp(rec[i].st,s.state)==0)
        {
            strcpy(rec[i].records[rec[i].nos],s.rollNo);
            rec[i].nos++;
            flag =1;
        }
    }
    if(flag==0)
    {
        strcpy(rec[i].st,s.state);
        strcpy(rec[i].records[rec[i].nos],s.rollNo);
        rec[i].nos++;
    }
}

int main()
{
    Student s;
    ofstream out;
    out.open("Var13.txt");
    char check;
    int count=0;
    cout<<"Enter student details: \n";

    do{
        cout<<"Enter roll number: ";
        cin.getline(s.rollNo,6);
        cout<<"Enter name: ";
        cin.getline(s.name,15);
        cout<<"Enter state: ";
        cin.getline(s.state,4);
        pack(out,s);
        count++;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y');

    out.close();
    ofstream out2;
    out2.open("State13.txt");

    ifstream in;
    in.open("Var13.txt");
    string buffer;

    States *rec = new States[count];

    for(int i=0;i<count;i++)
    {
        rec[i].nos = 0;
    }

    while(!in.eof())
    {
        getline(in,buffer,'#');
        if((buffer.length())<2)
            break;
        unpack(buffer,s);
        update(rec,count,s);
    }

    for(int i=0;i<count;i++)
    {
        if(rec[i].nos==0)
            break;
        out2<<rec[i].st<<"\t";
        for(int j=0;j<rec[i].nos;j++)
            out2<<rec[i].records[j]<<",";
        out2<<endl;
    }

    out2.close();
    in.close();

    return 0;
}
