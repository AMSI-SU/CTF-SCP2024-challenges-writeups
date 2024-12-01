// https://learn.arm.com/learning-paths/embedded-systems/bare-metal/retarget/
// https://documentation-service.arm.com/static/5e8e36c2fd977155116a90b5

#ifndef __uart_h
#define __uart_h

#include "utils.h"

struct pl011_uart {
        volatile unsigned int UARTDR;        // +0x00
        volatile unsigned int UARTECR;       // +0x04
  const volatile unsigned int unused0[4];    // +0x08 to +0x14 reserved
  const volatile unsigned int UARTFR;        // +0x18 - RO :               |  RI  | TXFE | RXFF | TXFF | RXFE | BUSY | DCD | DSR | CTS |
  const volatile unsigned int unused1;       // +0x1C reserved
        volatile unsigned int UARTILPR;      // +0x20
        volatile unsigned int UARTIBRD;      // +0x24
        volatile unsigned int UARTFBRD;      // +0x28
        volatile unsigned int UARTLCR_H;     // +0x2C
        volatile unsigned int UARTCR;        // +0x30
        volatile unsigned int UARTIFLS;      // +0x34
        volatile unsigned int UARTIMSC;      // +0x38
  const volatile unsigned int UARTRIS;       // +0x3C - RO
  const volatile unsigned int UARTMIS;       // +0x40 - RO
        volatile unsigned int UARTICR;       // +0x44 - WO
        volatile unsigned int UARTDMACR;     // +0x48
};

volatile struct pl011_uart* my_uart;

void uartInit(volatile unsigned int *addr) {
    my_uart = (struct pl011_uart *)addr;

    // Ensure UART is disabled
    my_uart->UARTCR  = 0x0;

    // Set UART 0 Registers
    my_uart->UARTECR   = 0x0;        // Clear the receive status (i.e. error) register
    my_uart->UARTLCR_H = 0x60;

    my_uart->UARTIBRD = 0x27;
    my_uart->UARTFBRD = 0x09;

    my_uart->UARTIMSC = 0x0;         // Mask out all UART interrupts
    my_uart->UARTICR  = 0x07FF;      // Clear interrupts
    my_uart->UARTCR  = 0x0 | 0x01 | 0x0100 | 0x0200;
}
// WRITE
void uart0_putchar(const char c) {
    // Wait until FIFO or TX register has space
    while ((my_uart->UARTFR & 0x20) != 0x0);
    // Write packet into FIFO/tx register
    my_uart->UARTDR = (volatile unsigned int)c;
    // Model requires us to manually send a carriage return
    if (c == '\n') {
        while ((my_uart->UARTFR & 0x20) != 0x0);
        my_uart->UARTDR = '\r';
    }
}
void uart0_putstr(const char *s) {
    while(*s != 0)
        uart0_putchar(*s++);
}
void uart0_putbyte(const char c) {
    uart0_putchar('0');
    uart0_putchar('x');
    char left = c>>4 & 0x0f;
    uart0_putchar(itoh(c>>4 & 0x0f));
    uart0_putchar(itoh(c & 0x0f));
}
void uart0_putint(volatile unsigned int n) {
    if (n < 10) {
        uart0_putchar('0' + n); // Convertir le chiffre en caractère et l'afficher
    } else {
        // Appel récursif pour afficher les chiffres précédents
        uart0_putint(n / 10);
        uart0_putchar('0' + (n % 10)); // Afficher le chiffre des unités
    }
}

// READ
char uart0_getchar() {
    while((my_uart->UARTFR & 0x10) != 0x0);
    return (char)my_uart->UARTDR;
}
int uart0_getstr(char *buffer, int size) {
    int i;
    for (i = 0; i<size; i++) {
        buffer[i] = uart0_getchar();
        uart0_putchar(buffer[i]);
        if (buffer[i] == 0 || buffer[i] == '\r' || buffer[i] == '\n') {
            break;
        }
    }
    uart0_putchar('\n');
    buffer[i] = 0;
    return i+1;
}

#endif