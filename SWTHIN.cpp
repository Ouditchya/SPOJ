// AC, ALGO: Brute Force, High School Maths.

/* 
  Helpful Link: http://www.cut-the-knot.org/Curriculum/Calculus/StraightLine.shtml
*/

// For any clarifications, contact me at : osinha6792@gmail.com

// Ouditchya Sinha, BIT Mesra, Ranchi.

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>
#include <csignal>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <list>
#include <string>
#include <stack>
#include <complex>
#include <iterator>
#include <functional>
#include <memory>
#include <new>
#include <typeinfo>
#include <valarray>
// #include <bits/stdc++.h>

#define get getchar_unlocked
#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define f(i,a,b) for( i = a; i < b; i++ )
#define F(i,a,b) for( i = a; i > b; i-- )

typedef long long i63;
typedef unsigned long long i64;

const int inf = 1000000000;
const i63 INF = i63( inf ) * inf;
const double eps = 1e-9;
const double PI = M_PI;

using namespace std;

inline int inp_i()
{
    int n = 0, s = 1;
    char p = get();
    if( p == '-' )	s = -1;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )	p = get();
    if( p == '-' )	s = -1, p = get();
    while( p >= '0' && p <= '9' )
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) , p = get();
    return n * s;
}

int main()
{
	// freopen( "input.txt", "r", stdin );
	// freopen( "output.out", "w", stdout );
	int n, i, j, k, a, b, c, ctr, m, cs = 0;
	
	while( scanf("%d",&n) && n )
	{
		cs++;
		int x[n], y[n];
		
		for( i = 0; i < n; i++ )
			x[i] = inp_i(), y[i] = inp_i();
		
		for( m = i = 0; i < n - 2; i++ )
		{
			for( j = i + 1; j < n - 1; j++ )
			{
				a = y[i] - y[j];
				b = x[j] - x[i];
				c = y[i] * x[j] - y[j] * x[i];
				for( ctr = 2, k = j + 1; k < n; k++ )
				{
					if( a * x[k] + b * y[k] == c )
						ctr++;
				}
				m = max( ctr, m );
			}
		}
		
		if( m >= 4 )
			printf("Photo %d: %d points eliminated\n",cs,m);
		else
			printf("Photo %d: 0 points eliminated\n",cs);
	}
	
	return 0;
}
