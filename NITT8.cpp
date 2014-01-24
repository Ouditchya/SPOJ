// AC, ALGO: Adhoc.

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

#define MIN(a,b) { if((a)>(b)) (a)=(b); }
#define MAX(a,b) { if((a)<(b)) (a)=(b); }
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define inp_f( n ) scanf("%f",&n);
#define inp_d( n ) scanf("%lf",&n);
#define f(i,a,b) for( i = a; i < b; i++ )
#define F(i,a,b) for( i = a; i > b; i-- )

typedef long long i63;
typedef unsigned long long i64;

const int inf = 1000000000;
const i63 INF = i63( inf ) * inf;
const double eps = 1e-9;
const double PI = M_PI;

using namespace std;

inline i63 inp_ll()
{
    i63 n = 0, s = 1;
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
	i63 t, n, i, head, tail, ans;
	
	for( t = inp_ll(); t--; )
	{
		n = inp_ll();
		
		i63 arr[n];
		for( i = 0; i < n; i++ )
			arr[i] = inp_ll();
		
		head = ans = 0, tail = n - 1;
		while( head < tail )
		{
			ans = max( ans, ( tail - head ) * min( arr[head], arr[tail] ) );
			if( arr[head] > arr[tail] )		tail--;
			else	head++;
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
