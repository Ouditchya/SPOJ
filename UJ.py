# AC , ALGO : Maths, Combinatorics.

# Helpful Link : http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=combinatorics

# For any clarifications, contact me at : osinha6792@gmail.com

s = raw_input( )
n , d = ( int( x ) for x in s.split( ) )
while n != 0 or d != 0 :
    ans = pow( n , d )
    print ans
    s = raw_input( )
    n , d = ( int( x ) for x in s.split( ) )
