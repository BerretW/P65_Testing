CHROUT	:=	$FF00	;	void	;	print CHAR from regA
CHRIN	:=	$FF03	;	char	;	get CHAR from buffer to regA
PRNTLN	:=	$FF06	;	void	;	put new line and a string with start address in regA and regX "lda #<(STRING),ldx #>(STRING),jsr PRNTLN"
PRNT	:=	$FF09	;	void	;	put a string with start address in regA and regX "lda #<(STRING),ldx #>(STRING),jsr PRNTLN"
PRNL	:=	$FF0C	;	void	;
SETBNK	:=	$FF0F	;	void	;	set bank to number from regA
GETBNK	:=	$FF12	;	char	;	get bank number to regA
SNINIT	:=	$FF15	;	void	;	Initialize SN76489 chipwith mute
SNWRT	:=	$FF18	;	void	;	write data from regA to sn76489
SHDLY	:=	$FF1B	;	void	;	very short delay
RST	:=	$FF1E	;	void	;	reset to bootloader
KBINPUT	:=	$FF21	;	char	;
KBGET	:=	$FF24	;	char	;
KBSCAN	:=	$FF27	;	char	;
KBINIT	:=	$FF2A	;	void	;
INPUT	:=	$FF2D	;	char	;

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
