// AC, ALGO: Number Theory, Recursion.

/* Some Helpful Links:

  http://oeis.org/search?q=0%2C2%2C6%2C150&language=english&go=Search
  http://mathworld.wolfram.com/Thue-MorseSequence.html
  http://www.wikihow.com/Generate-the-Thue-Morse-Sequence
  http://en.wikipedia.org/wiki/Thue%E2%80%93Morse_sequence

*/

// For any clarifications, contact me at: osinha6792@gmail.com

#include <cstdio>
#include <cmath>

using namespace std;

typedef long long i64;

i64 inv;

inline void solve( i64 len, i64 post, i64 year )
{
	// printf("len = %lld, post = %lld, year = %lld, inv = %lld\n",len,post,year,inv);
	if( len == 2 )
	{
		i64 ret;
		
		if( post == 1 )
			ret = 1;
		else
			ret = 0;
		
		if( inv & 1 )
		{
			if( ret == 1 )
				ret = 0;
			else
				ret = 1;
		}
		
		// printf("ret = %lld\n",ret);
		
		puts( !ret ? "red" : "blue" );
		
		return;
	}
	else if( post > len/2 )
		solve( len/2, post - len/2, year - 1 );
	else
	{
		inv++;
		solve( len/2 ,post ,year - 1 );
	}
}

int main()
{
	i64 len, post, year, t, store[52];
	store[0] = 1;
	
	for( t = 1; t <= 51; t++ )
		store[t] = 2 * store[t-1];
	// printf("\n") ;
	
	for( t = 1; t--; )
	{
		scanf("%lld %lld",&year,&post);
		
		if( !year && !post )
		{
			printf("red\n");
			continue;
		}
		
		len = store[year];
		post++;
		
		inv = 0;
		solve( len, post, year );
	}
	
	return 0;
}
