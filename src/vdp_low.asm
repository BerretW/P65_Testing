.include "io.inc65"
.include "macros_65c02.inc65"

.zeropage

radek:			.res 1


.export _vdp_wr_reg

.zeropage
.smart		on
.autoimport	on
.case		on
.debuginfo	off
.importzp	sp, sreg, regsave, regbank
.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
.macpack	longbranch

.globalzp tmpstack



.code


;****************************************
;* _vdp_wr_reg
;* Write to Register A the value X
;* Input : A - Register Number, X - Data
;* Output : None
;* Regs affected : P
;****************************************
_vdp_wr_reg:
	sta VDP_MODE1
; Extra nop for fast CPU
	nop
	nop
	nop
	nop
	LDY #$00
	LDA (sp),y
	ora #$80
	sta VDP_MODE1
	eor #$80
	rts
