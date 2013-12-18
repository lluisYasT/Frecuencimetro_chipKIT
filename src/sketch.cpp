#include <plib.h>
#include <WProgram.h>

volatile uint32_t cuenta = 0;
volatile uint8_t i = 0;
volatile bool listo = false;

void setup()
{
	Serial1.begin(9600);
	SYSKEY = 0x0;
	SYSKEY = 0xAA996655;
	SYSKEY = 0x556699AA;

	OSCCONSET = 2;

	SYSKEY = 0x0;

	while(!OSCCONbits.SOSCRDY);


	OpenTimer1(T1_ON | T1_PS_1_1 | T1_SOURCE_EXT | T1_SYNC_EXT_OFF, 0xFFFF);
	
	OpenTimer45(T45_ON | T45_PS_1_256 | T45_SOURCE_INT | T45_32BIT_MODE_ON, 156250);
	ConfigIntTimer45(T45_INT_ON | T45_INT_PRIOR_1 | T45_INT_SUB_PRIOR_1);
	INTEnableSystemMultiVectoredInt();
}

void loop()
{
	if(listo) {
		listo = false;
		Serial1.write(0xFE);
		Serial1.write(0x01);
		Serial1.print("Freq: ");
		Serial1.print(cuenta * 2);
		Serial1.write(0xFE);
		Serial1.write(0x8E);
		Serial1.print("Hz");
	}
}

extern "C" {
	void __ISR(_TIMER_5_VECTOR,ipl1)Timer4Handler(void)
	{
		cuenta = TMR1;
		TMR1 = 0x0;
		IFS0CLR = 0x00100000;
		listo = true;
	}
	// void __ISR(_TIMER_1_VECTOR,ipl3)Timer1Handler(void)
	// {
	// 	PORTAINV = 0x0008;
	// 	cuenta = TMR4;
	// 	IFS0CLR = 0x00000010;
	// }
}
