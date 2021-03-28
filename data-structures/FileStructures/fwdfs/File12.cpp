#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct Student{
    char rollNo[7];
    char name[16];
};

struct RollNos{
    char name[16];
    int nos;
    int records[10];
};

void pack(ofstream& out,Student& s)
{
    out<<s.rollNo<<"|"<<s.name<<"#";
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

        tag++;
    }
}

void update(RollNos *rec, int count, Student s, int recNo)
{
    int flag =0;
    int i = 0;
    for(i=0;i<count;i++)
    {
        if(rec[i].nos == 0)
            break;
        if(strcmp(rec[i].name,s.name)==0)
        {
            rec[i].records[rec[i].nos] = recNo;
            rec[i].nos++;
            flag =1;
        }
    }
    if(flag==0)
    {
        strcpy(rec[i].name,s.name);
        rec[i].records[rec[i].nos] = recNo;
        rec[i].nos++;
    }
}

int main()
{
    Student s;
    ofstream out;
    out.open("Var12.txt");
    char check;
    int count=0;
    cout<<"Enter student details: \n";

    do{
        cout<<"Enter roll number: ";
        cin.getline(s.rollNo,6);
        cout<<"Enter name: ";
        cin.getline(s.name,15);
        pack(out,s);
        count++;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y');

    out.close();
    ofstream out2;
    out2.open("RollNo12.txt");

    ifstream in;
    in.open("Var12.txt");
    string buffer;

    RollNos *rec = new RollNos[count];

    for(int i=0;i<count;i++)
    {
        rec[i].nos = 0;
    }

    int recNo=1;
    while(!in.eof())
    {
        getline(in,buffer,'#');
        if((buffer.length())<2)
            break;
        unpack(buffer,s);
        update(rec,count,s,recNo);
        recNo++;
    }

    for(int i=0;i<count;i++)
    {
        if(rec[i].nos==0)
            break;
        for(int j=0;j<rec[i].nos;j++)
            out2<<rec[i].records[j]<<",";
        out2<<"|";
    }

    out2.close();
    in.close();

    return 0;
}
