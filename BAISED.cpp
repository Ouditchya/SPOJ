// AC, Algo : Sorting.

/*

  Helpful Link : http://www.cplusplus.com/reference/algorithm/sort/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include <cstdio>
#include <algorithm>
 
using namespace std ;
 
int main( )
{
        long long t , n , i , bad ;
        char str[10000] ;
        
        scanf("%lld",&t) ;
        
        while( t-- )
        {
                scanf("%lld",&n) ;
                
                long long a[n+1] ;
                
                for( i = 1 ; i <= n ; i++ )
                        scanf("%s %lld",str,&a[i]) ;
                        
                sort( a + 1 , a + n + 1 ) ;
                
                for( bad = 0 , i = 1 ; i <= n ; i++ )
                {
                        if( i - a[i] < 0 )
                                bad += ( a[i] - i ) ;
                        else
                                bad += ( i - a[i] ) ;
                }
                        
                printf("%lld\n",bad) ;
        }
        
        return 0 ;
}
