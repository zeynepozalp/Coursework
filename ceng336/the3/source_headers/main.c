#pragma config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

#include <xc.h>
#include "breakpoints.h"

void main(void) {
    init_complete();
    adc_value =5;
    adc_complete();
    rb4_handled();
    latjh_update_complete();
    latcde_update_complete();
    correct_guess();
    hs_passed();
    game_over();
    restart();
    special_number();
    return;
}
