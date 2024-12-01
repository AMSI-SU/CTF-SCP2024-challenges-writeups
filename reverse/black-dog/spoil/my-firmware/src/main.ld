ENTRY(_Reset)

PHDRS
{
    text PT_LOAD FLAGS(5);    /* Read + Execute */
    data PT_LOAD FLAGS(6);    /* Read + Write */
}

SECTIONS
{
    . = 0x40000000;
    
    .startup . : { obj/startup.o(.text) } :text
    .text : { *(.text) } :text
    .data : { *(.data) } :data
    .bss : { *(.bss COMMON) } :data

    . = ALIGN(8);
}