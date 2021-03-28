#include<stdio.h>
#include<gmp.h>
#include<iostream>

using namespace std;


int main()
{

	mpz_t genp,rop,gcd;
	mpz_t one;
	mpz_t p,q,n,phi,e,d,m,c;
	gmp_randstate_t state;
	gmp_randinit_default(state);
	mpz_inits(one,p,q,gcd,rop,n,phi,e,d,c,m,genp, NULL);
	mpz_urandomb(genp,state,24);
	mpz_nextprime (p , genp);
	mpz_urandomb(genp,state,24);
	mpz_nextprime (q , genp);
	//100000007
	//100056811

	//gmp_printf("Total product of ni's is %Zd\n", rop);
	
	//mpz_set_ui(p,17);
	//mpz_set_ui(q,11);
	mpz_mul(n,p,q);
	mpz_set_ui(one,1);
	gmp_printf("n: %Zd \np: %Zd\nq: %Zd\n", n,p,q);
	mpz_sub(p,p,one);
	mpz_sub(q,q,one);
	mpz_mul(phi,p,q);
	gmp_printf("phi: %Zd\n", phi);
	mpz_set_ui(e,7);
	while(1)
	{
		mpz_urandomm(e,state,phi);
		gmp_printf("E generated :{%Zd } \n",e);
		mpz_gcd(gcd,e,phi);
		if(mpz_cmp(one,gcd)==0)
			break;

	}
	gmp_printf("e: %Zd\n", e);
	mpz_invert(d, e, phi);
	gmp_printf("d: %Zd\n", d);
	gmp_printf("PU :{%Zd , %Zd} \n",e,n);
	gmp_printf("PR :{%Zd , %Zd} \n",d,n);
	mpz_set_ui(m,88);
	gmp_printf("Plain Text :%Zd\n",m);
	mpz_powm(c,m,e,n);
	gmp_printf("Cipher text :%Zd\n",c);
	mpz_powm(m,c,d,n);
	gmp_printf("Plain Text :%Zd\n",m);
	return 0;

}















