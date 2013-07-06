// AC, ALGO : Elementary Calculus.

/*
  
  Helpful Link : http://hyperphysics.phy-astr.gsu.edu/hbase/math/maxmin.html

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

#define PI 3.141592653589793238462643383279

using namespace std ;

int main( )
{
    int l ;
    long double r , a ;
    
    scanf("%d",&l) ;
    
    while( l )
    {
        r = l / PI ;
        a = ( PI * r * r ) / 2 ;
        
        printf("%.2llf\n",a) ;
        
        scanf("%d",&l) ;
    }
    
    return 0 ;
}
