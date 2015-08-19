
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
//#include <limits.h>

#define INPUT_FILE
//#define INPUT_STDIN

bool initFlag = false;	// getMax関数の記憶している最大値を初期化するため

// 今までに引数に入力されてきた値の中で、
// 最も大きな値を返す
double getMax( double num );

int main( void )
{
	int n;	// 次数
	double e;	// 許容絶対誤差
	char coefStr[ 100 ][ 1000 ];	// 方程式の係数(文字列)
	double coef[ 100 ][ 100 ];	// 方程式の係数(数値)



	//////////
	// 入力
	//////////

	// 次数、許容絶対誤差の入力
	#ifdef INPUT_FILE
	FILE *fp = fopen( "input.txt", "rt" );
	#endif

	#ifdef INPUT_STDIN
	scanf( "%d %lf", &n, &e );
	#else
	fscanf( fp, "%d %lf", &n, &e );
	#endif

	// 方程式の係数の入力
	#ifdef INPUT_SDTIN
	getc( stdin );	//	改行を読み飛ばす
	#else
	getc( fp );
	#endif
	for ( int i = 0; i < n; i++ ) {
		#ifdef INPUT_STDIN
		fgets( coefStr[ i ], sizeof( coefStr[ i ] ), stdin );	// 1行読み込む
		#else
		fgets( coefStr[ i ], sizeof( coefStr[ i ] ), fp );	// 1行読み込む
		#endif
	}

	// coefStrをcoefに変換
	for ( int i = 0; i < n; i++ ) {
		char *ptr;

		// coefStrを" "で区切る
		ptr = strtok( coefStr[ i ], " " );

		// 文字列終端まで繰り返す
		int j = 0;	// 要素数カウンタ
		while ( ptr != NULL ) {
			// 数値に変換し代入
			coef[ i ][ j++ ] = atof( ptr );

			// 区切る
			ptr = strtok( NULL, " " );
		}
	}

	// 表示
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n + 1; j++ ) {
			printf( "%lf ", coef[ i ][ j ] );
		}
		printf( "\n" );
	}
	


	//////////
	// 処理
	//////////

	// 解
	double x[ 100 ] = { 0.0 };
	double oldX = 0.0;


	/////
	// 計算
	/////
	int k = 0;	// カウンタ

	do  {
		// getMax初期化
		initFlag = true;
		getMax( DBL_MIN );

		for ( int i = 0; i < n; i++ ) {
			oldX = x[ i ];	// 前回の解を格納
			x[ i ] = 0;

			for ( int j = 0; j < n; j++ ) {
				if ( i != j ) x[ i ] += -coef[ i ][ j ] * x[ j ];	// 各項の係数と解をかけて加算
			}
			x[ i ] += coef[ i ][ n ];	// 右辺を加算

			x[ i ] /= coef[ i ][ i ];	// 係数で割る

			printf( "%lf\n", getMax( fabs( x[ i ] - oldX ) ) );	// 差を取得
			//printf( "x[ %d ] :%f\n", i, x[ i ] );	// 表示
		}

		k++;
	} while ( getMax( DBL_MIN ) > e );

	// 表示
	printf( "k :%d\n", k );
	for ( int i = 0; i < n; i++ ) {
		printf( "x[ %d ] :%lf\n", i, x[ i ] );	// 表示
	}

	//////////
	// 終了処理
	//////////

	printf( "\n\n" );
	system( "pause" );
	return 0;
}

double getMax( double num )
{
	static double maxNum = num;

	if ( initFlag ) {
		maxNum = DBL_MIN;
		initFlag = false;
	}
	else if ( maxNum < num ) maxNum = num;

	return maxNum;
}