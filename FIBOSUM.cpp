// AC , ALGO : Matrix Exponentiation, Number Theory.

/* Some Helpful Links :

	http://en.wikipedia.org/wiki/Exponentiation_by_squaring
	http://comeoncodeon.wordpress.com/2011/05/08/recurrence-relation-and-matrix-exponentiation/
	http://zobayer.blogspot.in/2010/11/matrix-exponentiation.html
	http://en.wikipedia.org/wiki/Fibonacci_number
	http://mathworld.wolfram.com/FibonacciNumber.html

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cmath>

#define MOD 1000000007

typedef unsigned long long i64 ;

using namespace std ;

i64 matrix_exponentiation( i64 ex )
{
    i64 a[2][2] = { { 1 , 1 } , { 1 , 0 } } , temp[2][2] , i[2][2] = { { 1 , 0 } , { 0 , 1 } } ;
    if( ex == 0 )
        return 0 ;
    else if( ex == 1 )
        return 1 ;
    else
    {
        ex = ex - 1 ;
        while( ex )
        {
            if( ex & 1 )
            {
                temp[0][0] = i[0][0] ;
                temp[0][1] = i[0][1] ;
                temp[1][0] = i[1][0] ;
                temp[1][1] = i[1][1] ;
                i[0][0] = ( ( temp[0][0] * a[0][0] ) + ( temp[0][1] * a[1][0] ) ) % MOD ;
                i[0][1] = ( ( temp[0][0] * a[0][1] ) + ( temp[0][1] * a[1][1] ) ) % MOD ;
                i[1][0] = ( ( temp[1][0] * a[0][0] ) + ( temp[1][1] * a[1][0] ) ) % MOD ;
                i[1][1] = ( ( temp[1][0] * a[0][1] ) + ( temp[1][1] * a[1][1] ) ) % MOD ;
            }
            temp[0][0] = a[0][0] ;
            temp[0][1] = a[0][1] ;
            temp[1][0] = a[1][0] ;
            temp[1][1] = a[1][1] ;
            a[0][0] = ( ( temp[0][0] * temp[0][0] ) + ( temp[0][1] * temp[1][0] ) ) % MOD ;
            a[0][1] = ( ( temp[0][0] * temp[0][1] ) + ( temp[0][1] * temp[1][1] ) ) % MOD ;
            a[1][0] = ( ( temp[1][0] * temp[0][0] ) + ( temp[1][1] * temp[1][0] ) ) % MOD ;
            a[1][1] = ( ( temp[1][0] * temp[0][1] ) + ( temp[1][1] * temp[1][1] ) ) % MOD ;
            ex >>= 1 ;
        }
    }
    return i[0][0] ;     
}
 
int main()
{
    i64 t , n , m , n1 , m1 ;
  
    scanf("%llu",&t) ;
    
    while( t-- )
    {
        scanf("%llu%llu",&n,&m) ;
        
	n1 = matrix_exponentiation( n + 1 ) ;
	m1 = matrix_exponentiation( m + 2 ) ;
		
	printf("%llu\n", ( ( m1 - n1 ) + MOD ) % MOD ) ;
    }
	
    return 0 ;
} 
