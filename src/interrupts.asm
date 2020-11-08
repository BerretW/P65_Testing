
; ---------------------------------------------------------------------------
; interrupt.s
; ---------------------------------------------------------------------------
;
; Interrupt handler.
;
; Checks for a BRK instruction and returns from all valid interrupts.

;.import   _stop
.import   _acia_putc
.export   _irq_int, _nmi_int

.segment  "CODE"

.PC02                             ; Force 65C02 assembly mode

; ---------------------------------------------------------------------------
; Non-maskable interrupt (NMI) service routine

_nmi_int:   CLI
            RTI                    ; Return from all NMI interrupts

; ---------------------------------------------------------------------------
; Maskable interrupt (IRQ) service routine
_irq_int:   SEI
            PHA
            LDA #41
            jsr _acia_putc
            PLA
            RTI

;_irq_int1:  PHX                    ; Save X register contents to stack
;           TSX                    ; Transfer stack pointer to X
;           PHA                    ; Save accumulator contents to stack
;           INX                    ; Increment X so it points to the status
;           INX                    ;   register value saved on the stack
;           LDA $100,X             ; Load status register contents
;           AND #$10               ; Isolate B status bit
;           BNE break              ; If B = 1, BRK detected

; ---------------------------------------------------------------------------
; IRQ detected, return

irq:       PLA                    ; Restore accumulator contents
           PLX                    ; Restore X register contents
           RTI                    ; Return from all IRQ interrupts

; ---------------------------------------------------------------------------
; BRK detected, stop

;break:     JMP _stop              ; If BRK is detected, something very bad
                                  ;   has happened, so stop running
