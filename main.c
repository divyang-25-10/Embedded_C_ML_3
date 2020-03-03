#include "test.h"
void port_config();
int main(void)
{
    unsigned int temp_pwm=128;
    unsigned int adc_value=0;
    unsigned int b,d,start_flag;
    start_flag=1;
    port_config();  //Configuration of all ports
    while(1)
    {
        if(flag.isr_Flag1==1)
        {
            while(!(PIND & (1<<PD2)))
            {
                OCR0A=temp_pwm;
                if (start_flag == 1)
                {
                    SET_BIT(PORTD,PD1);  //Default - Cool Air
                    SET_BIT(PORTB,PB2);  //Default - Face
                    start_flag =0;
                }
                else
                {
                    PORTB |= b;
                    PORTD |= d;
                }
                SET_BIT(PORTD,PD1); // Default Cool Air
                SET_BIT(PORTB,PB2); // Default Face Mode
                if(!(PIND & (1<<PD4)))
                {
                    OCR0A=OCR0A+64;
                    temp_pwm=OCR0A;
                    _delay_ms(200);  //Delay
                }
                else if(!(PIND & (1<<PD5)))
                {
                    OCR0A=OCR0A-64;
                    temp_pwm=OCR0A;
                    _delay_ms(200);
                }
            }
            b= PINB;
            d=PIND;
            flag.isr_Flag1=0;
        }
        //OCR0A=0;
        if((flag.isr_Flag2==1))
        {
            if(!(PIND & (1<<PD2)))
            {
                OCR0A=temp_pwm;
                while(!(PIND & (1<<PD3)))
                {
                    SET_BIT(ADCSRA,ADSC);
                    while(ADCSRA & (1<<ADSC));
                    adc_value=ADC;
                    if(adc_value>750)
                    {
                        SET_BIT(PORTD, PD0); // HOT Air Mode

                    }
                    else
                    {
                        SET_BIT(PORTD, PD1);  // Cool Air Mode
                    }
                }
                if((PINB&(1<<PB0)) && (!(PINB&(1<<PB1))))
                {
                    SET_BIT(PORTB,PB3);  // Leg Mode
                    CLR_BIT(PORTB,PB2);
                    CLR_BIT(PORTB,PB4);
                    CLR_BIT(PORTB,PB5);
                }
                else if((!(PINB&(1<<PB0))) && ((PINB&(1<<PB1))))
                {
                    SET_BIT(PORTB,PB2);  // Both Mode
                    SET_BIT(PORTB,PB3);
                    CLR_BIT(PORTB,PB4);
                    CLR_BIT(PORTB,PB5);
                }
                else if((!(PINB&(1<<PB0))) && ((!(PINB&(1<<PB1)))))
                {
                    SET_BIT(PORTB,PB5);  // Windshield Mode
                    CLR_BIT(PORTB,PB2);
                    CLR_BIT(PORTB,PB4);
                    CLR_BIT(PORTB,PB3);
                }
                else
                {
                    SET_BIT(PORTB,PB2);  // Face Mode
                    CLR_BIT(PORTB,PB3);
                    CLR_BIT(PORTB,PB4);
                    CLR_BIT(PORTB,PB5);
                }

                // OCR0A=0;
            }
            else
            {
                PORTB = 0x00;
                PORTD = 0x00;
            }
        }
        flag.isr_Flag2=0;

    }
    return 0;
}
