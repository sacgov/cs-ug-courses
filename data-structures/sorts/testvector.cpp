#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>a;
/*	//constructor 
 vector<int> first;                                // empty vector of ints
  vector<int> second (4,10);                       // four ints with value 100
  vector<int> third (second.begin(),second.end());  // iterating through second
  vector<int> fourth (third);
  //test
  std::cout << "The contents of fifth are:";
  for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
    
    cout<<endl;
    for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  vector<int>::iterator it1=second.begin();
  it1++;
  cout<<endl;
  vector<int> sixth (it1,second.end());
  for (vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
    std::cout << ' ' << *it;
    cout<<endl;
    
    
    
    
    
    //operator
  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  for (vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
  std::cout << ' ' << *it;
  cout<<endl;
  foo = std::vector<int>();
  for (vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
    std::cout << ' ' << *it;
    cout<<endl;

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';*/
  
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> test (myints, myints + sizeof(myints) / sizeof(int) );
  
 /* vector<int>::iterator it1 = test.end();
  it1--;
  vector<int>::iterator it2 = test.begin();
  it2--;
  for (vector<int>::iterator it=it1; it != it2; --it)
    std::cout << ' ' << *it;
    cout<<endl;
    
    for (vector<int>::reverse_iterator it = test.rbegin(); it != test.rend(); ++it)
    std::cout << ' ' << *it;
    cout<<endl;
    
    //check auto cend cbegin
    std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
    cout<<endl;
  myvector.resize(8,100);
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
    cout<<endl;
  myvector.resize(12);
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
    cout<<endl;
    
    
     std::vector<int>::size_type sz;

  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<4097; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(4500);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<4097; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
    std::vector<int> myvector (100);
  std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

  myvector.resize(10);
  std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

//  myvector.shrink_to_fit();  check c++ 11
  std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';*/

     std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();`

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
    
  
	
}
