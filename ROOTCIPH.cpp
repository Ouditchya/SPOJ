// AC, ALGO: High School Maths.

/*
  Given Equation: X^3 + a X^2 + b X + c = 0
  Let it's roots be x, y & z
  
  Using properties of roots of cubic equations,
  
  x + y + z = -a
  xy + yz + zx = b
  xyx = c
  
  Now ans = x^2 + y^2 + z^2 
  => ans = ( x + y + z )^2 - 2( xy + yz + zx ) = a^2 - 2b
*/

// For any clarifications, contact me at : osinha6792@gmail.com



#include <cstdio>

using namespace std;

int main()
{
    int t;
    long long a, b, c;
    unsigned long long ans;
    
    scanf("%d",&t);
    while( t-- )
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        ans = a*a - 2*b;
        printf("%llu\n",ans);
    }
    
    return 0;
}
