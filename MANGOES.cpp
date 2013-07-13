// AC, ALGO : Adhoc.

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main()
{
    int t ;
    long long sum , n , m ;
    
    scanf("%d",&t) ;
    
    while( t-- )
    {
        scanf("%lld",&n) ;
        
        if( n % 2 == 0 )
            m = n - 1 ;
        else 
            m = n ;
        
        sum = ( ( m - 1 ) * ( m - 1 ) ) / 4 ;
        sum %= n ;
        
        printf("%lld\n",sum) ;
    }
    
    return 0 ;
}
