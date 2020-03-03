#include "test.h"
extern void port_config()
{
    SET_BIT(DDRB,PB2);  // Face Output
    SET_BIT(DDRB,PB3);  // Legs Output
    SET_BIT(DDRB,PB4);  // Chest Output
    SET_BIT(DDRB,PB5);  // Windshield Output
    CLR_BIT(DDRB,PB0);
    SET_BIT(PORTB,PB0);
    CLR_BIT(DDRB,PB1);
    SET_BIT(PORTB,PB1);

    SET_BIT(DDRD,PD0); // Output - Hot Air Mode
    SET_BIT(DDRD,PD1); // Output - Cool Air Mode

    CLR_BIT(DDRD,PD2); //Interrupt Configuration
    CLR_BIT(DDRD,PD3);
    CLR_BIT(DDRD,PD4);
    CLR_BIT(DDRD,PD5);
    SET_BIT(DDRD,PD6);
    SET_BIT(PORTD,PD2);
    SET_BIT(PORTD,PD3);
    SET_BIT(PORTD,PD4);
    SET_BIT(PORTD,PD5);
    SET_BIT(EICRA,ISC10); // Any logical change INT1
    SET_BIT(EICRA,ISC00); // Any logical change INT0
    SET_BIT(EIMSK,INT0);
    SET_BIT(EIMSK,INT1);

    SET_BIT(TCCR0A,COM0A1);   //PWM Configuration
    SET_BIT(TCCR0A,WGM00);
    SET_BIT(TCCR0A,WGM01);
    SET_BIT(TCCR0B,CS02);
    SET_BIT(TCCR0B,CS00);
    TCNT0=0;


    ADMUX&=0x00;            //ADC Configuration
    SET_BIT(ADMUX,REFS0);
    SET_BIT(ADCSRA,ADEN);
    sei();   //Global interrupt
}
