// AC, ALGO : Maths, Newton-Raphson method.

/* Some Helpful Links :

  https://en.wikipedia.org/wiki/Newton%27s_method
  http://www.sosmath.com/calculus/diff/der07/der07.html

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cmath>
 
using namespace std ;

// Fast I/P Begins

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

// Fast I/P Ends

int main()
{
    int t , i , a , b , c ;
    double x1 , x2 , x3 , ans ;
    
    t = inp() ;
    
    while( t-- )
    {
        
        a = inp() ;
        b = inp() ;
        c = inp() ;
                
        x1 = 0 ;
        x2 = 2500 ;
                
        for( i = 1 ; i <= 50 ; i++ )
        {
            x3 = ( x1 + x2 ) / 2 ;
            ans = a * x3 + b * sin( x3 ) -  c ;
            
            if( ans == 0.000000 || ( x2 - x1 ) / 2 < 0.000001 )
                break ; 
            if( ans > 0 )
                x2 = x3 ;
            else
                x1 = x3 ;
        }
                
        printf("%lf\n",x3) ;
    }
        
    return 0 ;
}
