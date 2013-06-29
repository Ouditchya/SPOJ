// AC , ALGO : Adhoc , Implementation

#include<cstdio>
#include<cstring>

using namespace std ;

int main( )
{
    char str[300] ;
    int c , r , n , i , j , flag , ctr ;
	
    scanf("%d",&c) ;
    
    while( c != 0 )
	  {
		  scanf("%s",str) ;
		  
      n = strlen( str ) ;
		  r = n / c ;
		  
      char a[r][c+1] ;
		
      flag = -1 ;
		  for( i = ctr = 0 ; i < r && ctr < n ; i++ )
		  {
			  flag *= -1 ;
			  if( flag == 1 )
			  {
                for( j = 0 ; j < c ; j++ )
					        a[i][j] = str[ctr++] ;
				        a[i][j] = '\0' ;
			  }
			  else
			  {
              for( j = c - 1 ; j >= 0 ; j-- )
					      a[i][j] = str[ctr++] ;
			  }
		  }
		  for( i = 0 ; i < c ; i++ )
		  {
			  for( j = 0 ; j < r ; j++ )
				  printf("%c",a[j][i]) ;
		  }
		  
      printf("\n") ;
      scanf("%d",&c) ;
	} 
	
  return 0 ;
}
