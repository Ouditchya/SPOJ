// AC, ALGO : Adhoc.

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std ;

int main( )
{
  int n , s[5] , a , b , i ;
	
	while( ~scanf("%d",&n) )
	{
		memset( s , 0 , sizeof( s ) ) ;
		s[4] = 1 ;
		for( i = 0 ; i < n ; i++ )
		{
			scanf("%d%*c%d",&a,&b) ;
			if( a == 1 && b == 4 )
				s[1] += 1 ;
			if( a == 1 && b == 2 )
				s[2] += 1 ;
			if( a == 3 && b == 4 )
				s[3] += 1 ;
		}
		
		printf("%d\n", s[4] + s[3] + ( max( s[1] - s[3] , 0 ) + 2 * s[2] + 3 ) / 4 ) ;
	}
	
	return 0 ;
}
