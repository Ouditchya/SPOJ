// AC, ALGO : Maths, Josephus problem.

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/Josephus_problem
  http://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main( )
{
  	int r , i , n , k , id ;

	while( scanf("%d",&n) , n != 0 )
	{
		id = 1 ;
		while( true )
		{
			k = id ;	r = 0 ;		i = 2 ;
			while( i <= n - 1 )
			{
				r = ( r + k ) % i ;
				i++ ;
			}
			if( r + 2 == 13 )
				break ;
			id++ ;
		}

		printf("%d\n",id) ;
	}
	
	return 0 ;
}
