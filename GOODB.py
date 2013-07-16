# AC , ALGO : Maths, Combinatorics.

# Helpful Link : See Permutation with Repetition - http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=combinatorics

# For any clarifications, contact me at : osinha6792@gmail.com

fact = [1]
i = 1
while i < 301 :
        n = fact[i-1] * i
        fact.append( n )
        i += 1
 
n , w , t , r = ( int(x) for x in raw_input().split() )
ans = fact[n] / ( fact[w] * fact[t] * fact[r] )
ans = ans % 1000000007
print ans
