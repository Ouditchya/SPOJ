// AC, ALGO : Adhoc.

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main()
{
        int t , n , i , j ;
        long long life , life_req , num ;
        
        scanf("%d",&t) ;
        
        for( i = 1 ; i <= t ; i++ )
        {
                life = life_req = 1 ;
                
                scanf("%d",&n) ;
                
                for( j = 0 ; j < n ; j++ )
                {
                    scanf("%lld",&num) ;
                    life += num ;
                    if( life <= 0 )
                    {
                        life_req += ( life - 1 ) * ( -1 ) ;
                        life += ( life - 1 ) * ( -1 ) ;
                    }
                }
                
                printf("Scenario #%d: %lld\n",i,life_req) ;
        }
        
        return 0 ;
}
