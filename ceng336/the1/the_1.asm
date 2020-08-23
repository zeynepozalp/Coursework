#include <p18f8722.inc>
CONFIG OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

UDATA_ACS
    t1 res 1	; used in delay
    t2 res 1	; used in delay
    t3 res 1	; used in delay
    op res 1    ; 0 for add, 1 for sub
    state1 res 1; is RE3 pressed
    state2 res 1; is RE4 pressed
    val1 res 1  ; value from portb
    val2 res 1  ; value from portc
    result res 1; result of val1 op val2

org 0

call main

clearregs
    CLRF    LATA
    CLRF    LATB
    CLRF    LATC
    CLRF    LATD
    CLRF    LATE
    CLRF    LATF
    CLRF    LATG
    CLRF    LATH
    CLRF    LATJ
    clrf op
    clrf state1
    clrf state2
    clrf val1
    clrf val2
    clrf result
    CLRF    TRISA
    CLRF    TRISB
    CLRF    TRISC
    CLRF    TRISD
    CLRF    TRISE
    CLRF    TRISF
    CLRF    TRISG
    CLRF    TRISH
    CLRF    TRISJ
    movlw   b'00010000'
    movwf   TRISA

    movlw   b'00011000'
    movwf   TRISE
    return

init
    call clearregs

    movlw   b'00001111'
    movwf   LATB

    movlw   b'00001111'
    movwf   LATC

    movlw   b'11111111'
    movwf   LATD

    call DELAY

    movlw   b'00000000'
    movwf   LATB

    movlw   b'00000000'
    movwf   LATC

    movlw   b'00000000'
    movwf   LATD

    return

RA4pressed
    BTFSS PORTA,4
    return
    RA4pressedloop
	BTFSC PORTA,4
	goto RA4pressedloop
	COMF op, 1
	return

RE3pressed
    clrf state1
    BTFSS PORTE,3
    return
    RE3pressedloop
	BTFSC PORTE,3
	goto RE3pressedloop
	COMF state1, 1
	return

RE4pressed
    clrf state2, 0
    BTFSS PORTE,4
    return
    RE4pressedloop
	BTFSC PORTE,4
	goto RE4pressedloop
	COMF state2, 1
	return

addit
    movff val2, result
    additloop
	btfss val1, 0
	return
	call addit2
	rrcf val1
	goto additloop
	return
addit2
    rlncf result, 1
    INCF result, 1
    return

subst
    movf val1, 0
    cpfsgt val2
    call substBC
    cpfslt val2
    call substCB
    return

substCB
    movff val2, result
    substloopCB
	btfss val1, 0
	return
	call subst2CB
	rrncf val1
	goto substloopCB
	return
subst2CB
    rrcf result, 1
    return

substBC
    movff val1, result
    substloopBC
	btfss val2, 0
	return
	call subst2BC
	rrncf val2
	goto substloopBC
	return
subst2BC
    rrcf result, 1
    return

portBinput
	call RE3pressed
	btfsc state1, 1
	call portCinput
	call RE4pressed
	btfss state2, 1
	goto portBinput
	rlcf val1, 1    ; shift val1 by 1 bit
	incf val1, 1    ; increment val1 by 1
	cpfslt val1
	clrf val1
	goto portBinput

portCinput
        movff val1, LATB
	loopc
        call RE3pressed
	btfsc state1, 1
	call portDoutput
	call RE4pressed
	btfss state2, 1
	goto loopc
	rlcf val2, 1    ; shift val2 by 1 bit
	incf val2, 1    ; increment val2 by 1
	cpfslt val1
	clrf val1
	goto loopc

portDoutput
	call RE3pressed
	btfsc state1, 1
	call portBinput
	movff val2, LATC
	goto operate


DELAY	; Time Delay Routine with 3 nested loops
    MOVLW 82	; Copy desired value to W
    MOVWF t3	; Copy W into t3
    _loop3:
	MOVLW 0xA0  ; Copy desired value to W
	MOVWF t2    ; Copy W into t2
	_loop2:
	    MOVLW 0x9F	; Copy desired value to W
	    MOVWF t1	; Copy W into t1
	    _loop1:
		decfsz t1,F ; Decrement t1. If 0 Skip next instruction
		GOTO _loop1 ; ELSE Keep counting down
		decfsz t2,F ; Decrement t2. If 0 Skip next instruction
		GOTO _loop2 ; ELSE Keep counting down
		decfsz t3,F ; Decrement t3. If 0 Skip next instruction
		GOTO _loop3 ; ELSE Keep counting down
		return


main
    call init
    loop
	movlw 0x0F
	call RA4pressed
	call RE3pressed
	btfss state1, 1
	goto loop
	call portBinput
	operate
	btfss op, 1
	call subst
	btfsc op, 1
	call addit
	movff result, LATD
	call DELAY
	call clearregs
	goto loop
    return

end
