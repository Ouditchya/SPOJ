// AC, Algo : Maths, Multinomial Theorem.

/* 

  Helpful Link :  http://en.wikipedia.org/wiki/Multinomial_theorem

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main( )
{
  	long long fact[13] , num , denom ;
	int i , n , k , coeff ;
	fact[0] = 1 ;
	
	for( i = 1 ; i<= 12 ; i++ )
		fact[i] = fact[i-1] * i ;
	
	while( ~scanf("%d %d",&n,&k) )
	{
		num = fact[n] ;
		denom = 1 ;
		
		for( i = 0 ; i < k ; i++ )
		{
			scanf("%d",&coeff) ;
			denom *= fact[coeff] ;
		}
		
		printf("%lld\n",num/denom) ;
	}
	
	return 0 ;
}
