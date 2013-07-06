// AC, ALGO : Adhoc.

/* Some Helpful Links :

  http://en.wikipedia.org/wiki/C_dynamic_memory_allocation
  http://www.programiz.com/c-programming/c-dynamic-memory-allocation

*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<stdio.h>
int main()
{
  long long *arr , num ;
	int i = 0 , j , ctr , temp , sum , now , p ;
	
  scanf("%lld",&num) ;
	
  arr = ( long long * )malloc( num * sizeof( long long ) ) ;
	
  do
	{
		scanf("%d",(arr+i)) ;
		i++ ;
	}	while( i != num ) ;
	printf("\n") ;
	
  for( j = 0 ; j <= i - 1 ; j++ )
	{
		ctr = 1 ;
		sum = 0 ;
		p = 5 ;
		temp = *(arr+j) ;
		while( ( now = temp / p ) != 0 )
		{
			sum += now ;
			p *= 5 ;
			ctr++ ;
		}
		printf("%d\n",sum) ;
	}
	
  return 0 ;
}
