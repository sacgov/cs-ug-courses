#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long int get(long int n)
{
	unsigned long long int sum1=0;
	for(long int i=n;i>0;i=i-2)
	{
		sum1=sum1+(i*(i+1))/2;
	}
	return sum1;
}
int main()
{
	int t;
	scanf("%d",&t);
	long int n;
	for(int i=0;i<t;i++)
	{
		unsigned long long int sum=0;
		scanf("%ld",&n);
		sum=n*(n-1)/2;
		sum=(sum*(n+1))/3;
		sum=sum+(n*n);
		if((n-3)>0)
		sum=sum+get(n-3);
		printf("%lld\n",sum);
	}
	return 0;

}