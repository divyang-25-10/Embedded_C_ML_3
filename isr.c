#include "test.h"
ISR(INT0_vect)
{
    cli();
    flag.isr_Flag1=1;
    sei();
}
ISR(INT1_vect)
{
    cli();
    flag.isr_Flag2=1;
    sei();
}

