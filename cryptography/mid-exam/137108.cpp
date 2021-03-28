#include <iostream>
#include <string>
using namespace std;
int key[8];
int round_key[12];
void take_input_key()
{
	cout<<"Enter the 8 bit key in binary format"<<endl;
	string bin = "11011011";
	//cin>>bin;
	for(int i=0;i<8;i++)
	{
		key[i] = bin[i] - 48;
	}
	cout<<"The key entered is ";
	for(int i=0;i<8;i++)
		cout<<key[i];
	cout<<endl<<endl;
}

void apply_shift_key()
{
	int temp = key[0];
	for(int i=0;i<3;i++)
		key[i] = key[i+1];
	key[3] = key[0];
	temp = key[7];
	for(int i=7;i>4;i--)
		key[i] = key[i-1];
	key[4] = temp;
	cout<<"The key after left and right shifts is ";
	for(int i=0;i<8;i++)
		cout<<key[i];
	cout<<endl;

}
void apply_pc2_key()
{
	int exp[12] = {0,2,5,1,7,4,6,3,0,4,3,1};
	for(int i=0;i<12;i++)
		round_key[i] = key[exp[i]];
	cout<<"The key after expansion is ";
	for(int i=0;i<12;i++)
		cout<<round_key[i];
	cout<<endl<<endl;


}
int block1,block2;
int fb[16],sb[16];
void take_input_block()
{
	cout<<"enter the first block"<<endl;
	//cin>>block1;
	block1 = 11;
	cout<<"enter the second block"<<endl;
	//cin>>block2;
	block2 = 14;
	for(int i=0;i<15;i++)
	{
		fb[i] = 0;
		sb[i] = 0;

	}
	for(int i=15;i>=0;i--)
	{
		fb[i] = block1%2;
		block1 = block1/2;
		sb[i] = block2%2;
		block2 = block2/2;
	}
	cout<<"The first block of message is ";
	for(int i=0;i<16;i++)
		cout<<fb[i];
	cout<<endl;
	cout<<"second block of message is  ";
	for(int i=0;i<16;i++)
		cout<<sb[i];
	cout<<endl;


}

int c0[16],c1[16];
/*
void apply_ip()
{
	cout<<endl;
	int iv[16] = {1 ,4, 3, 2, 5,  8, 7, 6, 0, 11, 10, 12, 15, 14,9,13};
	for(int i=0;i<16;i++)
	{
		c01[i] = fb[iv[i]];
		c02[i] = sb[iv[i]];
	}
	cout<<"first block after initial permutaion"<<endl;
	for(int i=0;i<16;i++)
		cout << c01[i];
	cout<<endl;
	cout<<"second block after initial permutaion"<<endl;
	for(int i=0;i<16;i++)
		cout << c02[i];
	cout<<endl;
}
*/

void apply_xor(int *a,int *b,int size)
{

	for(int i=0;i<size;i++)
	{
		//cout<<a[i]<<b[i];
		//a[i] = 0;
		if(a[i] == 1 && b[i] == 0)
			a[i] = 1;
		else if(a[i] == 0 && b[i] == 1)
			a[i] = 1;
		else
			a[i] = 0;
		//cout<<a[i]<<endl;
	}
}
void calculate_c0()
{

	cout<<endl<<"*************Calculating C0 ******************"<<endl;
	int last[6];
	for(int i=0;i<6;i++)
		last[i] = fb[i+10];
	int first[10];
	for(int i=0;i<10;i++)
		first[i] = fb[i];

	//applying expansion
	int exp[12] = {0,2,5,1,5,4,2,3,0,4,3,1};
	int last_exp[12];
	for(int i=0;i<12;i++)
		last_exp[i] = last[exp[i]];

	cout<<"right part after expansion : ";
	for(int i=0;i<12;i++)
		cout<<last_exp[i];
	cout<<endl;
	//cout<<"The key after expansion is ";
	//for(int i=0;i<12;i++)
	//	cout<<round_key[i];
	//cout<<endl;

	//applying xor

	apply_xor(last_exp,round_key,12);

	cout<<"right part after xor : ";
	for(int i=0;i<12;i++)
		cout<<last_exp[i];
	cout<<endl;

	int sbox[10] = {2,3,5,6,7,8,9,4,11,10};
	for(int i=0;i<10;i++)
	{
		sbox[i] = last_exp[sbox[i]];
	}
	cout<<"right part after sbox and :";
	for(int i=0;i<10;i++)
		cout<<sbox[i];
	cout<<endl;

	apply_xor(sbox,first,10);
	//for(int i=0;i<10;i++)
	//	sbox[i] = sbox[i]^first[i];
	cout<<"right part after xor with left part :";
	for(int i=0;i<10;i++)
		cout<<sbox[i];
	cout<<endl;

	for(int i=0;i<6;i++)
		c0[i] = last[i];
	for(int i=0;i<10;i++)
		c0[i+6] = sbox[i];
	cout<<"final C0 is :";
		for(int i=0;i<16;i++)
			cout<<c0[i];
		cout<<endl;

	cout<<"Applying IV"<<endl;
	int iv[16] = {1 ,0, 1, 0, 0,  0, 1, 0, 0, 1, 1, 1, 1, 1,0,1};
	cout<<"*********   C0'  ***********"<<endl;
	int finalc0[16];
	for(int i=0;i<16;i++)
		finalc0[i] = c0[i] ^ iv[i];
	for(int i=0;i<16;i++)
		cout<<finalc0[i];
	
	cout<<endl<<endl;

}

