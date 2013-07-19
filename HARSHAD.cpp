// AC, ALGO : Graph Theory : Number Theory, Prime Numbers.

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/Self_number
  http://oeis.org/A003219
  http://thomasinterestingblog.wordpress.com/2011/11/30/generating-primes-with-the-sieve-of-atkin-in-c/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std ;

#define limit 1000001
#define get getchar_unlocked
#define SIZE 6943

bool sieve[limit] ;
int root = ceil(sqrt(limit)) , primes[SIZE] , insert = 2 , z , x , y , n , r , a , i , j , k ;

inline int inp()
{
    int n = 0 , s = 1 ;
    char p = get() ;
    if( p == '-' )
        s = -1 ;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = get() ;
    if( p == '-' )
        s = -1 , p = get() ;
    while( p >= '0' && p <= '9' )
    {
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = get() ;
    }
    return n * s ;
}

int sum_digits( int n )
{
  	int m = n , sum = 0 ;
	
	while( m != 0 )
	{
		sum += m % 10 ;
		m /= 10 ;
	}
	
	return sum + n ;
}

int main()
{
  	for( z = 0 ; z < limit ; z++ )
		sieve[z] = false ;
	for( x = 1 ; x <= root ; x++ )
	{
		for( y = 1 ; y <= root ; y++ )
		{
			n = ( 4 * x * x ) + ( y * y ) ;
			if( n <= limit && ( n % 12 == 1 || n % 12 == 5 ) ) 
				sieve[n] ^= true ;
			n = ( 3 * x * x ) + ( y * y ) ;
			if( n <= limit && n % 12 == 7 ) 
				sieve[n] ^= true ;
			n = ( 3 * x * x ) - ( y * y ) ;
			if( x > y && n <= limit && n % 12 == 11 ) 
				sieve[n] ^= true ;
		}
	}
	sieve[2] = sieve[3] = true ;
	for ( r = 5 ; r <= root ; r++ )
	{
		if ( sieve[r] ) 
		{
			for ( i = r * r ; i < limit ; i += r * r ) 
				sieve[i] = false ;
		}
	}
	for( i = 0 ; i <= 1000000 ; i++ )
	{
		k = sum_digits(i) ;
		if( k <= 1000000 && sieve[k] )
			sieve[k] = 0 ;
	}
	// primes[0] = 3 ;	
	for( j = 0 , i = 0 ; i <= 1000000 ; i++ )
	{
		if( sieve[i] )
			primes[j++] = i ;
	}
	
	/* for( i = 0 ; i < j ; i++ )
		printf("%d ",primes[i]) ;
	printf("\n\n") ; */
	
	int q , l , r , up , low , ans ;
	
	q = inp() ;
	
	while( q-- )
	{
		l = inp() ;
		r = inp() ;
		
		low = std::lower_bound( primes , primes + SIZE , r ) - primes - 1 ;
		up = std::upper_bound( primes , primes + SIZE , l ) - primes ;
		
		if( r == primes[low+1] )
			low++ ;
		if( l == primes[up-1] && up )
			up-- ;
		
		printf("%d\n",low-up+1) ;
	}
	
	return 0 ;
}
