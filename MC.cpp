// AC , ALGO : Dynamic Programming - Length of LCS.

/*
	Helpful Link : http://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cstring>

using namespace std ;

int main( )
{
  	char x[2000] , y[2000] ;
	int i , j , m , n , lcs_len ;

	while( scanf("%s",x) , strcmp( x , "#" ) )
	{
		scanf("%s",y) ;
		
		m = strlen( x ) ;
		n = strlen( y ) ;
		
		int c[m+1][n+1] ;
		memset( c , 0 , sizeof( c ) ) ;
		
		for( i = 1 ; i <= m ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
			{
				if( x[i-1] == y[j-1] )
					c[i][j] = c[i-1][j-1] + 1 ;
				else if( c[i-1][j] >= c[i][j-1] )
					c[i][j] = c[i-1][j] ;
				else
					c[i][j] = c[i][j-1] ;
			}
		}
		lcs_len = c[m][n] ;
		
		printf("%d\n",15 * ( m - lcs_len ) + 30 * ( n - lcs_len ) ) ;
	}
	
	return 0 ;
}
