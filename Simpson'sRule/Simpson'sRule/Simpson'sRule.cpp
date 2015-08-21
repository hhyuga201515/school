
#include <stdio.h>
#include <stdlib.h>



//////////
// ŠÖ”
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
	double a;	// ‹æŠÔ•‚Í‚¶‚Ü‚è
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
	h = ( b - a ) / ( double )n;

	double oddNum = 0.0;	// Šï”‰ñ
	double evenNum = 0.0;	// ‹ô”‰ñ
	for ( int i = 1; i <= n - 1; i++ ) {
		// ‹ô”‰ñ‚Ìê‡
		if ( i % 2 == 0 ) 
			evenNum += f( a + ( h * ( double )i ) );
		
		// Šï”‰ñ‚Ìê‡
		else 
			oddNum += f( a + ( h * ( double )i ) );
	}
	oddNum *= 4.0;
	evenNum *= 2.0;
	integralVal += oddNum + evenNum;
	integralVal += f( a ) + f( b );

	integralVal *= h / 3.0;	// h(‹æŠÔ•)‚ÅŠ„‚é


	printf( "\n%lf\n", integralVal );
	system( "pause" );
	return 0;
}