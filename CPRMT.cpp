// AC, ALGO : Adhoc.

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std ;

int main( )
{
    int i , j , n1 , n2 , k , in1f[26] , in2f[26] , ctr ;
    char in1[2000] , in2[2000] , out[2000] ;
    
    while( scanf("%s\n%s",in1,in2) != EOF )
    {
        n1 = strlen( in1 ) ;
        n2 = strlen( in2 ) ;
        
        memset( in1f , 0 , sizeof(in1f) ) ;
        memset( in2f , 0 , sizeof(in2f) ) ; 

        for( i = 0 ; i < n1 ; i++ )
        {
            j = (int) in1[i] ;
            j -= 97 ;
            in1f[j] += 1 ;
        }
        
        for( i = 0 ; i < n2 ; i++ )
        {
            j = (int) in2[i] ;
            j -= 97 ;
            in2f[j] += 1 ;
        }

        for( ctr = i = 0 ; i < 26 ; i++ )
        {
            j = ( in1f[i] > in2f[i] ) ? in2f[i] : in1f[i] ;
            for( k = 0 ; k < j ; k++ )
                out[ctr++] = ( i + 97 ) ;
        }
        out[ctr] = '\0' ;
        
        printf("%s\n",out) ;
    }
    
    return 0 ;
}
