// AC , ALGO : High School Physics.

/*  Some Helpful Links :

    http://en.wikipedia.org/wiki/Projectile_motion
    http://www.physicsclassroom.com/Class/vectors/U3L2e.cfm
    http://physics.gmu.edu/~amin/phys251/Topics/ScientificComputing/sprojectileMotion.html

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include <cstdio>
#include <cmath>

#define PI 3.14159265

using namespace std ;

int main( )
{
    int t , ta , sp , i ;
    double angle ;
    
    for( scanf("%d",&t) , i = 1 ; i <= t ; i++ )
    {
        scanf("%d%d",&ta,&sp) ;
        
        angle = asin( ( 9.806 * ta ) / ( sp * sp ) ) ;
        angle /= 2 ;
        angle *= 180.0 ;
        angle /= PI ;
        
        printf("Scenario #%d: ",i) ;
        if( angle <= 45.000000000000 )
            printf("%.2lf\n",angle) ;
        else
            printf("-1\n") ;
    }
    
    return 0 ;
}
