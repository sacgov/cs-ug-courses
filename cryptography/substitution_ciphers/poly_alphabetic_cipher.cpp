/*
Author : sac0(sachin govind)
github : github.com/sac0

*/

#include <bits/stdc++.h>
using namespace std;
#define NUM_OF_ALPHABETS 26

// Key: deceptivedeceptivedeceptive 
// Text: wearediscoveredsaveyourself 
// Cipher: ZICVTWQNGRZGVTWAVZHCQYGLMGJ 
/*

refer page 45 of cryptography and network security by william stallings fouth edition

1.Set of monoalphabetic ciphers is used
2.A key determines which particular rule is chosen for a given transformation

The process of encryption is
simple: Given a key letter x and a plaintext letter y, the ciphertext letter is at the intersection of the row
labeled x and the column labeled y; in this case the ciphertext is V

See The modern vigenere Tableau 

*/

char array_cipher[NUM_OF_ALPHABETS][NUM_OF_ALPHABETS];

void init() {
    for (int i=0; i<NUM_OF_ALPHABETS; ++i) {
        for (int j = 0; j < NUM_OF_ALPHABETS; ++j) {
            array_cipher[i][j] = 'A'+ (i%NUM_OF_ALPHABETS+j)%NUM_OF_ALPHABETS;
        }
    }
}

int main() {
    init();

    //holds the key for the cipher0
    string key;
    string text;
    string cipher="";
    cout << "Enter the text to be encrypted : "; getline(cin, text);
    cout << "Enter Key for the encryption: "; getline(cin, key);
    for (int i = 0; i < text.length(); ++i) {
        if (islower(text[i])) {
            cipher += array_cipher[text[i]-'a'][key[i]-'a'];
        }
    }
    cout<<"encrypted text : ";
    cout << cipher << "\n";
    return 0;
}

