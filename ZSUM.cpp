// AC, ALGO : Math, Exponentiation by Squaring.

// Just solve the expression Z(n) + Z(n-1) - 2 * Z(n-2) using S(n) & P(n), most of the terms will cancel.

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/Exponentiation_by_squaring
  http://www.programminglogic.com/fast-exponentiation-algorithms/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

#define MOD 10000007

using namespace std ;

typedef long long int int_64 ;

int_64 simple_exponentiation( int_64 a , int_64 b )
{
  int_64 x = 1 , y = a ;
	
  while( b > 0 )
	{
		if( b % 2 == 1 )
			x = ( x * y ) % MOD ;
		y = ( y * y ) % MOD ;
		b /= 2 ;
	}
	
  return x % MOD ;
}

int main()
{
	int_64 n , k , a , b , c , d , ans ;
	
  scanf("%lld%lld",&n,&k) ;
	
  while( n != 0 && k != 0 )
	{
		a = simple_exponentiation( n , k ) ;
		b = simple_exponentiation( n - 1 , k ) ;
		b = ( b * 2 ) % MOD ;
		
    c = simple_exponentiation( n , n ) ;
		d = simple_exponentiation( n - 1, n - 1 ) ;
		d = ( d * 2 ) % MOD ;
		
    ans = ( a + b + c + d ) % MOD ;
		
    printf("%lld\n",ans) ;
		scanf("%lld %lld",&n,&k) ;
	}
	
  return 0 ;
}
