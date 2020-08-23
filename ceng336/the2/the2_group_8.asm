;CENG 336 THE2 Group 8 (THE2_v2 simulation environment)
;Zeynep Özalp 2237691
;Hilmi Yıldırım 2237949
;İsmail Alperen YAVAŞCAN 2237915
;We tested our code on board and it is woking.
;7-segment display has some issues in board.
;All is working properly in the simulation environment.

list P=18F8722

#include <p18f8722.inc>
config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF
UDATA_ACS
    t1	res 1	; used in delay
    level2_neccessary_ball res 1
    level3_neccessary_ball res 1
    timer0_counter3 res 1
    bar_flag	res 1
    end_flag	res 1
    five_move	res 1

;----------------------------------
timer0_counter1 udata 0x21
timer0_counter1

timer0_counter2 udata 0x22
timer0_counter2

errorint udata 0x23
errorint

level1_neccessary_ball udata 0x24
level1_neccessary_ball

level udata 0x25
level

w_temp  udata 0x26
w_temp

status_temp udata 0x27
status_temp

pclath_temp udata 0x28
pclath_temp

portb_var   udata 0x29
portb_var

ballgen1low udata 0x30
ballgen1low

ballgen1high udata 0x31
ballgen1high

ballgen2 udata 0x32
ballgen2

crateball udata 0x33
createball

carry udata 0x34
carry

carry2 udata 0x35
carry2

HP udata 0x36
HP

bar udata 0x37
bar

gameover udata 0x38
gameover

 cblock 0x10
 d1
 d2
 endc




org     0x00
goto    init

org     0x08
goto    isr             ;go to interrupt service rout

init:
    clrf PORTA
    clrf PORTB
    clrf PORTC
    clrf PORTD
    clrf PORTE
    clrf PORTF
    clrf PORTG
    clrf PORTH
    clrf PORTJ

    clrf LATA
    clrf LATB
    clrf LATC
    clrf LATD
    clrf LATE
    clrf LATF
    clrf LATG

    clrf TRISA
    clrf TRISB
    clrf TRISC
    clrf TRISD
    clrf TRISE
    clrf TRISF
    clrf TRISG
    clrf TRISH
    clrf TRISJ

    ;clear variables
    clrf level
    clrf errorint
    clrf timer0_counter1
    clrf timer0_counter2
    clrf level1_neccessary_ball
    clrf w_temp
    clrf status_temp
    clrf pclath_temp
    clrf portb_var
    clrf ballgen1low
    clrf ballgen1high
    clrf ballgen2
    clrf createball
    clrf carry
    clrf carry2
    clrf HP
    clrf bar
    clrf end_flag
    clrf gameover

    ;timer 0 counters initilization
    movlw   d'76' ; 76 x 256 x 256 x 0.1 =500ms
    movwf   timer0_counter1
    movlw   d'61'
    movwf   timer0_counter2
    movlw   d'53'
    movwf   timer0_counter3
    movlw   d'5'
    movwf   five_move
    ;------ ball initilization----

    movlw   d'5' ;level1_neccessary_ball is 5
    movwf   level1_neccessary_ball ;we need 5 ball for level 1
    movlw   d'10'
    movwf   level2_neccessary_ball ;we need 10 ball for level 1
    movlw   d'15'
    movwf   level3_neccessary_ball ;we need 15 ball for level 1

    movlw   d'1'
    movwf   level
    ;Disable interrupts
    clrf    INTCON
    clrf    INTCON2

    ;Configure Output Ports
    clrf    LATF
    clrf    TRISF

    ;Configure Input/Interrupt Ports
    movlw   b'00010000'
    movwf   TRISB
    bsf     INTCON2, 7  ;External Pull-ups are enabled, Internal Pull-ups are disabled
    clrf    PORTB

    ;Initialize Timer0
    movlw   b'01000111' ;Disable Timer0 by setting TMR0ON to 0 (for now)
                        ;Configure Timer0 as an 8-bit timer/counter by setting T08BIT to 1
                        ;Timer0 increment from internal clock with a prescaler of 1:256.
    movwf   T0CON
    movlw   b'10000001'
    movwf   T1CON	;on bit one

    ;Enable interrupts
    movlw   b'10100000' ;Enable Global, peripheral, Timer0 and RB interrupts by setting GIE, PEIE, TMR0IE and RBIE bits to 1
    movwf   INTCON
    clrf    TMR0

    ;asagidaki kodu RG0 basildiktan sonra main icine yazdim
    ;bsf     T0CON, 7    Enable Timer0 by setting TMR0ON to 1

    movlw   b'00001101' ; RG0-2-3 is input port
    movwf   TRISG

    call startGame

    goto main

