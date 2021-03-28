/********************************************************
* Author         : Sachin Govind
* Date           : 22 January 2016 (Friday)
* Title          : lexical analyser in C
********************************************************/
// Info :  does the lexical anaysis of i/p C program
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int i=0,id=0,kw=0,num=0,op=0;
char keys[32][10]={"const","auto","break","case","char","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
void keyw(char* p){
        int k,flag=0;
        for(k=0;k<=31;k++){
                if(strcmp(keys[k],p)==0){
                        printf("%s is a keyword\n",p);
                        kw++;
                        flag=1;
                        break;
                }
        }
        if(flag==0){
                if(isdigit(p[0])){
                        printf("%s is a number\n",p);
                        num++;
                }
                else{
                        if(p[0]!='\0'){
                                printf("%s is an identifier\n",p);
                                id++;
                        }
                }
        }
        i=-1;
}
int main(){
        char ch,str[25],seps[15]="\t\n,;(){}[]#\"<>",oper[]="!%^&*-+=~|.<>?";
        int j;
        char fname[50];
        FILE *f1;
        printf("Enter file path : ");
        scanf("%s",fname);
        f1=fopen(fname,"r");
        if(f1==NULL){
                printf("File not found");
                exit(0);
        }
        while((ch=fgetc(f1))!=EOF){
                for(j=0;j<=14;j++){
                        if(ch==oper[j]){
                                printf("%c is an operator\n",ch);
                                op++;
                                str[i]='\0';
                                keyw(str);
                        }
                }
                for(j=0;j<=14;j++){
                        if(i==-1) break;
                        if(ch==seps[j]){
                                if(ch=='#'){
                                        while(ch!='>'){
                                                printf("%c",ch);
                                                ch=fgetc(f1);
                                        }
                                        printf("%c is a header file\n",ch);
                                        i=-1;
                                        break;
                                }
                                if(ch=='"'){
                                        do{
                                                ch=fgetc(f1);
                                                printf("%c",ch);
                                        }while(ch!='"');
                                        printf("\b is an argument\n");
                                        i=-1;
                                        break;
                                }
                                str[i]='\0';
                                keyw(str);
                        }
                }
                if(i!=-1){
                        str[i]=ch;
                        i++;
                }
                else i=0;
        }
        printf("Keywords:       %d\nIdentifiers:        %d\nOperators:  %d\nNumbers:    %d\n",kw,id,op,num);
}

