/*
Author : sac0(sachin govind)
github : github.com/sac0

*/

#include <iostream>
#include <string>
using namespace std;
int main()
/*
C = KP mod 26
C = {c1 c2 c3} cipher text
P mod 26 = {pi ,p2,p3} plain text
K is 3*# matrix 
william stalling pg 43 cryptography and network security use 
K = {{17,17,5},{21,18,21},{2,2,19}};
plain text = "paymoremoney";
expected cipher key is LNSHDLEWMTRW
*/
{
	string plaintext;
	string ciphertext;
	
	//cout << "Enter the text to be encrypted : ";
	//getline(cin,plaintext);
	plaintext = "paymoremoney";
	//cout<<plaintext;
	ciphertext = plaintext;
	//cout<<"enter the substitution cipher to use : " ;

	//set this to other mapping for differnet cipher
	//string cipher = "defghijklmnopqrstuvwxyzabc";
	int p[3];
	int key[3][3] = {{17,17,5},{21,18,21},{2,2,19}};
	for(int i=0;i<plaintext.length();i=i+3)
	{
		if(plaintext[i ] == ' ')
			continue;
		
		p[0] = (plaintext[i] - 97)%26;
		p[1] = (plaintext[i+1] - 97)%26;
		p[2] = (plaintext[i+2] - 97)%26;

		ciphertext[i] =   ( key[0][0] * p[0] + key[0][1]*p[1] + key[0][2]*p[2] ) % 26  + 65;
		ciphertext[i+1] = ( key[1][0] * p[0] + key[1][1]*p[1] + key[1][2]*p[2] ) % 26  + 65;
		ciphertext[i+2] = ( key[2][0] * p[0] + key[2][1]*p[1] + key[2][2]*p[2] ) % 26  + 65;

	}
	cout<<"encrypted text : "<<ciphertext<<endl;

	int keyinverse[3][3] = {{4,9,15},{15,17,6},{24,0,17}};
 	cout<<"decrypting the text : ";
	for(int i =0;i<ciphertext.length();i=i+3)
	{
		p[0] = (ciphertext[i]   - 65);
		p[1] = (ciphertext[i+1] - 65);
		p[2] = (ciphertext[i+2] - 65);
		cout<<(char)(( keyinverse[0][0] * p[0] + keyinverse[0][1]*p[1] + keyinverse[0][2]*p[2] ) % 26  + 97);
		cout<<(char)(( keyinverse[1][0] * p[0] + keyinverse[1][1]*p[1] + keyinverse[1][2]*p[2] ) % 26  + 97);
		cout<<(char)(( keyinverse[2][0] * p[0] + keyinverse[2][1]*p[1] + keyinverse[2][2]*p[2] ) % 26  + 97);
	}
	cout<<endl;
	return 0;


}