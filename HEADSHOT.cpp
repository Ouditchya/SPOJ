// AC , ALGO : Adhoc

#include<cstdio>
#include<cstring>

using namespace std ;

int main( )
{
  	char str[1000] ;
	int live , die , i , len ;
	live = die = 0 ;
	
	gets( str ) ;
	
	len = strlen( str ) ;
	
	if( str[0] == '0' && str[len-1] == '0' )
		live++ ;
	else if( str[0] == '0' && str[len-1] == '1' )
		die++ ;
		
	for( i = 1 ; i < len ; i++ )
	{
		if( str[i] == '1' )
			continue ;
		else if( str[i] == '0' && str[i-1] == '0' )
			live++ ;
		else if( str[i] == '0' && str[i-1] == '1' )
			die++ ;
	}
	
	if( live == len || live == die )
		printf("EQUAL\n") ;
	else if( live > die )
		printf("SHOOT\n") ;
	else if( live < die )
		printf("ROTATE\n") ;
	
	return 0 ;
}
