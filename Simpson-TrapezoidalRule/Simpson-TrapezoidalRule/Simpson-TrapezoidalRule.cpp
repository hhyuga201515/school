
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
	int n;	// 最大分割数
	double h;	// 区間幅
	int j;	// 現在の分割数

	/////
	// 出力ファイル設定
	/////
	FILE *fp = fopen( "integral.csv", "wt" );
	if ( fp == NULL ) return -1;
	fprintf( fp, "n,Simpson'sRule,TrapezoidalRule\n" );


	//////////
	// 入力
	//////////
	printf( "入力フォーマット\n" );
	printf( "a :積分開始のx\n" );
	printf( "b :積分終了のx\n" );
	printf( "n :1~n回分割した時の積分値を計算x\n\n" );
	printf( "a, b, n :" );
	scanf( "%lf %lf %d", &a, &b, &n );



	//////////
	// 積分
	//////////
	for ( j = 1; j <= n; j++ ) {
		h = ( b - a ) / ( double )j;
		
		/////
		// Simpson'sRule
		/////
		double simpsonsIntegralVal = 0.0;	// 積分値(シンプソンの公式)
		if ( j % 2 == 0 ) {
			double oddNum = 0.0;	// 奇数回の合計
			double evenNum = 0.0;	// 偶数回の合計
			for ( int i = 1; i <= j - 1; i++ ) {
				// 偶数回の場合
				if ( i % 2 == 0 )
					evenNum += f( a + ( h * ( double )i ) );

				// 奇数回の場合
				else
					oddNum += f( a + ( h * ( double )i ) );
			}
			simpsonsIntegralVal += 4 * oddNum + 2 * evenNum;
			simpsonsIntegralVal += f( a ) + f( b );

			simpsonsIntegralVal *= h / 3.0;	// h(区間幅)で割る
		}
		else {
			simpsonsIntegralVal = -1;
		}


		/////
		// TrapezoidalRule
		/////
		double trapezoidalIntegralVal = 0.0;	// 積分値(台形公式)
		for ( int i = 1; i <= j - 1; i++ ) {
			trapezoidalIntegralVal += f( a + ( h * ( double )i ) );
		}
		trapezoidalIntegralVal *= 2.0;
		trapezoidalIntegralVal += f( a ) + f( b );

		trapezoidalIntegralVal *= h / 2.0;	// h(区間幅)で割る



		/////
		// 出力
		/////
		fprintf( fp, "%d,%lf,%lf\n", j, simpsonsIntegralVal, trapezoidalIntegralVal );
	}

	fclose( fp );
	system( "pause" );
	return 0;
}
