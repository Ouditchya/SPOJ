// AC, Algo : Adhoc.

/*  Some Helpful Links :
  
  http://www.cplusplus.com/reference/algorithm/
  http://www.cplusplus.com/reference/climits/
  http://www.cplusplus.com/reference/queue/queue/
  http://www.cplusplus.com/reference/vector/vector/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std ;

inline int num_dgt( int n )
{
  int c = 0 ;
	
	if( n == 0 )
		return 1 ;
	
	while( n )
	{
		n /= 10 ;
		c++ ;
	}

	return c ;
}

int main( )
{
	int t , cs , n , u , i , j , M , m , up , d ;

	for( scanf("%d",&t) , cs = 1 ; cs <= t ; cs++ )
	{
		scanf("%d %d",&n,&u) ;

		int a[n] ;

		for( i = 0 , M = INT_MIN , m = INT_MAX ; i < n ; i++ )
		{
			scanf("%d",&a[i]) ;

			if( a[i] > M )
				M = a[i] ;
			if( a[i] < m )
				m = a[i] ;
		}
		up = M / u ;
		m /= u ;
		d = num_dgt( up ) ;
		// printf("M = %d m = %d up = %d\n",M,m,up) ;

		vector< int > vec[up+1] ;
		int arr[up+1] ;
		memset( arr , 0 , sizeof( arr ) ) ;

		for( i = 0 ; i < n ; i++ )
		{
			M = a[i] / u ;
			// printf("M = %d\n",M) ;
			// printf("j = %d val = %d\n",j,a[i]%u) ;
			vec[M].push_back( a[i] % u ) ;
			arr[M]++ ;
		}

		printf("Scenario #%d:\n",cs) ;
		for( i = m ; i <= up ; i++ )
		{
			if( !arr[i] )
				continue ;
			
			M = num_dgt( i ) ;
			for( j = 1 ; j <= d - M ; j++ )
				printf(" ") ;
			printf("%d | ",i) ;

			M = vec[i].end( ) - vec[i].begin( ) ;
			sort( vec[i].begin( ) , vec[i].end( ) ) ;

			for( j = 0 ; j < M ; j++ )
				printf("%d ",vec[i][j]) ;
			printf("\n") ;
		}
	}

	return 0 ;
}
