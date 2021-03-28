#include<stdio.h>
#include<gmp.h>
#include<iostream>

using namespace std;



mpz_t ni[50];
mpz_t ai[50];
mpz_t temp[50];
mpz_t inv[50];
mpz_t res[50];

int main(){
int m;
cin>>m;
	//gmp_scanf("%Zd", m);
	int i;
	for(i = 0; i< m; i++){
		mpz_inits(ni[i],ai[i],temp[i], inv[i], NULL);
	}

	mpz_t N;
	mpz_init(N);
	mpz_set_ui(N,1);
	for(i = 0; i< m; i++){
		gmp_scanf("%Zd%Zd",ni[i], ai[i]);
		mpz_mul(N, N, ni[i]);
		

	}

	//gmp_printf("Total product of ni's is %Zd\n", N);
	//cout<<"N/ni\n";
	for(i = 0; i< m; i++){
		mpz_t t;
		mpz_init(t);
		mpz_set(t, N);
		mpz_fdiv_q(t,t,ni[i]);
		mpz_set(temp[i], t);
		gmp_printf("%Zd ",temp[i]);
	}
	cout<<endl;
	//cout<<"Inverse\n";
	for(i = 0; i <m; i++){
		mpz_t in;
		mpz_init(in);
		mpz_invert(inv[i], temp[i], ni[i]);
		gmp_printf("%Zd ",inv[i]);
	}
	cout<<endl;
	mpz_t total;
	mpz_init(total);
	mpz_set_ui(total, 0);

	for(i = 0; i< m; i++){
		mpz_t result;
		mpz_init(result);
		mpz_set_ui(result,1);
		// ai* inv * temp
		mpz_mul(result, ai[i], inv[i]);
		mpz_mul(result, result, temp[i]);
		mpz_add(total, total, result);
		

	}

	mpz_mod(total, total, N);
	gmp_printf("X = %Zd\n", total);
	



	

}















