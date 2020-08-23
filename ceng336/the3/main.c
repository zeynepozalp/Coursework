//CENG 336 THE3 Group 8 
//Zeynep Ozalp 2237691    
//Hilmi Yildirim 2237949
//Ismail Alperen YAVASCAN 2237915
    
#pragma config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

#include <xc.h>
#include "breakpoints.h"

int adcCounter=0; //count up to 10 to get 50ms for adc 
int segCounter=0; //count up to 100 to get 500ms for 7-segment flicker
int overCounter=0; //count up to 1000 to get 5000ms=5s for game over
int rb4Counter=0; //count up to 2 to get 10ms for RB4 robust
int rb4pressed=0; //rb4 for is pressed more than 10ms
int rb4flag=0; //rb4 is set (pressed)
int hs_flag=0;
int segFlag=1;  //game is over, blink segment flag
int overFlag=0; //game is over flag
int noBlink=0;  //which number of blink is this?
                //0->display, 1->not display, 2->display, 3->not display
int rb4enoughtime=0;
int gameended=0;
int displaying=0;
int mskeep=0;
int noblink2=0;
void init();
void displaySpecial();
void displayClear();
void updateDisplay();
void gameFinished();
void mapADC();
void updateDisplay();
void timr0configure();
unsigned int adcvalue=0;
void initvariables()
{
 adcCounter=0; //count up to 10 to get 50ms for adc 
 segCounter=0; //count up to 100 to get 500ms for 7-segment flicker
 overCounter=0; //count up to 1000 to get 5000ms=5s for game over
 rb4Counter=0; //count up to 2 to get 10ms for RB4 robust
 rb4pressed=0; //rb4 for is pressed more than 10ms
 rb4flag=0; //rb4 is set (pressed)
 hs_flag=0;
 segFlag=1;  //game is over, blink segment flag
 overFlag=0; //game is over flag
 noBlink=0;  //which number of blink is this?
                //0->display, 1->not display, 2->display, 3->not display
 rb4enoughtime=0;
 gameended=0;
 displaying=0;
 mskeep=0;
 noblink2=0;
    
    
}
void timer3configure()
{
    
    T3CON=0;
    T3CONbits.RD16=1;
    T3CONbits.T3CKPS0=1;
    
    TMR3IE=1;
    
    TMR3L=0b10110000; TMR3H=0b00111100; //TMR0=15536
    T3CONbits.TMR3ON=0;
}

void __interrupt() my_isr(){ //default is high p
    
    if(TMR3IF){
        TMR3IF=0;
        rb4enoughtime=1;
        TMR3L=0b10110000; TMR3H=0b00111100; //TMR0=15536
    }
    if(ADIF){
        adc_value=(ADRESH<<8)+ADRESL;
        adc_complete();
        latjh_update_complete();
        
        
        ADIF=0;
        if(!overFlag) {
            mapADC();
            updateDisplay();
        }
    }
    if(TMR0IF){
        //TMR0 interrupt
        if(++adcCounter==10){
            //50ms passed, start ADC
            
            adcCounter=0;
            GO=1; 
        }
        TMR0IF=0;
        TMR0L=0b10110000; TMR0H=0b00111100; //TMR0=15536
    } 
    if(TMR1IF && gameended ){ // game ended show on seven segment 500 ms intervals join here
   
        if(++mskeep==100)
        {
        noblink2++;
        hs_passed();
       
        latjh_update_complete();
        if(displaying==0)
        {
            displaying=1;
         
           displaySpecial();
        
        latjh_update_complete(); 
            
            
        }
        else
        {
             displaying=0;
             
             //displayClear();
            
             PORTH=0;
             PORTJ=0;
            latjh_update_complete();
            
        
        }
        if(noblink2==4)
        {
         
             restart();
             init();
             
        }
        mskeep=0;
    
        }
        TMR1IF=0;
        TMR1L=0b10110000; TMR1H=0b00111100; //TMR1=15536
    }
    if(TMR1IF && !gameended){
        //TMR1 interrupt
        
        if(++segCounter==100 )
        {
            hs_passed();
            latjh_update_complete();
            segCounter=0;
        }
   
        if(++overCounter==1000){
            //5s passed, game is over
                /*
                T0CON=0x00;
                TMR0ON=0;

                INTCONbits.RBIE=0;
                 
                gameended=1;
                  
                LATC=0x0;
                LATD=0x0;
                LATE=0x0;   
                displayClear();
                // above clear all ports

                hs_passed();
                game_over();
                 gameended=1;
                latjh_update_complete();
                latcde_update_complete();
                displaySpecial();
                TMR1L=0b10110000; TMR1H=0b00111100; //TMR1=15536
                overFlag=1;
                 */
            gameended=1;
              gameFinished(); //call this func to blink special for 2s
            game_over();
            latjh_update_complete();
            latcde_update_complete();
        }
      TMR1IF=0;
        TMR1L=0b10110000; TMR1H=0b00111100; //TMR1=15536
        
    }

    
    if(RBIF){
        //RBports interrupt
        if(PORTBbits.RB4){
            T3CONbits.TMR3ON=1;
            TMR3L=0b10110000; TMR3H=0b00111100;
            PORTBbits.RB4=0;
        }
        else
        {
            if(rb4enoughtime==1) // 10 ms ended
            {
                T3CONbits.TMR3ON=0;
                TMR3L=0b10110000; TMR3H=0b00111100;
                rb4pressed=1;
                rb4_handled();
                latcde_update_complete();
                rb4enoughtime=0;
            }
            else
            {
                 T3CONbits.TMR3ON=0;
                TMR3L=0b10110000; TMR3H=0b00111100;
                 rb4enoughtime=0;
            }
        }
        RBIF=0;
    }
}
void gameFinished(){
    displaySpecial();
    LATC=0x0;
    LATD=0x0;
    LATE=0x0;        
    noBlink++;
    segFlag=1;
    overFlag=1;
    overCounter=0;
    game_over();
}
void init(){
    initvariables();
    overCounter=0;
    TRISC=0;
    TRISD=0;
    TRISE=0;
    
    LATC=0;
    LATD=0;
    LATE=0;

    ADRESH=0;
    ADRESL=0;
    
    TMR1IE=0;
    TMR0IE=0;
    RBIE=0;
    
    T0CON=0x00; //TMR0ON is off, tmr0 is 16 bit
                //increment with internal clock
    T1CON=0x80; //TMR1ON is off
    
    INTCON=0xb00000000;
    IPEN=0;
    
    TRISB=0x10;//RB4 is input pin
  
    ADCON0=0x30; //channel 12
    ADCON1=0; //all pins are analog, no external voltage
    ADCON2=0x82; //right justified, 0 Tad, fosc/32
    ADON=1;

    TMR1L=0xb0; TMR1H=0x3c; //TMR0=15536
     
    
    RBIF=0;
    // INCON enable
    INTCON=0xb00000000;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    INTCONbits.TMR0IE=1;
    INTCONbits.RBIE=1;

    //INTCON=0b11101000; //set GIE,PEIE TMR0IE, RBIE 1010 1000
    INTCON2=0; // set tmr0 rb interrupst as high priority
    TMR1IE=1; //set TMR1IE
    ADIE=1; //ADC interrupt is open
    timr0configure();
    TMR1ON=1; //timers are open
     //ADC started
    TRISJ=0;
    TRISH=0b11110111;
    PORTH=0;
    PORTJ=0;
    latjh_update_complete();
    timer3configure();
    init_complete();
   
}
void timr0configure()
{
    T0CON=0;
    T0CONbits.PSA=1;
    TMR0L=0b10110000; TMR0H=0b00111100; //TMR0=15536
    TMR0ON=1;
}

