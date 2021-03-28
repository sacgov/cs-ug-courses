/********************************************************
* Author        : Sachin Govind
* Date          : 05 February 2016 (Friday)
* Title         : remove left recursion
********************************************************/
// Info :  removes left factoring in the given production
//user_name github :bssachingovind


#include<iostream>
#include<string.h>
using namespace std;
char terminals[10];		//for terminals
string prods[10];      //for productions
string alpha;  			//for alpha is produtions after removinf=g common
string beta[20]; 		//for betas ie which dont have anything in common
string gamma[20];		
string dpr[50];
int bi=0,gi=0;
int index=0;
char curTerm='A';        //starts with 'A'
int break_prod(string prod);  //breaks input productions at '|' symbol to form separate strings
int find_alpha(int p);
void find_betagamma(int p);

//print the productions
void print(){
        for(int i=0;i<index;i++){
                cout<<terminals[i]<<"->"<<prods[i]<<endl;
        }
}
//check for alphas and beta in productions
void check(string prod){
        int p=break_prod(prod);
        if(find_alpha(p)) find_betagamma(p);
        else {
                print();
        }
}

//current terminal are added to terminals array and a new production for factoring are done
void calculate_prod(){
        terminals[index]=curTerm++;
        prods[index]=alpha+curTerm+"|";
        for(int i=0;i<gi;i++){
                prods[index]+=gamma[i];
                prods[index]+="|";
        }
        index++;
        terminals[index]=curTerm;
        prods[index]="";
       for(int i=0;i<bi;i++){
        prods[index]+=beta[i];
        prods[index]+="|";
        }
        check(prods[index++]);
}

//extract beta gamma
void find_betagamma(int p){
        bi=0;gi=0;
        for(int i=0;i<p;i++){
                string str=dpr[i].substr(0,alpha.length());
                if(str==alpha) {
                        beta[bi++]=dpr[i].substr(alpha.length(),dpr[i].length());
                }
                else gamma[gi++]=dpr[i];
        }

        calculate_prod();
}

//finds the alpha terms in grammar
int find_alpha(int p){
        alpha="";
        int maps[dpr[0].length()];
        int count=0;
        for(int i=0;i<dpr[0].length();i++){
                alpha=dpr[0].substr(0,(i+1));
                count=0;
                for(int j=0;j<p;j++){
                        string str=dpr[j].substr(0,(i+1));
                        if(str==alpha) count++;
                }
                maps[i]=count;
        }
        int max=maps[0];int ind=0;
        for(int i=1;i<dpr[0].length();i++){
                if(maps[i]>=max){
                        max=maps[i];
                        ind=i;
                }
        }
        alpha=dpr[0].substr(0,(ind+1));
        if(max>1){
        return 1;
        }
        else return 0;
}

//break entered multi prodution to single strings by breaking at '|'
int break_prod(string prod){
        int i;
    int p=0;
    while(prod.length())
    {
        i=prod.find("|");
        if(i>prod.length())
        {
            dpr[p++] = prod;
            prod="";
        }
        else
        {
            dpr[p++] = prod.substr(0,i);
            prod=prod.substr(i+1,prod.length());
        }
    }
        return p;
}
int main(){
        string prod;
        		cout<<"To test enter the production on screen or enter your own\n"<<endl;
        		cout<<"productions for a are : abNd|abNe|abd|d";
                cout<<"\nproduction will be left factored \nA->";
                cin>>prod;
                int p=  break_prod(prod);
                cout<<"\nprodutions after left factoring are :\n";
                if(find_alpha(p)) find_betagamma(p);
                else {
                        terminals[index]=curTerm++;
                        prods[index++]=prod;
                        print();
                }
        return 0;
}

