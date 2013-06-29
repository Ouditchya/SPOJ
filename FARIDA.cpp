// AC , ALGO : Simple DP

#include<cstdio>
#include<algorithm>

typedef long long int_64 ;

using namespace std ; 

int main( )
{
  	int n , i , t , c ;
	
	scanf("%d",&t) ;
	
	for( c = 1 ; c <= t ; c++ )
	{
		scanf("%d",&n) ;
		
		if( n == 0 )
		{
			printf("Case %d: 0\n",c) ;
			continue ;
		}
		
		int_64 a[n] , dp[n] ;
	
		for( i = 0 ; i < n ; i++ )
			scanf("%lld",&a[i]) ;
	
		dp[0] = a[0] ;
		dp[1] = max( a[0] , a[1] ) ;
	
		for( i = 2 ; i < n ; i++ )
			dp[i] = max( a[i] + dp[i-2] , dp[i-1] ) ;
		
		printf("Case %d: %lld\n",c,dp[n-1]) ;
	}
	
	return 0 ;
}
