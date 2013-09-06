// AC , ALGO : Graph Theory : Floyd–Warshall algorithm, All Pairs Shortest Path problem.

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
  http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include <cstdio>

using namespace std ;

int main( )
{
	int t , n , r , i , j , k , cs , d ;
	
	for( scanf("%d",&t) , cs = 1 ; cs <= t ; cs++ )
	{
		scanf("%d",&n) ;
		
		int dist[n+1][n+1] ;

		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
				scanf("%d",&dist[i][j]) ;
		}
		
		for( k = 1 ; k <= n ; k++ )
		{
			for( i = 1 ; i <= n ; i++ )
			{
				for( j = 1 ; j <= n ; j++ )
				{
					if( dist[i][k] + dist[k][j] < dist[i][j] )
						dist[i][j] = dist[i][k] + dist[k][j] ;
				}
			}
		}
		
		/* for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
				printf("%d ",dist[i][j]) ;
			printf("\n") ;
		}
		printf("\n\n") ; */
		
		scanf("%d",&r) ;
		
		for( d = 0 , k = 1 ; k <= r ; k++ )
		{
			scanf("%d %d",&i,&j) ;
			d += dist[i][j] ;
		}
		
		printf("Case #%d: %d\n",cs,d) ;
	}
	
	return 0 ;
}
