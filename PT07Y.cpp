// AC , ALGO : Graph Theory : BFS on an unweighted, undirected tree.

/* Idea :
  1. If no. of edges != no. of nodes - 1 then "NO" ( draw a figure & think )
  2. Else 
    (i) Run a bfs from root S ( assumed node 1 ).
    (ii) Check if all the nodes are visited or not, if Yes then "YES" else "NO"
*/

/* Some Helpful Links :

  http://www.cplusplus.com/reference/queue/queue/
  http://www.cplusplus.com/reference/vector/vector/
  http://www.cplusplus.com/reference/climits/
  https://en.wikipedia.org/wiki/Breadth-first_search

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

#define MAX 10100
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

using namespace std ;

struct node
{
  int pre , dist , color ;
} ;

vector< int > adj[MAX] ;
vector< node > vec(MAX) ; 

int n ;

inline bool bfs( int s )
{
	int i , a , b , last ;

	for( i = 1 ; i <= n ; i++ )
	{
		if( i == s )
		{
			vec[i].pre = vec[i].dist = 0 ;
			vec[i].color = 1 ;
			continue ;
		}
		vec[i].pre = vec[i].color = 0 ;
		vec[i].dist = INT_MAX ;
	}

	queue< int > q ;
	q.push( s ) ;

	while( !q.empty( ) )
	{
		a = q.front( ) ;
		q.pop( ) ;

		last = adj[a].end( ) - adj[a].begin( ) ;

		for( i = 0 ; i < last ; i++ )
		{
			b = adj[a][i] ;

			if( !vec[b].color )
			{
				vec[b].color = 1 ;
				vec[b].dist = vec[a].dist + 1 ;
				vec[b].pre = a ;
				q.push( b ) ;
			}
		}

		vec[a].color = 2 ;
	} 

	for( i = 1 ; i <= n ; i++ )
	{
		if( !vec[i].color )
			return false ;
	}

	return true ;
}

int main( )
{
	int m , i , u , v ;

	n = inp( ) ;
	m = inp( ) ;

	for( i = 0 ; i < m ; i++ )
	{
		u = inp( ) ;
		v = inp( ) ;

		adj[u].push_back( v ) ;
		adj[v].push_back( u ) ;
	}

	if( m != n - 1 )
		printf("NO\n") ;
	else
		puts( bfs( 1 ) ? "YES" : "NO" ) ;

	for( i = 0 ; i <= n ; i++ )
		adj[i].clear( ) ;
	vec.clear( ) ;

	return 0 ;
}
