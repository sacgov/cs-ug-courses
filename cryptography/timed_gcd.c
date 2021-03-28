#include <stdio.h>
#include <gmp.h>
#include <stdarg.h>
#include <time.h>
void gcd(mpz_t a,mpz_t b)
{

	mpz_t t; mpz_t temp;
	mpz_inits(t,temp,NULL);
	mpz_abs(a,a);
	mpz_abs(b,b);
	//gmp_printf("a = %Zd  b = %Zd \n",a,b);
	
	while (mpz_cmp(b,temp) > 0)
	{
		//printf("%d",1);
		mpz_set(t,b);
		mpz_mod(b,a,b);
		mpz_set(a,t);
		//gmp_printf("%Zd %Zd \n",a,b);
	}
	gmp_printf("GCD is : %Zd\n",a);
}
int main()
{
	
	mpz_t  a,b,ans;
	mpz_inits(a,b,NULL);
	//gmp_printf("%Zd %Zd\n",a,b);
	//mpz_inp_str(a,stdin,10);
	//gmp_printf("%Zd %Zd\n",a,b);
	//mpz_inp_str(b,stdin,10);
	//gmp_printf("%Zd %Zd\n",a,b);
	//gcd(a,b);
	//mp_bitcnt_t nbits;
	int nbits =10;
	
	//printf("hi");
	
	//printf("hi2\n");*/
	gmp_randstate_t state;
	gmp_randinit_default (state);
	int multiplier = 1;
	for(multiplier = 1; multiplier <4 ;multiplier++)
	{
		nbits *=10;
		mpz_urandomb (a, state , nbits);
	//gmp_printf("GCD is : %Zd\n",a);
	
		mpz_urandomb (b, state , nbits);
	//gmp_printf("GCD is : %Zd\n",b);
	//printf("hi3");
		clock_t start = clock();
		gcd(a,b);
		clock_t end = clock();
		float Timeofexecution = ((float)(end - start))/CLOCKS_PER_SEC ;
		printf("bitlength %d Timeofexecution : %lf\n",nbits,Timeofexecution);
	}

	return 0;
}