# AC, ALGO : Maths, Josephus problem.

# Some Helpful Links :
# http://en.wikipedia.org/wiki/Josephus_problem
# http://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/


# For any clarifications, contact me at : osinha6792@gmail.com

@l = split(/ /,<STDIN>) ;
$n = $l[0] ;
$k = $l[1] ;
while( $n != 0 and $k != 0 )
{
  	$r = 0 ;
	$i = 2 ;
	while( $i <= $n )
	{
		$r = ( $r + $k ) % $i ;
		$i++ ;
	}
	printf("%d %d %d\n",$n,$k,$r+1) ;
	@l = split(/ /,<STDIN>) ;
	$n = $l[0] ;
	$k = $l[1] ;
}
