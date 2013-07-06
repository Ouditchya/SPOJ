// AC, ALGO : High School Maths.

/* 

 Helpful Link : http://library.thinkquest.org/20991/gather/formula/data/240.html

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main( )
{
  int t ;
  long long x , y , z , a , n , d , i ;
	
  scanf("%d",&t) ;
	
  while( t-- )
  {
	scanf("%lld%lld%lld",&x,&y,&z) ;
		
    	n = ( 2 * z ) / ( x + y ) ;
	d = ( y - x ) / ( n - 5 ) ;
	a = x - 2 * d ;
		
    	printf("%lld\n",n) ;
		
    	for( i = 0 ; i < n ; i++ )
		printf("%lld ",a+i*d) ;
	printf("\n") ;
  }
	
  return 0 ;
}
