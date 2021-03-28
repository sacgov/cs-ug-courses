/*
Author : sac0(sachin govind)
github : github.com/sac0

*/


#include <iostream>
#include <string>
using namespace std;
int main()
/*
The Caesar cipher, also known as a shift cipher, is one of the simplest forms of encryption. It is a substitution cipher where each letter in the original message (called the plaintext) is replaced with a letter corresponding to a certain number of letters up or down in the alphabet.

Plaintext:  
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
Ciphertext: 
QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD

As unreadable as the resulting ciphertext may appear, the Caesar Cipher is one of the weakest forms of encryption one can employ.

    The key space is very small. Using a brute force method, one could easily try all (25) possible combinations in order to decrypt the message without initially knowing the key.
    The structure of the original plaintext remains intact. This makes the encryption method vulnerable to frequency analysis - by looking at how often certain characters or sequences of characters appear, one can discover patterns and potentially discover the key without having to perform a full brute force search.

The Caesar Cipher can be expressed in a more mathematical form as follows:

In plain terms, this means that the encryption of a letter x is equal to a shift of x + n, where n is the number of letters shifted. The result of the process is then taken under modulo division, essentially meaning that if a letter is shifted past the end of the alphabet, it wraps around to the beginning.

Decryption of the encrypted text (ciphertext) would be defined similarly, with instead a subtraction of the shift amount.

First used by Julius Caesar, the Caesar Cipher is one of the more well known older historical encryption methods. While you certainly wouldn't want to use it in today's modern world, a long time ago it might have done the trick.

*/
{
	string plaintext;
	string ciphertext;
	
	cout << "Enter the text to be encrypted : ";
	getline(cin,plaintext);
	//cout<<plaintext;
	ciphertext = plaintext;
	cout<<"enter the number use for modulo : " ;
	int n;
	cin>>n;
	for(int i=0;i<plaintext.length();i++)
	{
		if(plaintext[i ] == ' ')
			continue;
		int a = plaintext[i];
		//cout <<a<<" ";
		a= a-65;
		a = a+ n;
		a = a%26;
		a = a+65; 
		//cout <<a<<" ";
		ciphertext[i] = a;
	}
	cout<<"encrypted text : "<<ciphertext<<endl;
	return 0;


}