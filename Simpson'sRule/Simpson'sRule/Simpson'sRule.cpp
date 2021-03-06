
#include <stdio.h>
#include <stdlib.h>



//////////
// 関数
//////////
double f( double x )
{
	return 1.0 / ( x + 1.0 );
}



//////////
// main
//////////
int main( void )
{
	double a;	// 区間幅はじまり
	double b;	// 区間終わり
	int n;	// 分割数
	double h;	// 区間幅
	double integralVal = 0.0;	// 積分値


	//////////
	// 入力
	//////////
	scanf( "%lf %lf %d", &a, &b, &n );



	//////////
	// 積分
	//////////
	h = ( b - a ) / ( double )n;

	double oddNum = 0.0;	// 奇数回
	double evenNum = 0.0;	// 偶数回
	for ( int i = 1; i <= n - 1; i++ ) {
		// 偶数回の場合
		if ( i % 2 == 0 ) 
			evenNum += f( a + ( h * ( double )i ) );
		
		// 奇数回の場合
		else 
			oddNum += f( a + ( h * ( double )i ) );
	}
	oddNum *= 4.0;
	evenNum *= 2.0;
	integralVal += oddNum + evenNum;
	integralVal += f( a ) + f( b );
	integralVal *= h / 3.0;	// h(区間幅)で割る

	printf( "\n%lf\n", integralVal );
	system( "pause" );
	return 0;
}