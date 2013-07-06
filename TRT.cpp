// AC, ALGO : Dynamic Programming.

/* Some Helpful Links :

  http://compsci.ca/v3/viewtopic.php?t=16847
  http://en.wikipedia.org/wiki/Dynamic_programming
  http://www.codechef.com/wiki/tutorial-dynamic-programming
  http://www.topcoder.com/tc?d1=tutorials&d2=dynProg&module=Static
  http://www.quora.com/Dynamic-Programming/Are-there-any-good-resources-or-tutorials-for-Dynamic-Programming-besides-TopCoder-tutorial

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

#define MAX 2100 

using namespace std ;

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

int treats[MAX] , interval[MAX][MAX] , n ; 

int max( int a , int b ) { return ( a > b ? a : b ) ; } 

int solve( int a , int b ) 
{
  int &ans = interval[a][b] ;
	
	if( ans )
		return ans ;
		
	if( a == b )
		return n * treats[a] ;

	int age = a + n - b ;
	
	ans = max( age * treats[a] + solve( a + 1 , b ) , age * treats[b] + solve( a , b - 1 ) ) ;

	return ans ;
	
}

int main()
{
	int i ;
	
	n = inp() ;
	
	for( i = 0 ; i < n ; i++ )
		treats[i] = inp() ;
		
	printf("%d\n",solve(0,n)) ;
	
	return 0 ;
	
}