generateRondomBall:
    movff ballgen1low, ballgen2
    movlw 07h
    andwf ballgen2, 1, 0 ;take rightmost 3 bits
    movlw 04h
    subwf ballgen2, 0, 0 ; substract 4 from ballgen1 put the result in wreg
    btfss STATUS, 4 ;if ballgen1-4 is negative, skip
    movwf ballgen2, 0 ;if ballgen1-4 is not negative, balgen1=balgen1-4 (mod operation)
    movff ballgen2, createball ;createball is the number of RG tha ball will be
    call shiftBallgen1
    movlw 01h
    cpfsgt level, 0
    goto exitGenBall
    call shiftBallgen1
    call shiftBallgen1
    movlw 02h
    cpfsgt level, 0
    goto exitGenBall
    call shiftBallgen1
    call shiftBallgen1
exitGenBall:
    goto createBall

shiftBallgen1:

    clrf carry
    clrf carry2

    btfsc ballgen1low, 0
    setf carry
    btfsc ballgen1high, 0
    setf carry2
    rrcf ballgen1low
    rrcf ballgen1high

    btfsc carry, 0
    bsf ballgen1high, 7
    btfss carry, 0
    bcf ballgen1high, 7
    btfsc carry2, 0
    bsf ballgen1low, 7
    btfss carry2, 0
    bcf ballgen1low, 7
    return

createBall:
    movlw 00h
    cpfsgt createball
    goto createballA
    movlw 01h
    cpfsgt createball
    goto createballB
    movlw 02h
    cpfsgt createball
    goto createballC
    goto createballD
createballA:
    bsf LATA, 0
    return
createballB:
    bsf LATB, 0
    return
createballC:
    bsf LATC, 0
    return
createballD:
    bsf LATD, 0
    return

moveBalls:
    clrf bar_flag
    call moveBallsA
    clrf bar_flag
    call moveBallsB
    clrf bar_flag
    call moveBallsC
    clrf bar_flag
    call moveBallsD
    clrf bar_flag
    return
moveBallsA:
    btfsc LATA, 5
    call barTestA

    bcf STATUS, 0 ;clear carry bit
    btfsc bar, 0
    incf bar_flag
    rlcf LATA
    bcf LATA, 6 ;clear bit 6
    btfsc bar_flag,0 ; bar? yerine koy
    bsf	  LATA,5

    return
moveBallsB:
    btfsc LATB, 5
    call barTestB

    bcf STATUS, 0 ;clear carry bit
    btfsc bar, 1
    incf bar_flag
    rlcf LATB
    bcf LATB, 6 ;clear bit 6
    btfsc bar_flag,0 ; bar? yerine koy
    bsf	  LATB,5

    return
moveBallsC:
    btfsc LATC, 5
    call barTestC

    bcf STATUS, 0 ;clear carry bit
    btfsc bar,2
    incf bar_flag
    rlcf LATC
    bcf LATC, 6 ;clear bit 6
    btfsc bar_flag,0 ; bar? yerine koy
    bsf	  LATC,5

    return
moveBallsD:
    btfsc LATD, 5
    call barTestD

    bcf STATUS, 0 ;clear carry bit
    btfsc bar,3
    incf bar_flag
    rlcf LATD
    bcf LATD, 6 ;clear bit 6
    btfsc bar_flag,0 ; bar? yerine koy
    bsf	  LATD,5

    return

barTestA:
    btfss bar, 0
    call decrHP
    return
barTestB:
    btfss bar, 1
    call decrHP
    return
barTestC:
    btfss bar, 2
    call decrHP
    return
barTestD:
    btfss bar, 3
    call decrHP
    return

decrHP:
    decf HP
    btfsc STATUS,2
    call gameOver
    return
    ;call updateDisplay

gameOver:
    bsf gameover, 0
    return


maindisplay1:

    clrf PORTH
    clrf PORTJ
    clrf TRISH
    clrf TRISJ

    movlw b'00001000'
    movwf PORTH
    movlw b'01101101' ; seven segment 5
    movwf LATJ


    btfsc PORTG, 0
    goto RG0pressed
    call maindisplay2

    return


