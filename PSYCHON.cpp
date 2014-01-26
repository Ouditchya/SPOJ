// AC, ALGO: Number Theory, Prime Factorization.

// DISCLAIMER: Sieve of Atkins part of the solution was not coded by me & I have cited the source below.

/* Some Helpful Links:

  http://thomasinterestingblog.wordpress.com/2011/11/30/generating-primes-with-the-sieve-of-atkin-in-c/
  http://en.wikipedia.org/wiki/Sieve_of_Atkin

*/

// For any clarifications, contact me at: osinha6792@gmail.com

#include <cstdio>
#include <cmath>

using namespace std;

#define limit 10000001

int root = ceil(sqrt(limit));
bool sieve[limit];
int primes[(limit/2)+1], insert = 2, z, x, y, n, r, a, i, even, odd, ctr;

int main()
{
    //Create the various different variables required
    primes[0] = 2, primes[1] = 3 ;
    for( z = 0; z < limit; z++ ) 
		sieve[z] = false; //Not all compilers have false as the default boolean value
	for( x = 1; x <= root; x++ )
	{
		for( y = 1; y <= root; y++ )
		{
			//Main part of Sieve of Atkin
			n = ( 4 * x * x ) + ( y * y );
			if( n <= limit && ( n % 12 == 1 || n % 12 == 5 ) ) 
				sieve[n] ^= true;
			n = ( 3 * x * x ) + ( y * y );
			if( n <= limit && n % 12 == 7 ) 
				sieve[n] ^= true;
			n = ( 3 * x * x ) - ( y * y );
			if( x > y && n <= limit && n % 12 == 11 ) 
				sieve[n] ^= true;
		}
	}
	//Mark all multiples of squares as non-prime
	sieve[2] = sieve[3] = true;
	for ( r = 5; r <= root; r++ )
	{
		if ( sieve[r] ) 
		{
			for ( i = r * r; i < limit; i += r * r ) 
				sieve[i] = false;
		}
	}
	//Add into prime array
	for( a = 5; a < limit; a++ )
	{
		if( sieve[a] )
		{
			primes[insert] = a;
			insert++;
		}
	}
	
	int N, M, t;
	for( scanf("%d",&t); t--; ) 
	{
		scanf("%d",&N);
		M = N; 
		
		if( M == 1 || sieve[M] )
		{
			printf("Ordinary Number\n");
			continue;
		}
		
		i = even = odd = 0;
		while( M != 1 )
		{
			ctr = 0;
			while( M % primes[i] == 0 )
			{
				ctr++;
				M /= primes[i];
			}
			i++;
			if( ! ( ctr & 1 ) && ctr )
				even++;
			else if( ctr & 1 && ctr )
				odd++;
			if( sieve[M] )
			{	
				odd++;
				break;
			}
		}
		puts( odd >= even ? "Ordinary Number" : "Psycho Number" );
	}
	
	return 0;
}
