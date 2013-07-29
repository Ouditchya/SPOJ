// AC, ALGO : Adhoc, Implementation.

#include <cstdio>
#include <cstring>

using namespace std ;

int main( )
{
  	char key[25] , text[2000] ;
	int i , j , k , l , key_len , text_len , var ;
	
	while( ~scanf("%s %s",key,text) )
	{
		key_len = strlen( key ) ;
		text_len = strlen( text ) ;
		
		char cipher[key_len][1000] ;
		for( i = 0 ; i < key_len ; i++ )
			cipher[i][0] = '\0' ;
		
		for( i = k = 0 , var = 2 ; k < key_len && i < text_len ; k++ )
		{
			l = 0 ;
			while( cipher[k][l] != '\0' )
				l++ ;
			for( j = 0 ; j < var ; j++ )
			{
				cipher[k][l++] = text[i++] ;
				if( i == text_len )
					break ;
			}
			cipher[k][l] = '\0' ;
			if( var == 2 )
				var = 1 ;
			else
				var = 2 ;
			if( k == key_len - 1 )
				k = -1 ;
		}
		
		/* for( i = 0 ; i < key_len ; i++ )
		{
			for( j = 0 ; cipher[i][j] != '\0' ; j++ )
			{
				printf("%c ",cipher[i][j]) ;
			}
			printf("\n") ;
		}
		printf("\n\n") ; */
		
		for( i = 1 ; i <= key_len ; i++ )
		{
			j = 0 ;
			while( i != ( int ) ( key[j] - 48 ) ) 
				j++ ;
			for( k = 0 ; cipher[j][k] != '\0' ; k++ )
				printf("%c",cipher[j][k]) ;
		}
		printf("\n") ;
	}
	
	return 0 ;
}
