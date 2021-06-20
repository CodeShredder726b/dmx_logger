#include <iostream>
#include <wiringPi.h>

using namespace std;
unsigned int t0, t1;

void irq_dmx_rise(void);
void irq_dmx_fall(void);

int main()
{
	wiringPiSetup();
	pinMode(1, INPUT);

	wiringPiISR(1, INT_EDGE_FALLING, irq_dmx_fall);
	wiringPiISR(1, INT_EDGE_RISING, irq_dmx_rise);
	
	for(;;)
	{
		// log to file
	}
}

void irq_dmx_rise(void)
{
	t0 = milis();
}

void irq_dmx_fall(void)
{
	t1 = milis();
	if((t1-t0) > ...)
	{
		t0 = 0;
		t1 = 0;
		// found start
		....
	}
}
