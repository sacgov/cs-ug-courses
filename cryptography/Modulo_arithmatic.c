#include <stdio.h>
#include <gmp.h>
#include <stdarg.h>
#include <time.h>

int gcd(mpz_t a,mpz_t b)
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
	mpz_t q;
	mpz_init(q);
	mpz_set_si(q,1);
	if(mpz_cmp(a,q) == 0 )
		return 1;
	else
		return 0;
	
}
void extendedEuclidean(mpz_t x, mpz_t y,mpz_t a,mpz_t b)
{
	mpz_t zero;
	mpz_init(zero);
	if(!mpz_cmp(b,zero)){
		mpz_clear(zero);
		mpz_set_ui(x,1);mpz_set_ui(y,0);
		return;
	}
	mpz_t mod;
	mpz_init(mod);
	mpz_mod(mod,a,b);
	extendedEuclidean(x,y,b,mod);
	mpz_t tmp;
	mpz_init(tmp);
	mpz_set(tmp,y);
	mpz_t quotient ,quot;
	mpz_init(quot);
	mpz_init(quotient);
	mpz_sub(quot,a,mod);
	mpz_cdiv_q(quotient,quot,b);
	mpz_t mul;
	mpz_init(mul);
	mpz_mul(mul,quotient,y);
	mpz_t sub;
	mpz_init(sub);
	mpz_sub(sub,x,mul);
	mpz_set(y,sub);
	mpz_set(x,tmp);
	mpz_clear(tmp);
	mpz_clear(quotient);
	mpz_clear(mul);
	mpz_clear(quot);
	mpz_clear(sub);
}
void calextendedEuclidean(mpz_t x,mpz_t y,mpz_t a,mpz_t b)
{
	if(mpz_sgn(a) == 1 && mpz_sgn(b) == 1)
	{
		mpz_t sub;
		mpz_init(sub);
		mpz_sub(sub,a,b);
		if(mpz_sgn(sub) == 1)
			extendedEuclidean(x,y,a,b);
		else
			extendedEuclidean(x,y,b,a);
	}
	else if(mpz_sgn(a) != 1 && mpz_sgn(b)!=1)
	{
		mpz_abs(a,a);
		mpz_abs(b,b);
		mpz_t sub;
		mpz_init(sub);
		mpz_sub(sub,a,b);
		if(mpz_sgn(sub) == 1)
			extendedEuclidean(x,y,a,b);
		else
			extendedEuclidean(x,y,b,a);
		mpz_neg(x,x);
		mpz_neg(y,y);
	}
	else
	{
		extendedEuclidean(x,y,a,b);
	}
}
int _x,_y;
void exteuc(int a,int b)
{
	if(b == 0)
	{
		_x =1;
		_y =0;
		return ;
	}
	exteuc(b,a%b);
	int tmp = _y;
	_y = _x- (a/b)*_y;
	_x = tmp;
}

int main()
{
	mpz_t zero;
	mpz_init(zero);
	mpz_set_si(zero,0);
	int test =10;
	mpz_t x,y,a,b,n;
	while(test--)
	{
		mpz_inits(x,y,a,b,n,NULL);
		gmp_scanf("%Zd%Zd%Zd",a,b,n);
		//printf("cool1" );
		
		int c;
		//fflush(stdin);
		scanf("%d",&c);
		//printf("cool\n" );
		if(c == 1)
		{
			mpz_add(a,a,b);
			mpz_mod(a,a,n);
			gmp_printf("ans : %Zd\n",a);
		}
		if(c == 2)
		{
			mpz_sub(a,a,b);
			mpz_mod(a,a,n);
			gmp_printf("ans : %Zd\n",a);
		}
		if(c == 3)
		{
			mpz_mul(a,a,b);
			mpz_mod(a,a,n);
			gmp_printf("ans : %Zd\n",a);
		}
		if(c == 4)
		{
			gmp_printf("a %Zd b %Zd n %Zd\n",a,b,n);
			mpz_t bcopy,ncopy;
			mpz_inits(bcopy,ncopy,NULL);
			mpz_set(bcopy,b);
			mpz_set(ncopy,n);
			int gcdnum = gcd(bcopy,ncopy);
			if(gcdnum == 1)
			{
				//printf("finding Inverse\n");
				//gmp_printf("a %Zd b %Zd n %Zd\n",a,b,n);
				calextendedEuclidean(x,y,b,n);
				//printf("finding Inverse2\n");
				mpz_mul(a,a,x);
				//printf("finding Inverse3\n");
				//gmp_printf("a %Zd b %Zd n %Zd\n",a,b,n);
				mpz_mod(a,a,n);
				//printf("finding Inverse4\n");
				gmp_printf("ans : %Zd\n",a);
			}
			else
			{
				printf("Inverse doesnt exist\n");
			}
			
		}
/*
		extendedEuclidean(x,y,a,b);
		gmp_printf("%Zd %Zd\n",x,y);
		
		int _a,_b;

		scanf("%d %d",&_a,&_b);
		exteuc(_a,_b);
		printf("%d %d\n",_x,_y );
		*/
	}
}
