// AC , ALGO : Matrix Exponentiation , Number Theory.

#include<cstdio>
#include<cmath>

#define MOD 1000000007

typedef unsigned long long i64 ;

using namespace std ;

i64 matrix_exponentiation( i64 ex )
{
    i64 a[2][2] = { { 1 , 1 } , { 1 , 0 } } , foo[2] = { 1 , 0 } , temp[2][2] , i[2][2] = { { 1 , 0 } , { 0 , 1 } } ;
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
