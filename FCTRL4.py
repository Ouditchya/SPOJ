# AC , ALGO : Maths, Big Integer.

# Helpful Link : http://oeis.org/A008904

# For any clarifications, contact me at : osinha6792@gmail.com

from sys import stdin
 
def exp( e ) :
        x = 1
        y = 2
        while e :
                if e % 2 == 1 :
                        x = x * y
                y = y * y
                e >>= 1
        return x
 
fac = [1,1,2,6,24]
while True :
        n = stdin.readline()
        if n == '' :
                break
        n = int(n)
        a = []
        n1 = n
        j = 0
        if n1 == 1 :
                print '1'
                continue
        while n1 >= 5 :
                b = n1 % 5
                a.append( b )
                j += 1
                n1 /= 5
        a.append( n1 )
        i = 0
        ld = 1
        while i <= j :
                ld = ( ld * ( fac[a[i]] ) *  ( exp( i * a[i] ) ) ) % 10
                i += 1
        ld = ( ld * 6 ) % 10
        print ld
