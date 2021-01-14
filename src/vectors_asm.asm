; ---------------------------------------------------------------------------
; vectors.s
; ---------------------------------------------------------------------------
;
; Defines the interrupt vector table.

.import   _main
.import   _nmi_int
.import   _irq_int

.segment  "VECTORS"

.addr      _nmi_int    ; NMI vector
.addr      _main       ; Reset vector
.addr      _irq_int    ; IRQ/BRK vector