maindisplay2:

    clrf PORTH
    clrf PORTJ
    clrf TRISH
    clrf TRISJ


    movlw b'00000001'
    movwf PORTH
    movlw b'00000110' ; seven segment 1
    movwf LATJ

    btfsc PORTG, 0
    goto RG0pressed
    goto maindisplay1

    return

startGame:
    ;turn on where the bar is
    movlw b'00100000'
    movwf LATA
    movwf LATB
    bsf bar, 0
    bsf bar, 1

    ;save TMR0 and init HP and level
    movlw 05h
    movwf HP, 0
    movlw 01h
    movwf level,0

    call maindisplay1

    goto RG0pressed

RG0pressed:
    btfss PORTG, 0
    goto RG0pressed
    movff TMR1L, ballgen1low
    movff TMR1H, ballgen1high
    goto main

RG2pressed:
    BTFSC PORTG,2
    goto RG2pressed
moveRight:
    btfsc bar, 0 ; ship is at RA5-RB5
    goto moveRightA

    btfsc bar, 1 ; ship is at RB5-RC5
    goto moveRightB

    goto mainloop ; ship is at RC5-RD5, do nothing
moveRightA:
    bcf LATA, 5
    bcf bar, 0
    bsf LATC, 5
    bsf bar, 2
    goto mainloop
moveRightB:
    bcf LATB, 5
    bcf bar, 1
    bsf LATD, 5
    bsf bar, 3
    goto mainloop

RG3pressed:
    BTFSC PORTG,3
    goto RG3pressed

moveLeft:
    btfsc bar, 3 ; ship is at RC5-RD5
    goto moveLeftD

    btfsc bar, 2 ; ship is at RB5-RC5
    goto moveLeftC

    goto mainloop ; ship is at RA5-RB5, do nothing
moveLeftD:
    bcf LATD, 5
    bcf bar, 3
    bsf LATB, 5
    bsf bar, 1
    goto mainloop
moveLeftC:
    bcf LATC, 5
    bcf bar, 2
    bsf LATA, 5
    bsf bar, 0
    goto mainloop

 display1:

    clrf PORTH
    clrf PORTJ
    clrf TRISH
    clrf TRISJ

    movlw b'00001000'
    movwf PORTH
    call displayHP
    return

display:

    movlw b'00000001'
    movwf PORTH
    call displayLevel
    return

displayHP:
    movf HP, 0, 0 ; move HP to wreg
    sublw 01h
    btfsc STATUS, Z
    movlw b'00000110' ; seven segment 1
    btfsc STATUS, Z
    movwf LATJ

    movf HP, 0, 0 ; move HP to wreg
    sublw 02h
    btfsc STATUS, Z
    movlw b'01011011' ; seven segment 2
    btfsc STATUS, Z
    movwf LATJ

    movf HP, 0, 0 ; move HP to wreg
    sublw 03h
    btfsc STATUS, Z
    movlw b'01001111' ; seven segment 3
    btfsc STATUS, Z
    movwf LATJ

    movf HP, 0, 0 ; move HP to wreg
    sublw 04h
    btfsc STATUS, Z
    movlw b'01100110' ; seven segment 4
    btfsc STATUS, Z
    movwf LATJ

    movf HP, 0, 0 ; move HP to wreg
    sublw 05h
    btfsc STATUS, Z
    movlw b'01101101' ; seven segment 5
    btfsc STATUS, Z
    movwf LATJ

    clrf PORTH
    clrf PORTJ
    clrf TRISH
    clrf TRISJ

    return

displayLevel:
    movf level, 0, 0 ; move HP to wreg
    sublw 01h
    btfsc STATUS, Z
    movlw b'00000110' ; seven segment 1
    btfsc STATUS, Z
    movwf PORTJ

    movf level, 0, 0 ; move HP to wreg
    sublw 02h
    btfsc STATUS, Z
    movlw b'01011011' ; seven segment 2
    btfsc STATUS, Z
    movwf PORTJ

    movf level, 0, 0 ; move HP to wreg
    sublw 03h
    btfsc STATUS, Z
    movlw b'01001111' ; seven segment 3
    btfsc STATUS, Z
    movwf PORTJ



     call display1

    return

