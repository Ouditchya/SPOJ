# AC, Algo : Adhoc.

# Helpful Link : http://www.tutorialspoint.com/python/index.htm

# For any clarifications, contact me at : osinha6792@gmail.com

fact = [1] 
i = 1
while i <= 105 :
 a = fact[i-1] * i
 i += 1
 fact.append( a )
t = int( raw_input( ) )
while t :
 t -= 1
 n = int( raw_input( ) )
 print fact[n] 
