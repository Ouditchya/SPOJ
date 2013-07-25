// AC, ALGO : Adhoc.

#include <cstdio>

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

using namespace std ;

int main( )
{
  int n , i , a , m , sum ;

	while( n = inp( ) )
	{
		if( !n )
			break ;

		if( n & 1 )
			m = ( n + 1 ) / 2 ;
		else
			m = n / 2 ;

		for( sum = 0 , i = 1 ; i <= n ; i++ )
		{
			a = inp( ) ;

			if( i > n - m )
				sum += a ;
		} 

		printf("%d\n",sum) ;
	}

	return 0 ;
}
