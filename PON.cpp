// AC , ALGO : Number Theory, Non-deterministic Primality Testing.

/* Some Helpful Links :

  http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=primalityTesting
  http://en.wikipedia.org/wiki/Primality_test
  http://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
  http://en.wikipedia.org/wiki/Bitwise_operation
  http://publib.boulder.ibm.com/infocenter/comphelp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8a.doc%2Flanguage%2Fref%2Fbitshe.htm

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cstdlib>

using namespace std ;

typedef long long int64 ;

#define get getchar_unlocked
 
inline int inp( )
{
    int n = 0 , s = 1 ;
    char p = get( ) ;
    if( p == '-' )
        s = -1 ;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = get( ) ;
    if( p == '-' )
        s = -1 , p = get( ) ;
    while( p >= '0' && p <= '9' )
    {
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = get( ) ;
    }
    return n * s ;
}

int64 mod_exponentiation( int64 a , int64 b , int64 c ) ;
int64 mullmod( int64 a , int64 b , int64 c ) ;
bool Miller( int64 p , int iterations ) ;
bool Fermat( int64 p , int iterations ) ;

int main()
{
  	int64 n ;
	int t ;
	
	t = inp() ;
	
	while( t-- )
	{
		scanf("%lld",&n) ;
		if( Miller( n , 1 ) )
			printf("YES\n") ;
		else
			printf("NO\n") ;
	}
	
	return 0 ;
}

int64 mod_exponentiation( int64 a , int64 b , int64 c )
{
	int64 x = 1 , y = b ;
	
  	while( b )
	{
		if( b & 1 )
			x = mullmod( x , y , c ) ;				// x = ( x * y ) % c ;
		y = mullmod( y , y , c ) ;					// y = ( y * y ) % c ;
		b >>= 1 ;
	}
	
  	return x % c ;
}

int64 mullmod( int64 a , int64 b , int64 c )
{
	int64 x = 0 , y = a % c ;
	
  	while( b )
	{
		if( b & 1 )
			x = ( x + y ) % c ;
		y = ( y * 2 ) % c ;
		b >>= 1 ;
	}
	
  	return x % c ;
}

bool Miller( int64 p , int iterations )
{
	if( p < 2 )
		return false ;
	if( p != 2 && p % 2 == 0 )
		return false ;
	
  	int64 s = p - 1 , a , mod , temp ;
	int i ;
	
  	while( s % 2 == 0 )
		s >>= 1 ;
	
  	for( i = 0 ; i < iterations ; i++ )
	{
		a = rand() % ( p - 1 ) + 1 ;
		temp = s ;
		
    		mod = mod_exponentiation( a , temp , p ) ;
		
    		while( temp != p - 1 && mod != 1 && mod != p - 1 )
		{
			mod = mullmod( mod , mod , p ) ;
			temp <<= 1 ;
		}
		
    		if( mod != p - 1 && temp % 2 == 0 )
			return false ;
	}
	
  	return true ;
}
