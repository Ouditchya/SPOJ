// AC , ALGO : STL

/*	Some Helpful Links :

	http://www.cplusplus.com/reference/set/set/
	http://www.cplusplus.com/reference/utility/pair/
	
*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<set>
#include<utility>

using namespace std ;

int main( )
{
  	int t , n , r , student_id , subject_code , cs , i ;
	
	scanf("%d",&t) ;
	
	for( cs = 1 ; cs <= t ; cs++ )
	{
		scanf("%d %d",&n,&r) ;
		
		set< pair< int , int > > list ;
		
		for( i = 0 ; i < r ; i++ )
		{
			scanf("%d %d",&student_id,&subject_code) ;
			list.insert( make_pair( student_id , subject_code ) ) ;
		}
		
		printf("Scenario #%d: ",cs) ;
		if( list.size( ) == r )
			printf("possible\n") ;
		else
			printf("impossible\n") ;
	}
	
	return 0 ;
}
