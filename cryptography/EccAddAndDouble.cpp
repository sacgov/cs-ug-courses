#include <gmp.h>
#include <iostream>
using namespace std;

mpz_t a , p;
struct point
{
	mpz_t x;
	mpz_t y;
	point()
	{
		mpz_inits(x , y , NULL);	
	}
};

point pointAddition(point A , point B)
{
	point C;
	mpz_t temp1,temp2;
	mpz_inits(temp1,temp2,NULL);
	mpz_sub(temp2 , A.x , B.x);
	mpz_sub(temp1 , A.y , B.y);
	if(mpz_invert(temp2 , temp2 , p )!=0)
	{
		//Calculate slope ( temp1 : slope)
		mpz_mul(temp1, temp1 , temp2);
		mpz_mod(temp1, temp1 , p);

		//Calculate point x
		mpz_mul(C.x , temp1 , temp1);
		mpz_sub(C.x , C.x , A.x);
		mpz_sub(C.x , C.x , B.x);
		mpz_mod(C.x , C.x , p);
		
		//Calculate point y
		mpz_sub(temp2 , A.x , C.x);
		mpz_mul(C.y , temp2 , temp1);
		mpz_sub(C.y , C.y , A.y);
		mpz_mod(C.y , C.y , p);
		return C;
	}
	else return C;
	
}

point pointDoubling(point A)
{
	point C;
	mpz_t temp1 , temp2;
	mpz_inits(temp1 , temp2 , NULL);
	
	//Calculate slope
	mpz_mul(temp1 , A.x , A.x);
	mpz_mul_ui(temp1 , temp1 , 3);
	mpz_add(temp1 , temp1 , a);
	mpz_mul_ui(temp2 , A.y , 2);
	if(mpz_invert(temp2 , temp2 , p)!=0)
	{
		//temp1 = slope
		mpz_mul(temp1 , temp1 , temp2);	
		mpz_mod(temp1 , temp1 , p);
	
		//calculate point x
		mpz_mul(C.x , temp1 , temp1);
		mpz_sub(C.x , C.x , A.x);
		mpz_sub(C.x , C.x , A.x);
		mpz_mod(C.x , C.x , p);

		//Calculate point y
		mpz_sub(C.y , A.x , C.x);
		mpz_mul(C.y , C.y , temp1);
		mpz_sub(C.y , C.y , A.y);
		mpz_mod(C.y , C.y , p);
		return C;
	}
	else
		return C;

}
int main()
{
	mpz_inits(a , p , NULL);
	cout<<"Enter the value of a and p respectively :";
	cin>>a>>p;
	
	//Point Addition
	cout<<"Enter the points to add : ";
	point A , B;
	cin>>A.x>>A.y;
	cin>>B.x>>B.y;
	point C = pointAddition(A, B);
	cout<<C.x<<" "<<C.y<<endl;

	//point Doubling
	cout<<"points to double :";
	cin>>A.x>>A.y;
	C = pointDoubling(A);
	cout<<"Result : "<<C.x<<" "<<C.y<<"endl";
	return 0;
}
