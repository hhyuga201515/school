
#include <stdio.h>
#include <stdlib.h>



//////////
// ŠÖ”
//////////
double f( double x )
{
	return 1.0 / ( x + 1.0 );
}

int main( void )
{
	double a;	// ‹æŠÔ‚Í‚¶‚Ü‚è
	double b;	// ‹æŠÔI‚í‚è
	int n;	// •ªŠ„”
	double h;	// ‹æŠÔ•
	double integralVal = 0.0;	// Ï•ª’l


	//////////
	// “ü—Í
	//////////
	scanf( "%lf %lf %d", &a, &b, &n );



	//////////
	// Ï•ª
	//////////
	h = ( b - a ) / ( double )n;	// ‹æŠÔ•‚ÌŒvZ

	for ( int i = 1; i <= n - 1; i++ ) {
		integralVal += f( a + ( h * ( double )i ) );
	}
	integralVal *= 2.0;
	integralVal += f( a ) + f( b );

	integralVal *= h / 2.0;	// h(‹æŠÔ•)‚ÅŠ„‚é


	printf( "\n%lf\n", integralVal );
	system( "pause" );
	return 0;
}