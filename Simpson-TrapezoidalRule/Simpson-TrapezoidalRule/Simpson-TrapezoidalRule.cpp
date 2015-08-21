
#include <stdio.h>
#include <stdlib.h>



//////////
// �֐�
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
	double a;	// ��ԕ��͂��܂�
	double b;	// ��ԏI���
	int n;	// �ő啪����
	double h;	// ��ԕ�
	int j;	// ���݂̕�����

	/////
	// �o�̓t�@�C���ݒ�
	/////
	FILE *fp = fopen( "integral.csv", "wt" );
	if ( fp == NULL ) return -1;
	fprintf( fp, "n,Simpson'sRule,TrapezoidalRule\n" );


	//////////
	// ����
	//////////
	printf( "���̓t�H�[�}�b�g\n" );
	printf( "a :�ϕ��J�n��x\n" );
	printf( "b :�ϕ��I����x\n" );
	printf( "n :1~n�񕪊��������̐ϕ��l���v�Zx\n\n" );
	printf( "a, b, n :" );
	scanf( "%lf %lf %d", &a, &b, &n );



	//////////
	// �ϕ�
	//////////
	for ( j = 1; j <= n; j++ ) {
		h = ( b - a ) / ( double )j;
		
		/////
		// Simpson'sRule
		/////
		double simpsonsIntegralVal = 0.0;	// �ϕ��l(�V���v�\���̌���)
		if ( j % 2 == 0 ) {
			double oddNum = 0.0;	// ���̍��v
			double evenNum = 0.0;	// ������̍��v
			for ( int i = 1; i <= j - 1; i++ ) {
				// ������̏ꍇ
				if ( i % 2 == 0 )
					evenNum += f( a + ( h * ( double )i ) );

				// ���̏ꍇ
				else
					oddNum += f( a + ( h * ( double )i ) );
			}
			simpsonsIntegralVal += 4 * oddNum + 2 * evenNum;
			simpsonsIntegralVal += f( a ) + f( b );

			simpsonsIntegralVal *= h / 3.0;	// h(��ԕ�)�Ŋ���
		}
		else {
			simpsonsIntegralVal = -1;
		}


		/////
		// TrapezoidalRule
		/////
		double trapezoidalIntegralVal = 0.0;	// �ϕ��l(��`����)
		for ( int i = 1; i <= j - 1; i++ ) {
			trapezoidalIntegralVal += f( a + ( h * ( double )i ) );
		}
		trapezoidalIntegralVal *= 2.0;
		trapezoidalIntegralVal += f( a ) + f( b );

		trapezoidalIntegralVal *= h / 2.0;	// h(��ԕ�)�Ŋ���



		/////
		// �o��
		/////
		fprintf( fp, "%d,%lf,%lf\n", j, simpsonsIntegralVal, trapezoidalIntegralVal );
	}

	fclose( fp );
	system( "pause" );
	return 0;
}
