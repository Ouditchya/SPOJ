// AC , ALGO : Graph Theory : BFS on an unweighted, undirected tree.

/* Idea :
  1. Run a bfs from root S ( assumed node 1 ) to find the farthest node u. Now new S = u.
  2. Again run a bfs from the farthest node u and found a new farthest node v.
  3. The path from the node u and v is the longest path in this tree.
*/

/* Some Helpful Links :

  http://www.cplusplus.com/reference/queue/queue/
  http://www.cplusplus.com/reference/vector/vector/
  http://www.cplusplus.com/reference/climits/
  https://en.wikipedia.org/wiki/Breadth-first_search

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<climits>
#include<vector>
#include<queue>

#define MAX 10100 

// Fast I/P Starts here

#define get getchar_unlocked
 
inline int inp( )
{
    int n = 0 , s = 1 ;
    char p = get( ) ;
    if( p == '-' )
        s = -1 ;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = get( ) ;
    if( p == '-' )
        s = -1 , p = get( ) ;
    while( p >= '0' && p <= '9' )
    {
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = get( ) ;
    }
    return n * s ;
}

// Fast I/P Ends here

using namespace std ;

struct node
{
  int color , pre , dist ;
} ;

int d , n ;
vector< node > vec(MAX) ;
vector< int > adj[MAX] ;

inline int bfs( int S )
{
	int i , a , b , last ;
	
	for( i = 1 ; i <= n ; i++ )
	{
		if( i == S )
			continue ;
		vec[i].color = vec[i].pre = 0 ;
		vec[i].dist = INT_MAX ;
	}
	
	vec[S].color = 1 ;
	vec[S].pre = 0 ;
	vec[S].dist = 0 ;
	
	queue< int > q ;
	
	q.push( S ) ;
	
	while( !q.empty( ) )
	{
		a = q.front( ) ;
		q.pop( ) ;
		
		last = adj[a].end( ) - adj[a].begin( ) ;
		
		for( i = 0 ; i < last ; i++ )
		{
			b = adj[a][i] ;
			
			if( vec[b].color == 0 )
			{
				vec[b].color = 1 ;
				vec[b].pre = a ;
				vec[b].dist = vec[a].dist + 1 ;
				q.push( b ) ;
			}
		}
		vec[a].color = 2 ;
	}
	
	for( i = 1 , d = 0 ; i <= n ; i++ )
	{
		if( vec[i].dist > d )
		{
			d = vec[i].dist ;
			S = i ;
		}
	}
	
	return S ;
}

int main( )
{
	int i , u , v , s ;
	
	n = inp( ) ;
	
	for( i = 1 ; i <= n ; i++ )
	{
		u = inp( ) ;
		v = inp( ) ;
		adj[u].push_back( v ) ;
		adj[v].push_back( u ) ;
	}
	
	s = bfs( 1 ) ;
	s = bfs( s ) ;
	
	printf("%d\n",d) ;
	
	return 0 ;
}