main:
    clrf TMR0
    bsf  T0CON, 7    ;Enable Timer0 by setting TMR0ON to 1
    call generateRondomBall
    decf level1_neccessary_ball
mainloop:
    call display

    btfsc PORTG, 2
    goto RG2pressed

    btfsc PORTG, 3
    goto RG3pressed

    btfsc gameover, 0
    goto init
    goto mainloop

isr:
    btfsc   INTCON, 2		;Is this a timer interrupt?
    goto    timer0_interrupt	;Yes. Goto timer interrupt handler part
    RETFIE

timer0_interrupt:
    movf    level,W  ;current level stored in W
    sublw   b'00000011'	    ;is it level 3 check
    btfsc   STATUS, Z	    ;Zero bit clear check
    call level3_interrupt
    movf    level,W  ;current level stored in W
    sublw   b'00000010'	    ;is it level 2 check
    btfsc   STATUS, Z	    ;Zero bit clear check
    call level2_interrupt
    movf    level,W  ; current level stored in W
    sublw   b'00000001'	    ; is it level 1 check
    btfsc   STATUS, Z	    ;Zero bit clear check
    call    level1_interrupt
    call    timer0_interrupt_exit
    RETFIE

 level1_interrupt:
    decfsz	timer0_counter1,1,0   ;decrement 76 if it is not zero no interrupt
    goto endlevel1		    ;Not zero

    ; random top generation and open next leds code goes here
    call moveBalls
    call generateRondomBall

    movlw   d'76' ; 76 x 256 x 256 x0.1 =500ms
    movwf   timer0_counter1
    dcfsnz	level1_neccessary_ball,1,0
    incf level; if 5 ball generate ended current level need to be incremented
endlevel1:
    return
level3_interrupt:
    decfsz timer0_counter3,1,0   ;decrement 53 if it is not zero no interrupt
    goto endlevel3		    ;Not zero
    btfsc   end_flag,0
    goto    lastmoves

    ; ------------------------random top generation and open next leds code goes here-------------------------------------------
    call moveBalls
    call generateRondomBall


    movlw   d'53' ; 53 x 256 x 256 x0.1 =350ms
    movwf   timer0_counter3
    dcfsnz  level3_neccessary_ball,1,0
    incf    end_flag; if 10 ball generate ended current level need to be incremented
endlevel3:
    return
lastmoves:
    movlw   d'53' ; 53 x 256 x 256 x0.1 =350ms
    movwf   timer0_counter3
     call moveBalls
    dcfsnz five_move
    goto init
    return

level2_interrupt:
    decfsz timer0_counter2,1,0   ;decrement 61 if it is not zero no interrupt
    goto endlevel2		    ;Not zero

    ; random top generation and open next leds code goes here
    call moveBalls
    call generateRondomBall

    movlw   d'61' ; 61 x 256 x 256 x0.1 =400ms
    movwf   timer0_counter2
    dcfsnz level2_neccessary_ball,1,0
    incf level; if 10 ball generate ended current level need to be incremented
endlevel2:
	return

timer0_interrupt_exit:
    bcf	    INTCON, 2		    ;Clear TMROIF
    clrf	    TMR0
    return

save_registers:
    movwf 	w_temp          ;Copy W to TEMP register
    swapf 	STATUS, w       ;Swap status to be saved into W
    clrf 	STATUS          ;bank 0, regardless of current bank, Clears IRP,RP1,RP0
    movwf 	status_temp     ;Save status to bank zero STATUS_TEMP register
    movf 	PCLATH, w       ;Only required if using pages 1, 2 and/or 3
    movwf 	pclath_temp     ;Save PCLATH into W
    clrf 	PCLATH          ;Page zero, regardless of current page
    return

restore_registers:
    movf 	pclath_temp, w  ;Restore PCLATH
    movwf 	PCLATH          ;Move W into PCLATH
    swapf 	status_temp, w  ;Swap STATUS_TEMP register into W
    movwf 	STATUS          ;Move W into STATUS register
    swapf 	w_temp, f       ;Swap W_TEMP
    swapf 	w_temp, w       ;Swap W_TEMP into W
    return

    delay:
    movlw 0xFF
    movwf d1
    movwf d2

    delay0
    decfsz d1
    goto delay0

    delay1
    decfsz d2
    goto delay1

    return


end