void calculate_c1()
{

	cout<<endl<<"*************Calculating C1 ******************"<<endl;
	int last[6];
	for(int i=0;i<6;i++)
		last[i] = sb[i+10];
	int first[10];
	for(int i=0;i<10;i++)
		first[i] = sb[i];

	//applying expansion
	int exp[12] = {0,2,5,1,5,4,2,3,0,4,3,1};
	int last_exp[12];
	for(int i=0;i<12;i++)
		last_exp[i] = last[exp[i]];

	cout<<"right part after expansion :";
	for(int i=0;i<12;i++)
		cout<<last_exp[i];
	cout<<endl;
	//cout<<"The key after expansion is ";
	/*
	for(int i=0;i<12;i++)
		cout<<round_key[i];
	cout<<endl<<endl;
	*/
	//applying xor

	apply_xor(last_exp,round_key,12);

	cout<<"right part after xor :";
	for(int i=0;i<12;i++)
		cout<<last_exp[i];
	cout<<endl;

	int sbox[10] = {2,3,5,6,7,8,9,4,11,10};
	for(int i=0;i<10;i++)
	{
		sbox[i] = last_exp[sbox[i]];
	}
	cout<<"right part after sbox and :";
	for(int i=0;i<10;i++)
		cout<<sbox[i];
	cout<<endl;

	apply_xor(sbox,first,10);
	//for(int i=0;i<10;i++)
	//	sbox[i] = sbox[i]^first[i];
	cout<<"right part after xor with left part :" ;
	for(int i=0;i<10;i++)
		cout<<sbox[i];
	cout<<endl;

	for(int i=0;i<6;i++)
		c1[i] = last[i];
	for(int i=0;i<10;i++)
		c1[i+6] = sbox[i];
	cout<<"final C1 is :";
		for(int i=0;i<16;i++)
			cout<<c1[i];
		cout<<endl;

	cout<<"Applying C0"<<endl;
	//int iv[16] = {1 ,0, 1, 0, 0,  0, 1, 0, 0, 1, 1, 1, 1, 1,0,1};
	cout<<"*********   C1'  ***********"<<endl;
	int finalc1[16];
	for(int i=0;i<16;i++)
		finalc1[i] = c0[i] ^ c1[i];
	for(int i=0;i<16;i++)
		cout<<finalc1[i];
	
	cout<<endl;



}
int main()
{
	cout<<"************* TAKING INPUT KEY **************"<<endl<<endl;
	take_input_key();

	cout<<endl<<"**************GENERATING ROUND KEY**********"<<endl<<endl;;
	apply_shift_key();
	apply_pc2_key();

	cout<<endl<<"***********TAKING INPUT Blocks  ***************"<<endl<<endl;;
	take_input_block();
	//apply_ip();
	cout<<endl;
	calculate_c0();

	cout<<endl<<"**************GENERATING ROUND KEY for C1**********"<<endl<<endl;;
	apply_shift_key();
	apply_pc2_key();
	calculate_c1();
	/*

	*/
	return 0;
}