void displaySpecial(){
    //display special number on 7 segment
        PORTH=8;       
        if(special_number()==0)        PORTJ=0b00111111;
        else if(special_number()==1)   PORTJ=0b00000110;
        else if(special_number()==2)   PORTJ=0b01011011;
        else if(special_number()==3)   PORTJ=0b01001111;
        else if(special_number()==4)   PORTJ=0b01100110;
        else if(special_number()==5)   PORTJ=0b01101101;
        else if(special_number()==6)   PORTJ=0b01111101;
        else if(special_number()==7)   PORTJ=0b00000111;
        else if(special_number()==8)   PORTJ=0b01111111;
        else if(special_number()==9)   PORTJ=0b01101111;
        

    //latjh_update_complete();
}

void displayClear(){
    //clear 7 segment
    PORTH=0;
    PORTJ=0;
    //latjh_update_complete();
}

void updateDisplay(){
    //display adc_value on 7 segment
    
        PORTH=8;
        if(adcvalue==0)        PORTJ=0b00111111;
        else if(adcvalue==1)   PORTJ=0b00000110;
        else if(adcvalue==2)   PORTJ=0b01011011;
        else if(adcvalue==3)   PORTJ=0b01001111;
        else if(adcvalue==4)   PORTJ=0b01100110;
        else if(adcvalue==5)   PORTJ=0b01101101;
        else if(adcvalue==6)   PORTJ=0b01111101;
        else if(adcvalue==7)   PORTJ=0b00000111;
        else if(adcvalue==8)   PORTJ=0b01111111;
        else if(adcvalue==9)   PORTJ=0b01101111;
        
        latjh_update_complete();
}



void up(){
    //turn leds to up arrow
    LATC=0x02;
    LATD=0x0F;
    LATE=0x02;
    latcde_update_complete();
}

void down(){
    //turn leds to down arrow
    LATC=0x04;
    LATD=0x0F;
    LATE=0x04;
    latcde_update_complete();
}



void mapADC(){
    if(adc_value<=102) adcvalue=0;
    else if(adc_value<=204) adcvalue=1;
    else if(adc_value<=306) adcvalue=2;
    else if(adc_value<=408) adcvalue=3;
    else if(adc_value<=510) adcvalue=4;
    else if(adc_value<=612) adcvalue=5;
    else if(adc_value<=714) adcvalue=6;
    else if(adc_value<=816) adcvalue=7;
    else if(adc_value<=918) adcvalue=8;
    else if(adc_value<=1023) adcvalue=9;
    
}


void main(void) {
    init();
    
    while(1){
        
        if(rb4pressed && !overFlag){
            if(adcvalue==special_number()){
               
                    correct_guess();
                    latjh_update_complete();
                    latcde_update_complete();
                    gameended=1;
                    T0CON=0x00;
                        TMR0ON=0;

                        INTCONbits.RBIE=0;

                        gameended=1;

                        LATC=0x0;
                        LATD=0x0;
                        LATE=0x0;   
                        displayClear();
                        // above clear all ports


                        game_over();
                        gameended=1;
                        latjh_update_complete();
                        latcde_update_complete();
                        displaySpecial();
                        TMR1L=0b10110000; TMR1H=0b00111100; //TMR1=15536
                //while(1);
            }
            else if(adcvalue<special_number()){
                up();
            }
            else down();
            
            rb4pressed=0;
        }
    }
    return;
}
