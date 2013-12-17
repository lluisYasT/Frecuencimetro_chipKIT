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
	
	OpenTimer4(T4_ON | T4_PS_1_256 | T4_SOURCE_INT, 62500);
	IPC4SET = 0x0000000C; // Nivel de prioridad 3
	IPC4SET = 0x00000001; // Subprioridad 1
	IFS0CLR = 0x00010000; // Clear timer interrupt status flag
	IEC0SET = 0x00010000; // Habilita inturrupciones de los temporizadores
}

void loop()
{
	if(listo) {
		listo = false;
		Serial1.write(0xFE);
		Serial1.write(0x01);
		Serial1.print("Freq: ");
		Serial1.print(cuenta * 5);
		Serial1.write(0xFE);
		Serial1.write(0x8E);
		Serial1.print("Hz");
	}
}

extern "C" {
	void __ISR(_TIMER_4_VECTOR,ipl3)Timer4Handler(void)
	{
		cuenta = TMR1;
		TMR1 = 0x0;
		IFS0CLR = 0x00010000;
		listo = true;
	}
	// void __ISR(_TIMER_1_VECTOR,ipl3)Timer1Handler(void)
	// {
	// 	PORTAINV = 0x0008;
	// 	cuenta = TMR4;
	// 	IFS0CLR = 0x00000010;
	// }
}
