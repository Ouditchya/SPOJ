// AC , ALGO : Graph Theory : BFS on a grid.

// Source : Adapted from an incomplete solution in TopCoder Forums

/* Some Helpful Links :

	http://www.cplusplus.com/reference/queue/queue/
	http://www.cplusplus.com/reference/utility/pair/
	https://en.wikipedia.org/wiki/Breadth-first_search

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>  			// I/O
#include<cstring>			// memset method
#include<cstdlib>			
#include<queue>				// queue STL
#include<utility>			// pair STL

using namespace std ;			// standard namespace

int main( )
{
	int r , c , i , j , x , y , a[50][50] , max , cs = 1 ;
	
	// m1 & m2 are arrays holding all possibilities of traversal in 2D array except (0,0)
	int m1[] = {-1,0,1,1,1,0,-1,-1} , m2[] = {-1,-1,-1,0,1,1,1,0} ;
	
	char s[50][50] ;		// input array
	bool visited[50][50] ;		// array to hold status of co-ordinate visited/not visited
	
	queue < pair< int , int > > q ;	// queue of pairs to hold co-orinates of 2D array for BFS
	pair< int , int > p ;		// pair to hold a co-ordinate during BFS
	
	while( scanf("%d %d",&r,&c) , r != 0 , c != 0 )
	{
		memset( a , 0 , sizeof( a ) ) ;
		memset( visited , false , sizeof( visited ) ) ;	
		// visited status = false for all co-ordinates initially
		
		// Taking I/P
		for( max = i = 0 ; i < r ; i++ )
			scanf("%s",&s[i]) ;
		
		for( i = 0 ; i < r ; i++ )
		{
			for( j = 0 ; j < c ; j++ )
			{
				// If element is 'A' push its co-ordinates in queue & update value in a array
				if( s[i][j] == 'A' )		
				{
					a[i][j] = 1 ;
					max = 1 ;
					q.push( make_pair( i , j ) ) ;
				}
			}
		}
		
		// Initialising BFS & continuing till queue is empty i.e., BFS is complete
		while( !q.empty( ) )
		{
			p = q.front( ) ;		// Storing front co-ordinates
			q.pop( ) ;				// Poping current co-ordinates into queue
			// Checking all 8 possibilities from each array element
			for( i = 0 ; i < 8 ; i++ )	
			{
				x = m1[i] + p.first ;
				y = m2[i] + p.second ;
				// Checking if this new co-ordinate is within bounds && that the new co-ordinate has the next alphabet w.r.t. s[x][y]
				if( x >= 0 && x < r && y >= 0 && y < c && ( s[x][y] == 1 + s[p.first][p.second] ) )
				{
					// If this co-ordinate is not visited, set visit status to true & modify corresponding 'a' array count, modify max value if required. Push this new co-ordinate into queue as BFS from this co-ordinate must also be done to check for presence of next alphabet
					if( !visited[x][y] )
					{
						a[x][y] = 1 + a[p.first][p.second] ;
						visited[x][y] = true ;
						if( a[x][y] > max )
							max = a[x][y] ;
						q.push( make_pair( x , y ) ) ;
					}
				}
			}
		}
		
		printf("Case %d: %d\n",cs++,max) ;
	}
	
	return 0 ;
}
