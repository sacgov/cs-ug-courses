/*
Author : sac0(sachin govind)
github : github.com/sac0

*/


#include <bits/stdc++.h>
using namespace std;
#define ALPHA 27

int main() {
    string key = "pxlmvmsydofuyrvzwc tnlebnecvgdupahfzzlmnyih", text = "mr mustard with the candlestick in the hall", cipher="";
    cout << "Enter the text to be encrypted : ";  //getline(cin, text);
    cout << "Enter Key for the encryption: ";    // getline(cin, key);

    int len = min(text.length(), key.length());
    int textlen = text.length();
    int keylen = key.length();
    for(int i=0;i<len;i++)
    {
        //getting an int
        int akey=26,atext=26;
        if(key[i] != ' ')
        {
            akey = key[i] - 'a';
        }
        if(text[i] != ' ')
        {
            atext = text[i] - 'a';
        }
        int ans = akey + atext;
        ans = ans % ALPHA;
        //cout <<ans<<endl;
        char c;

        c = 'A' + ans;
        cipher+=c;      
    }
    cout <<"Cipher : ";
    cout << cipher << "\n";
    return 0;
}

/*
ciphertext: ANKYODKYUREPFJBYOJDSPLREYIUNOFDOIUERFPLUYTS
key:        pxlmvmsydofuyrvzwc tnlebnecvgdupahfzzlmnyih
plaintext:  mr mustard with the candlestick in the hall
*/
