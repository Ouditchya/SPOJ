// AC , ALGO : High School Maths.

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cmath>

using namespace std ;

int main( )
{
    int test_cases ;
    double n1 , n2 , sq , i , x , y , z , k , l ;
    long long int n , d , a , j ;
    
    scanf("%d",&test_cases) ;
    
    while( test_cases-- )
    {
        scanf("%lf %lf %lf",&x,&y,&z) ;
        
        i = 3.5 * x + 2.5 * y + z ;
        k = i * i ;
        l = 12 * z * ( x + y ) ;
        sq = sqrtl( k - l ) ;
        n1 = ( i + sq ) / ( x + y ) ;
        n2 = ( i - sq ) / ( x + y ) ;
        
        if( ceil(n1) == floor(n1) ) n = (llrintl)(n1) ;
        else if( ceil(n2) == floor(n2) ) n =(llrintl)(n2) ;
        
        d = (llrintl)(( y - x ) / ( n - 6 )) ;
        a = (llrintl)(x - 2 * d) ;
        
        printf("%lld\n",n) ;
        printf("%lld ",a) ;
        
        for( j = 0 ; j <= n - 3 ; j++ )
        {
            a += d ;
            printf("%lld ",a) ;
        }
        
        a += d ;
        printf("%lld\n",a) ;
    }
    return 0 ;
}
