#include <bits/stdc++.h>
using namespace std;
const string key="monarchy";
char poly[5][5];
map<char, pair<int, int> > look;

void fill_poly() {
    int arr[26];
    for (int i=0; i<26; i++)
    arr[i]=0;
    int in = 0;
    for (int i=0; i<key.length(); i++) {
    if (arr[key[i]-'a'] == 0) {
        if (key[i] == 'i' || key[i] == 'j') {
        poly[in/5][in%5] = key[i] == i ? key[i]+32 : key[i]+31;
        arr['i'-'a'] = arr['j'-'a'] = 1;
        } else {
            poly[in/5][in%5] = key[i]-32;
            arr[key[i]-'a'] = 1;
        }
        in++;
    }
    }

    for (int i=0; i<26; i++) {
    if (arr[i] == 0) {
        if (i==8){
            poly[in/5][in%5] = 'I';
        arr[i] = 0;
        arr[++i] = 1;
        }
        poly[in/5][in%5] = 'A'+i;
        in++;
    } 
    }
    // creating map of char to co-ordinates
    for (int i=0; i<5; i++)
    for (int j=0; j<5; j++)
        look.insert(make_pair(poly[i][j]+32, make_pair(i,j)));
}

string cipher(string s) {
   if (s[0] == 'i') s[0] = 'j';
   if (s[1] == 'i') s[1] = 'j';
   pair<int, int> p1 = look[s[0]];
   pair<int, int> p2 = look[s[1]];
   string c="00";
   if (p1.first == p2.first) { // same row
    c[0] = poly[p1.first][(p1.second+1)%5];
    c[1] = poly[p2.first][(p2.second+1)%5];
   } else if (p1.second == p2.second) { // same col
    c[0] = poly[(p1.first+1)%5][p1.second];
    c[1] = poly[(p2.first+1)%5][p2.second];
   } else { // else anywhere on board
    c[0] = poly[p1.first][p2.second];
    c[1] = poly[p2.first][p1.second];
   }
   return c;
}

int main(int argc, char * argv[]) {
    string str, crypt="";
    fill_poly();
    for (int i=0; i<5; i++) 
    {
        for (int j=0; j<5; j++) 
        cout << poly[i][j] << " ";
        cout << "\n";
    }

    cout << "Enter string: ";

    getline(cin, str);
    for (int i=0; i<str.length()-1; i+=2) {
    if (str[i] == str[i+1]) {
        string s;
        s.push_back(str[i]);
        s.push_back((str[i]+1)%97+'a');
        crypt += cipher(s);
        i--;
    } else {
        string s;
        s.push_back(str[i]);
        s.push_back(str[i+1]);
        crypt += cipher(s);
    }
    }
    cout << crypt << endl;
    return 0;
}