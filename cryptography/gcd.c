#include <stdio.h>
#include <gmp.h>
void gcd(mpz_t a,mpz_t b)
{

	mpz_t t; mpz_t temp;
	mpz_inits(t,temp);
	mpz_abs(a,a);
	mpz_abs(b,b);
	while (mpz_cmp(b,temp) > 0)
	{
		//printf("%d",1);
		mpz_set(t,b);
		mpz_mod(b,a,b);
		mpz_set(a,t);
		gmp_printf("%Zd %Zd \n",a,b);
	}
	gmp_printf("GCD is : %Zd\n",a);
}
int main()
{
	
	mpz_t  a,b,ans;
	mpz_inits(a,b);
	//gmp_printf("%Zd %Zd\n",a,b);
	mpz_inp_str(a,stdin,10);
	//gmp_printf("%Zd %Zd\n",a,b);
	mpz_inp_str(b,stdin,10);
	//gmp_printf("%Zd %Zd\n",a,b);
	gcd(a,b);
	return 0;
}