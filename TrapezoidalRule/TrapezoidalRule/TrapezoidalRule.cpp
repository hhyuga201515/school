
#include <stdio.h>
#include <stdlib.h>



//////////
// �֐�
//////////
double f( double x )
{
	return 1.0 / ( x + 1.0 );
}

int main( void )
{
	double a;	// ��Ԃ͂��܂�
	double b;	// ��ԏI���
	int n;	// ������
	double h;	// ��ԕ�
	double integralVal = 0.0;	// �ϕ��l


	//////////
	// ����
	//////////
	scanf( "%lf %lf %d", &a, &b, &n );



	//////////
	// �ϕ�
	//////////
	h = ( b - a ) / ( double )n;	// ��ԕ��̌v�Z

	for ( int i = 1; i <= n - 1; i++ ) {
		integralVal += f( a + ( h * ( double )i ) );
	}
	integralVal *= 2.0;
	integralVal += f( a ) + f( b );

	integralVal *= h / 2.0;	// h(��ԕ�)�Ŋ���


	printf( "\n%lf\n", integralVal );
	system( "pause" );
	return 0;
}