.section .text

.global _Reset
.global c_entry

_Reset:
    // initialize register by sections addresses
    ldr sp, =0x40200000
    // start to c_entry function
    bl c_entry
    mov r0, #0
    bl _Exit

_Exit: // put return code in r0
    bl _Exit


.section .note.GNU-stack,"",%progbits
