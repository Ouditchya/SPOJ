// AC , ALGO : Adhoc.

#include<cstdio>
#include<cstring>

using namespace std ;

int main( )
{  
	char s[1001] , e[1001] ;
	int i , count ;
	
	while( scanf("%s %s",s,e) , strcmp( s , "*" ) )
	{
		if( !strcmp( s , e ) )
			printf("0\n") ;
		else
		{
			for( i = count = 0 ; s[i] ; i++ )
			{
				if( i == 0 && s[i] != e[i] )
					count++ ;
				else if( s[i] != e[i] && s[i-1] == e[i-1] )
					count++ ;
			}
			printf("%d\n",count) ;
		}
	}
	
	return 0 ;
}
