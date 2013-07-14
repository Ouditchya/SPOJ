// AC , ALGO : High School Maths.

/*

  Helpful Link : http://www.gogeometry.com/problem/p103_equilateral_triangle_heron_area_elearning.htm

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cmath>

#define ROOT_3 1.7320508075688772935274463

using namespace std ;

int main( )
{
        int t ;
        double area , d , e , f , s ;
        
        scanf("%d",&t) ;
        
        while( t-- )
        {
                scanf("%lf %lf %lf",&d,&e,&f) ;
                
                area = ( ROOT_3 * ( d * d + e * e + f * f ) ) / 8 ;
                s = ( d + e + f ) / 2 ;
                area += ( 1.5 * sqrt( s * ( s - d ) * ( s - e ) * ( s - f ) ) ) ;
                
                printf("%0.2lf\n",area) ;
        }
        
        return 0 ;
}
