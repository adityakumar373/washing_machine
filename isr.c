#include <xc.h>

unsigned int count ;
extern unsigned char sec,min;
void __interrupt() isr( void ) //interrupt handler
{
    if(TMR2IF)
    {
         if (TMR2IF)
        {
            TMR2IF = 0;  // Clear flag first

        if( ++count == 20000) // 250 , 200ns 8 bit timer for 1 sec
        {
              count = 0;
            if(sec!=0)
            {
                sec--;
               
            }
            else if(sec==0 && min !=0)
            {
                min--;
                sec=59;
            }
        }
    }
    
    }
}

