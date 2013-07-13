// AC, ALGO : Greedy, Activity Selection problem.

/* Some Helpful Links :

  http://www.cplusplus.com/reference/utility/pair/
  http://en.wikipedia.org/wiki/Activity_selection_problem
  http://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std ;

int main( )
{
        int t , i , s , f , n , ctr , k ;
        
        scanf("%d",&t) ;
        
        pair<int,int> a[100001] ;
        
        while( t-- )
        {
                scanf("%d",&n) ;
                
                for( i = 0 ; i < n ; i++ )
                {
                        scanf("%d%d",&s,&f) ;
                        a[i] = make_pair(f,s) ;
                }
                
                sort( a , a + n ) ;
                
                for( k = 0 , ctr = i = 1 ; i <= n ; i++ )
                {
                        if( a[i].second >= a[k].first )
                        {
                                ctr++ ;
                                k = i ;
                        }
                }
                
                printf("%d\n",ctr) ;
        }
        
        return 0 ;
}
