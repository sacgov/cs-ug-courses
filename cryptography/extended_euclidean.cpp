#include <stdio.h>
#include <gmp.h>
#include <stdarg.h>
#include <time.h>

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
	int test =10;
	mpz_t x,y,a,b;
	while(test--)
	{
		mpz_inits(x,y,a,b,NULL);
		gmp_scanf("%Zd%Zd",a,b);
		extendedEuclidean(x,y,a,b);
		gmp_printf("%Zd %Zd\n",x,y);
		/*
		int _a,_b;

		scanf("%d %d",&_a,&_b);
		exteuc(_a,_b);
		printf("%d %d\n",_x,_y );
		*/
	}
}
