#include <wiringPi.h>
#include <stdio.h>
int main (void)
{
  if ( wiringPiSetupGpio () == -1 ){
	printf ("wiring failed - returning ! ");
	return 0;
  }
  pinMode (17, OUTPUT) ;
  for (;;)
  {
    digitalWrite (17, HIGH) ; delay (500) ;
    digitalWrite (17,  LOW) ; delay (500) ;
  }
  return 0 ;
}
