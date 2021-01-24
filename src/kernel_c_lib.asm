CHROUT	:=	$FF00	;	VOID	;	print CHAR from regA
CHRIN	:=	$FF03	;	CHAR	;	get CHAR from buffer to regA
PRNTLN	:=	$FF06	;	VOID	;	put new line and a string with start address in regA and regX "lda #<(STRING),ldx #>(STRING),jsr PRNTLN"
PRNT	:=	$FF09	;	VOID	;	put a string with start address in regA and regX "lda #<(STRING),ldx #>(STRING),jsr PRNTLN"
PRNL	:=	$FF0C	;	VOID	;
SETBNK	:=	$FF0F	;	VOID	;	set bank to number from regA
GETBNK	:=	$FF12	;	CHAR	;	get bank number to regA
SNINIT	:=	$FF15	;	VOID	;	Initialize SN76489 chipwith mute
SNWRT	:=	$FF18	;	VOID	;	write data from regA to sn76489
SHDLY	:=	$FF1B	;	VOID	;	very short delay
RST	:=	$FF1E	;	VOID	;	reset to bootloader
KBINPUT	:=	$FF21	;	CHAR	;
KBGET	:=	$FF24	;	CHAR	;
KBSCAN	:=	$FF27	;	CHAR	;
KBINIT	:=	$FF2A	;	VOID	;
INPUT	:=	$FF2D	;	CHAR	;
DLY	:=	$FF30	;	VOID	;

.export	_CHROUT
.export	_CHRIN
.export	_PRNTLN
.export	_PRNT
.export	_PRNL
.export	_SETBNK
.export	_GETBNK
.export	_SNINIT
.export	_SNWRT
.export	_SHDLY
.export	_RST
.export	_KBINPUT
.export	_KBGET
.export	_KBSCAN
.export	_KBINIT
.export	_INPUT
.export	_DLY






.segment "CODE"

_CHROUT: 	JMP	CHROUT
_CHRIN: 	JMP	CHRIN
_PRNTLN: 	JMP	PRNTLN
_PRNT: 	JMP	PRNT
_PRNL: 	JMP	PRNL
_SETBNK: 	JMP	SETBNK
_GETBNK: 	JMP	GETBNK
_SNINIT: 	JMP	SNINIT
_SNWRT: 	JMP	SNWRT
_SHDLY: 	JMP	SHDLY
_RST: 	JMP	RST
_KBINPUT: 	JMP	KBINPUT
_KBGET: 	JMP	KBGET
_KBSCAN: 	JMP	KBSCAN
_KBINIT: 	JMP	KBINIT
_INPUT: 	JMP	INPUT
_DLY: 	JMP	DLY
