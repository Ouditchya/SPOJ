// AC, ALGO : Adhoc.

#include <cstdio>

using namespace std ;

int main( )
{
    double n , sum ;
    int i ;
    
    while( scanf("%lf",&n) && !n )
    {
        for( sum = 0 , i = 2 ; sum <= n ; i++ )
            sum += 1 / ( long double ) i ;
        
        printf("%d card(s)\n",i-2) ;
    }
    
    return 0 ;
}
