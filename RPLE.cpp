// AC , ALGO : STL

#include<cstdio>
#include<set>

using namespace std ;

int main( )
{
  	int cs , t , n , r , i , r1 , r2 ;
	
	scanf("%d",&t) ;
	
	for( cs = 1 ; cs <= t ; cs++ )
	{
		scanf("%d %d",&n,&r) ;
		
		set< int > spy , citizen ;
		bool status = true ;
		
		for( i = 0 ; i < r ; i++ )
		{
			scanf("%d %d",&r1,&r2) ;
			spy.insert( r1 ) ;
			citizen.insert( r2 ) ;
		}
		
		for( i = 0 ; i < n ; i++ )
		{
			if( spy.count( i ) > 0 && citizen.count( i ) > 0 )
			{
				status = false ;
				break ;
			}
		}
		
		if( status )
			printf("Scenario #%d: spying\n",cs) ;
		else
			printf("Scenario #%d: spied\n",cs) ;
	}
	
	return 0 ;
}
