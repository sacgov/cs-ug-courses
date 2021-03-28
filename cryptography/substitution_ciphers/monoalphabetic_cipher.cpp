/*
Author : sac0(sachin govind)
github : github.com/sac0

*/

#include <string>
using namespace std;
int main()
/*
it sustitutes a letter for another letter leading to 261 keys
requires a plaintext and a mapping of letters for functioning
cipher : defghijklmnopqrstuvwxyzabc
used in page 38 in cryptography and network security by william stallings fourth edition
*/
{
	string plaintext;
	string ciphertext;
	
	cout << "Enter the text to be encrypted : ";
	getline(cin,plaintext);
	//cout<<plaintext;
	ciphertext = plaintext;
	//cout<<"enter the substitution cipher to use : " ;

	//set this to other mapping for differnet cipher
	string cipher = "defghijklmnopqrstuvwxyzabc";
	for(int i=0;i<plaintext.length();i++)
	{
		if(plaintext[i ] == ' ')
			continue;
		int a = plaintext[i];
		//cout <<a<<" ";
		a= a-97;
		ciphertext[i] = cipher[a];
	}
	cout<<"encrypted text : "<<ciphertext<<endl;
	cout<<"decrypting the text : ";
	for(int i =0;i<ciphertext.length();i++)
	{
		int index = cipher.find(ciphertext[i]);
		cout<<char(index + 97);
	}
	cout<<endl;
	return 0;


}