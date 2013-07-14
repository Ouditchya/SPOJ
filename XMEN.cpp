// AC, ALGO : Dynamic Programming, Longest Increasing Subsequence. 

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/Longest_increasing_subsequence
  http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<cstring>

#define MAX 100001

using namespace std ;

int CeilIndex( int A[] , int l , int r , int key ) 
{
    int m ;

    while( r - l > 1 )
    {
        m = l + ( r - l ) / 2 ;
        ( A[m] >= key ? r : l) = m ;
    }

    return r ;
}

int LIS_len( int A[] , int size ) 
{
    int *tailTable = new int[size] ;
    int len , i ;

    memset( tailTable , 0 , sizeof( tailTable[0] ) * size ) ;

    tailTable[0] = A[0] ;
    len = 1 ;
    for( i = 1 ; i < size ; i++ ) 
	{
        if( A[i] < tailTable[0] )
            tailTable[0] = A[i] ;
        else if( A[i] > tailTable[len-1] )
            tailTable[len++] = A[i] ;
        else
            tailTable[CeilIndex( tailTable , -1 , len - 1 , A[i] )] = A[i] ;
    }

    delete[] tailTable ;

    return len ;
}

int main( )
{
	int a[MAX] , b[MAX] , c[MAX] , i , t , n ;
	
	for( scanf("%d",&t) ; t > 0 ; t-- )
	{
		scanf("%d",&n) ;
		
		for( i = 0 ; i < n ; i++ )
		{
			scanf("%d",&a[i]) ;
			c[a[i]] = i ;
		}
		
		for( i = 0 ; i < n ; i++ )
		{
			scanf("%d",&b[i]) ;
			a[i] = c[b[i]] ;
		}
		
		printf("%d\n",LIS_len( a , n )) ;
	}
	
	return 0 ;
}
