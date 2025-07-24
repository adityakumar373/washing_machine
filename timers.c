#include <xc.h>
#include "timers.h"

void init_timer2(void)
{
    TMR2=0;
    T2CKPS1 = 0;  // Prescaler bit 1
    T2CKPS0 = 0;  // Prescaler bit 0

    TOUTPS3 = 0;  // Postscaler bit 3
    TOUTPS2 = 0;
    TOUTPS1 = 0;
    TOUTPS0 = 0;
    
    
    //turn off the timer2
    TMR2ON = 0;
    
    TMR2IF=0;
    // enable timer2 interrupt
    TMR2IE = 1;
    
    //no of ticks in PR2
    PR2 = 250;
 
}
