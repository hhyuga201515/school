
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
//#include <limits.h>

#define INPUT_FILE
//#define INPUT_STDIN

bool initFlag = false;	// getMax�֐��̋L�����Ă���ő�l�����������邽��

// ���܂łɈ����ɓ��͂���Ă����l�̒��ŁA
// �ł��傫�Ȓl��Ԃ�
double getMax( double num );

int main( void )
{
	int n;	// ����
	double e;	// ���e��Ό덷
	char coefStr[ 100 ][ 1000 ];	// �������̌W��(������)
	double coef[ 100 ][ 100 ];	// �������̌W��(���l)



	//////////
	// ����
	//////////

	// �����A���e��Ό덷�̓���
	#ifdef INPUT_FILE
	FILE *fp = fopen( "input.txt", "rt" );
	#endif

	#ifdef INPUT_STDIN
	scanf( "%d %lf", &n, &e );
	#else
	fscanf( fp, "%d %lf", &n, &e );
	#endif

	// �������̌W���̓���
	#ifdef INPUT_SDTIN
	getc( stdin );	//	���s��ǂݔ�΂�
	#else
	getc( fp );
	#endif
	for ( int i = 0; i < n; i++ ) {
		#ifdef INPUT_STDIN
		fgets( coefStr[ i ], sizeof( coefStr[ i ] ), stdin );	// 1�s�ǂݍ���
		#else
		fgets( coefStr[ i ], sizeof( coefStr[ i ] ), fp );	// 1�s�ǂݍ���
		#endif
	}

	// coefStr��coef�ɕϊ�
	for ( int i = 0; i < n; i++ ) {
		char *ptr;

		// coefStr��" "�ŋ�؂�
		ptr = strtok( coefStr[ i ], " " );

		// ������I�[�܂ŌJ��Ԃ�
		int j = 0;	// �v�f���J�E���^
		while ( ptr != NULL ) {
			// ���l�ɕϊ������
			coef[ i ][ j++ ] = atof( ptr );

			// ��؂�
			ptr = strtok( NULL, " " );
		}
	}

	// �\��
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n + 1; j++ ) {
			printf( "%lf ", coef[ i ][ j ] );
		}
		printf( "\n" );
	}
	


	//////////
	// ����
	//////////

	// ��
	double x[ 100 ] = { 0.0 };
	double oldX = 0.0;


	/////
	// �v�Z
	/////
	int k = 0;	// �J�E���^

	do  {
		// getMax������
		initFlag = true;
		getMax( DBL_MIN );

		for ( int i = 0; i < n; i++ ) {
			oldX = x[ i ];	// �O��̉����i�[
			x[ i ] = 0;

			for ( int j = 0; j < n; j++ ) {
				if ( i != j ) x[ i ] += -coef[ i ][ j ] * x[ j ];	// �e���̌W���Ɖ��������ĉ��Z
			}
			x[ i ] += coef[ i ][ n ];	// �E�ӂ����Z

			x[ i ] /= coef[ i ][ i ];	// �W���Ŋ���

			printf( "%lf\n", getMax( fabs( x[ i ] - oldX ) ) );	// �����擾
			//printf( "x[ %d ] :%f\n", i, x[ i ] );	// �\��
		}

		k++;
	} while ( getMax( DBL_MIN ) > e );

	// �\��
	printf( "k :%d\n", k );
	for ( int i = 0; i < n; i++ ) {
		printf( "x[ %d ] :%lf\n", i, x[ i ] );	// �\��
	}

	//////////
	// �I������
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