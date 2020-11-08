.include "io.inc65"
.include "macros_65C02.inc65"

.zeropage

.smart		on
.autoimport	on
.case		on
.debuginfo	off
.importzp	sp, sreg, regsave, regbank
.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
.macpack	longbranch


.export _ym_write_data
.export _ym_write_reg
.export _ym_init
.export _ym_setreg


.code


_ym_setreg:
            jsr pusha
            ldy #$01
            lda (sp),y
            JSR _ym_write_reg
            jsr _delay
            LDY #$00
            LDA (sp),y
            JSR _ym_write_data
            jmp incsp2

_ym_init:
            LDA #$FF
            STA VIA_DDRA
            STA VIA_DDRB
            LDA #%11111100
            STA VIA_ORB
            jsr _delay
            LDA #%11111000
            STA VIA_ORB
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            jsr _delay2
            LDA #%11111100
            STA VIA_ORB
            RTS

_ym_write_data:
            PHA
            LDX #%11110101
            STX VIA_ORB
            jsr _delay
            PLA
            STA VIA_ORA
            JSR _delay
            LDX #%11010101
            STX VIA_ORB
            jsr _delay
            LDX #%11110101
            STX VIA_ORB
            jsr _delay
            LDX #%11111100
            STX VIA_ORB
            RTS

_ym_write_reg:  PHA
                LDX #%11110100
                STX VIA_ORB
                jsr _delay
                PLA
                STA VIA_ORA
                jsr _delay
                LDX #%11010100
                STX VIA_ORB
                jsr _delay
                LDX #%11110100
                STX VIA_ORB
                jsr _delay
                LDX #%11111100
                STX VIA_ORB
                RTS

_delay:					LDX #$1
_delay1:				DEX
                BNE _delay1
                RTS
_delay2:					LDX #$FF
_delay3:				DEX
                BNE _delay3
                RTS
