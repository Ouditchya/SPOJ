// AC, ALGO : Simple DP

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/Dynamic_programming
  http://people.csail.mit.edu/bdean/6.046/dp/
  http://www.codechef.com/wiki/tutorial-dynamic-programming
  http://www.cs.miami.edu/~burt/learning/Csc517.101/workbook/recurrence_dynprog.html
  http://www.cplusplus.com/reference/map/map/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<map>

using namespace std ;

typedef long long int_64 ;

map< int_64 , int_64 > h ;

inline int_64 dp( int_64 n )
{
    if( n == 0 )
        return 0 ;
        
    int_64 r = h[n] ;
    
    if( r == 0 )
    {
        r = max( n , dp( n / 2 ) + dp( n / 3 ) + dp( n / 4 ) ) ;
        h[n] = r ;
    }
    
    return r ;   
}

int main( )
{
    int_64 n ;
    
    while( ~scanf("%lld",&n) )
        printf("%lld\n",dp(n)) ;

    return 0 ;
}
