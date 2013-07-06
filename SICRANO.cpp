// AC, ALGO : Maths, Co-ordinate Geometry.

/* 

  Helpful Link : http://www.analyzemath.com/line/Tutorials.html

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main()
{
        int t , n , m ;
        scanf("%d",&t) ;
        while( t-- )
        {
                scanf("%d%d",&n,&m) ;
                
                int p[n+1][2] , s[m+1][4] , i , j , ctr ;
                
                for( i = 1 ; i <= n ; i++ )
                        scanf("%d %d",&p[i][0],&p[i][1]) ;
                
                for( i = 1 ; i <= m ; i++ )
                        scanf("%d %d %d %d",&s[i][0],&s[i][1],&s[i][2],&s[i][3]) ;
                
                for( i = 1 ; i <= m ; i++ )
                {
                        int x1 , x2 , y1 , y2 , x , X , y , Y , y3 , x3 , m1 , m2 ;
                        x1 = s[i][0] ; 
                        x2 = s[i][2] ;
                        y1 = s[i][1] ;
                        y2 = s[i][3] ;
                        x = ( x1 > x2 ) ? x2 : x1 ;
                        X = ( x1 > x2 ) ? x1 : x2 ;
                        y = ( y1 > y2 ) ? y2 : y1 ;
                        Y = ( y1 > y2 ) ? y1 : y2 ;
                        m1 = y2 - y1 ;
                        m2 = x2 - x1 ;
                        ctr = 0 ;
                        for( j = 1 ; j <= n ; j++ )
                        {
                                x3 = p[j][0] ;
                                y3 = p[j][1] ;
                                if ( x1 == x2 ) 
                                {
                                        if( y <= y3 && y3 <= Y )
                                        {
                                                if( x3 == x1 )
                                                {
                                                        ctr++ ;
                                                }
                                        }
                                }
                                else if( y1 == y2 )
                                {
                                        if( x <= x3 && x3 <= X )
                                        {
                                                if( y3 == y1 )
                                                {
                                                        ctr++ ;
                                                }
                                        }
                                }
                                else
                                {
                                        if( ( y3 - y1 ) * m2 == ( x3 - x1 ) * m1 )
                                        {
                                                if( ( y3 - y2 ) * m2 == ( x3 - x2 ) * m1 )
                                                {
                                                        if( y <= y3 && y3 <= Y )
                                                        {
                                                                if( x <= x3 && x3 <= X )
                                                                {
                                                                        ctr++ ;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                        printf("%d\n",ctr) ;
                }
        }
        return 0 ;
}
