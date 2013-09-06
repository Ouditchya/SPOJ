// AC, ALGO : Adhoc.

/*

   Helpful Link: http://www.cplusplus.com/reference/cstring/memset/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include <cstdio>
#include <cstring>
 
using namespace std ;
 
int main( )
{
        int t , c , v , i , j ;
        
        scanf("%d",&t) ;
        
        while( t-- )
        {
                scanf("%d %d",&c,&v) ;
                
                int pref[v][c] , votes[c+1] , max1 , winner1 , max2 , winner2 ;
                memset( votes , 0 , sizeof( pref ) ) ;
                
                for( i = 0 ; i < v ; i++ )
                {
                        for( j = 0 ; j < c ; j++ )
                                scanf("%d",&pref[i][j]) ;
                        votes[pref[i][0]] += 1 ;
                }
                
                for( max1 = i = 0 ; i <= c + 1 ; i++ )
                {
                        if( max1 < votes[i] )
                        {
                                max1 = votes[i] ;
                                winner1 = i ;
                        }
                }
                
                if( ( ( double ) max1 ) / ( (double) v ) > 0.500000 )
                        printf("%d 1\n",winner1) ;
                else
                {
                        for( max2 = i = 0 ; i <= c + 1 ; i++ )
                        {
                                if( i == winner1 )
                                        continue ;
                                if( max2 < votes[i] )
                                {
                                        max2 = votes[i] ;
                                        winner2 = i ;
                                }
                        }
                        int a , b ;
                        a = b = 0 ;
                        
                        for( i = 0 ; i < v ; i++ )
                        {
                                j = 0 ;
                                while( pref[i][j] != winner1 && pref[i][j] != winner2 )
                                        j++ ;
                                if( pref[i][j] == winner1 )
                                        a++ ;
                                else
                                        b++ ;
                        }
                        
                        if( a > b )
                                printf("%d 2\n",winner1) ;
                        else
                                printf("%d 2\n",winner2) ;
                }
        }
        
        return 0 ;
}
