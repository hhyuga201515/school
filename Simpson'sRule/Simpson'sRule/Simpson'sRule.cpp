
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
	h = ( b - a ) / ( double )n;

	double oddNum = 0.0;	// ���
	double evenNum = 0.0;	// ������
	for ( int i = 1; i <= n - 1; i++ ) {
		// ������̏ꍇ
		if ( i % 2 == 0 ) 
			evenNum += f( a + ( h * ( double )i ) );
		
		// ���̏ꍇ
		else 
			oddNum += f( a + ( h * ( double )i ) );
	}
	oddNum *= 4.0;
	evenNum *= 2.0;
	integralVal += oddNum + evenNum;
	integralVal += f( a ) + f( b );

	integralVal *= h / 3.0;	// h(��ԕ�)�Ŋ���


	printf( "\n%lf\n", integralVal );
	system( "pause" );
	return 0;
}