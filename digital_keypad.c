#include <xc.h>
#include "digital_keypad.h"

void init_digital_keypad(void) {
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
    //TRISB=TRISB|0X3F;
}

unsigned char read_digital_keypad(unsigned char mode) {
    static unsigned char once = 1;
    static unsigned char long_press = 1;
    static unsigned char pre_key;
    unsigned char key = KEYPAD_PORT & INPUT_LINES;

    if ((key != ALL_RELEASED) && once) {
        once = 0;
        pre_key = key;
        long_press = 1;
    } else if ((key == ALL_RELEASED) && !once) {
        once = 1;
        if (long_press < 15) {
            long_press = 1;  // reset
            return pre_key;  // short press
        }
    } else if (!once && long_press <= 15) {
        long_press++;
    } else if (!once && long_press == 16 &&pre_key==SW4) {
        long_press++;
        return LPSW4;  // indicate long press
    }

    return ALL_RELEASED;
}

    /*
    if (mode == LEVEL_DETECTION)
    {
        return KEYPAD_PORT & INPUT_LINES;
    }
    else if(mode==STATE_DETECTION)
    {
        if (((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
        {
            once = 0;
            
            return KEYPAD_PORT & INPUT_LINES;
        }
        else if ((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED)
        {
            once = 1;
        }
    }
     */
