#include "pl011_uart.h"
#include "pl031_rtc.h"
#include "utils.h"
#include "auth.h"

#define  UART0_ADDR 0x09000000
#define  RTC_ADDR 0x09010000
#define FW_CFG_ADDR 0x09020000

volatile unsigned int startup_time;

void print_blackdog() {
     sleep(30000000);
     uart0_putstr("      ▓▓▓▓▓██████▓▓▓▓▓███████████████████▓▓██████████▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     \n");     
     sleep(30000000);
     uart0_putstr("   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓█████████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    \n");
     sleep(30000000);
     uart0_putstr(" ▓▓▓▓▓▓████████████▓▓▓███████████░░████████████████████▓░█▓█▓▓▓▓▓▓███████▓▓█▓▓██▓▓▓▓▓▓██▓▓▓ \n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓████████▓▓███████▓▓▓▓███▓▓░█░▓██████░░░███░▒█████░█░▓███░░█▓▓▓██████████▓▓▓▓▓▓▓▓██▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓█████▓▓░░█▓▓▓█████▓▓▓███░░░█░█░░█░░██░░░░▓▓▓░░███░█░█░░░░█░░░▓▓▓███████░░▓▓███▓▓▓██▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓████████░██░░█▓▓▓▓░▓▓▓▓▓░██░█░░█░░▓██▓░░░░░▓▓▓▓▓▒░██░░█▓█░█░░░░▓▓▓▓▓▓░░▒█░█▓▓█▓█████▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓█████████▓░█░██░░██░░▓▓▓░░█▓█░█▓░█░░█▓░░░░░░█▓▓▓░░█░░█░█▓▓█░░░░░▓▓▓░░██░█░░█▓▓▓▓▓████▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓███████████░░██░▓█░░░░░░░░█▒▓█░██▓░█░░░░░░░░░▓░░░░█░░███░███░░░░░▒░░██░█▓▓░████▓▓▓▓████▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓██████▓░█▓█▓░▓▓▓░█░█░░░░░█░██░████░░█░░░░░░░░░░░░█░░████░██░█░░░░░█▒█░█▓▓░░█░█░░▓▓▓▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓█████▓░░▓▓░█░████░██▓█░█████░██░██░▓██████▓▓▓██████░██░██░██░██░▓▓█████▓▓░▓▓███░░▓▓▓██▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓█████▓░░▒▓▓▓░░██████▓░░░░░██░██████░░░░░░░░░░░░░░░░██████░██▓░░░░░██████▓░▓▓▓▓░░░▓▓▓████▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓██████░░░░░░░░██░░░░░░███░███▒██▓░█████░░░░░░░░░████▓░███░██░░███░░░░░███░░░░░░░░▓▓▓▓███▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓███▓▓▒▒░░░░░█░░░░░░░░░░░░░█████████▓░░░░██░░░██░░░██████████░░░░░░░░░░░░░██░░░░░▓▓▓▓▓▓█▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓████▒▓░░░░█░░░█░░░░░░░░░░▓██████████░░░░░▓███░░░░░███████████░░░░░░░░░░█░░░██░░▓▓▓▓░▓▓▓█▓▓\n");
     sleep(30000000);
     uart0_putstr("████▓▓▓░░▓█░▒░██░▓░░███████░████░░░░░░░██░█░██░▓░░█░░░░░░░████░▒██████░░█░██░░░█░░▓▓░░▓▓███▓\n");
     sleep(30000000);
     uart0_putstr("███▓█▓░░░██████░█▓██▒▒░▒▓██████░██████░░░█████░█░█░░██████░███████▒▒▒▒██▓█░███░█░░░░░░▓▓███▓\n");
     sleep(30000000);
     uart0_putstr("████░░░░░░██▒░░░▓███▒░░▒██░░██████▒▒▒░██████████████▒▒░▒███████░██▒░░░▒███░░░░██░░░░▓▓▓▓█▓▓▓\n");
     sleep(30000000);
     uart0_putstr("█░░░███░░░░░░░░░░░███████░▓█████░█▓▒▒▒▒██░▓▓▓░▓▓░██▒▒░▒▒█▒░█████░░█████▓░░░░░░░░░░███░░░█▓▓▓\n");
     sleep(30000000);
     uart0_putstr("░█▓░░░█▓█░░░░░░░░██░██░░██████░█░░██████░░░░░░░░░░░█████░░█░███████▓██░███░░░░░░███░░░██░░▓▓\n");
     sleep(30000000);
     uart0_putstr("░░█████░░░████░▒███▓░█████████░▒█████░▓░░██░░░░██▒░█░██████░███░░░░████░████▓░░▓░█████▓█░▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▒░███████░░████████░░██░░██████░░███░█░░░█████████░░█░████░██████░██░░░░░▒░░░░████████▓█░▓▓█\n");
     sleep(30000000);
     uart0_putstr("█░░█░░████░░███████░░█▒░██░░████░░█████░░░░█████░░░▒█▓██▓░████░██░▓██░░█░█░░█░███░░░░░█░░▓▓█\n");
     sleep(30000000);
     uart0_putstr("██░░█░█░██▓█████████████░███▒████░████░████████████░████░███▓█░░█████████████░▒█▓░░█░█░░███▓\n");
     sleep(30000000);
     uart0_putstr("███░░█░█░░░█░░░███░█░████░████████▓█░████████████████░███████░███░░███▓████░██░░░░███░▓██▓▓▓\n");
     sleep(30000000);
     uart0_putstr("█████░░░░░░░░░░░█░▓░█████░███████████░█░░█░█░██░█░░██░███████░█████░░░█░░█░░░░░░░░░░░██░█▓▓▓\n");
     sleep(30000000);
     uart0_putstr("██▓░██░░░░░░░░░█░█░███░█░▓███████████░██░████████░██░█████████░██░███░░░░▓█████░░░░░█░░░░▓▓▓\n");
     sleep(30000000);
     uart0_putstr("███▓█▓░░░░░░░░█░▓░███░█░████▓░░██████░████░░░█░░████░██████░░███░██░████████▓░░░░██████░▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓░░░▓███░░░░██░░█░███▓░█████████░██░█░░░█░░█░██░█████████░██░▒█░██████░░░░██████░░█▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("███▓░░░█░░▒░░█████░░█░███▓███████████░██░█░░░█░░█░██░███████████░██░█░░██░█░░██░░░░░█░█▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓█▓▓░░█░▓░███▓███░█░░███░░███████████░████░░░▓░░████░██████░████░░██░░█░▓█▒█▒█░░░░░▓▒░▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓░█░█░█░░█████░░██▓▓░░░░███▒█░████░░█░██░░░░██░█▓▓████▓█████░░░░▒██░░█████░░░░░░░░░▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓░█░░░█░░░█████████░░░░░░███░█████░░█▒██████▓█░█░█████▒▓█▓▓░░░░░░▓████████░░░░░░░░░▓▓▓██▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓░█▒▓██░░░░░░░░░░░░░░░░░░░▓██░█████░░█▓░░░░▒░▓█░░█████▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓██▓▓░░█░░░▓███░░░░░░░▓▓░░░░░░▓▓█░██████▒░░████░░░████▓░██▓▓░░░░██░░░░░░░░████░░░░░░▓▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓▓░░░░░░░█▓▓▓░░░░░░█▓░░░░░▓▓███████▓▓███████▓▓███░███▓▓░░░░▓██░░░░░████░░░░░░█▓▓▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓░░▓▓█░░░░░▓▓▓▓░░░░░▓▓░▓░░░░▓███░▓████████████▓███░████░░░░░▓▓▓░░░░▓███░░░▓▓▓▓▓░░▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓▓░░░░░░░░░▓██░░░░░░░░▓░░░░░▓▓▓░░▓██████████░░▓▓███▓▓▓░░░▓▓▓▓▓░░░░▓███░░░░░░░░█▓▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓▓▓▓░░░░░░░▓▓▓▓░░░░▓░░▓▓░░░░░▓▓▓▓██████████▓░░░▓▓▓▓▓░░▓▓▓▓▓▓▓░░░░▓▓▓▓█░░░░░░▓▓▓▓▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓▓░▓▓▓▓░░░░▓▓▓▓▓▓▓▓▓░░▓▓▓▓▓░░▓▓▓███░░▓▓▓▓▓░░░▓░█▓▓▓░░▓▓▓▓▓▓█▓▓▓▓▓▓▓▓▓░░░░░▓▓▒░▓▓▓▓▓█▓▓▓\n");
     sleep(30000000);
     uart0_putstr("▓▓▓▓▓▓▓▓█░▒▓▓░░░░░█▓▓▓▓██▓░░▓▓▓▓▓░▓▓▓░░░▓▓▓▓▓░░░░▓▓░░█▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▓▓▓██▓▓▓▓▓▓▓▓▓▓\n");
     sleep(30000000);
     uart0_putstr(" ▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░█▓▓▓▓▓▓▓▓▓▒▓░░▓▓▓▓▓░░░█▓▓▓▓░░▓▓░▓▓▓▓▓▓█▓▓██░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓ \n");
     sleep(30000000);
     uart0_putstr("   ▓▓▓▓▓▓▓▓▓░░█▓▓▓▓▓▓░░░░░░▓▓▓▓▓▓▓▓▓░░▓▓▓▒░░█▓▓▓▓▓░░██░░▓▓▓▓▓▓█░░░░░░▓█▓▓▓▓▓▓░▓▓▓▓▓▓▓▓▓▓▓   \n");
     sleep(30000000);
     uart0_putstr("     ▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░░░█▓▓▓▓░░▓▓▓▓░░▓▓▓▓▓▓█░░░▓▓▓██▓▓░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▓▓▓      \n");
}

void initialize() {
     uartInit((volatile unsigned int *)UART0_ADDR);
     // VIRT_UART0
     uart0_putstr("[STARTUP] : Courant d'alimentation détecté.\n");
     sleep(100000000);
     uart0_putstr("[STARTUP] : Réveil du système...\n");
     sleep(100000000);
     uart0_putstr("[STARTUP] : Lancement du chargeur de démarrage «BlackDog666»...\n");
     sleep(300000000);
     uart0_putstr("\t[0x40000000] : SRAM address\n");
     uart0_putstr("\t[0x40000000] : bootloader sector\n");
     uart0_putstr("\t[0x40200000] : stack sector\n");

     uart0_putstr("[BOOTLOADER] : Initialisation des composantes systèmes :\n");
     sleep(100000000);
     uart0_putstr("[BOOTLOADER] : \tinitialisation de l'interface VIRT_UART0 (0x09000000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_RTC
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_RTC (0x09010000)...");
     rtcInit((volatile unsigned int *)RTC_ADDR);
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     startup_time = my_rtc->RTCDR;
     uart0_putstr("               \t\tEPOCH=");
     uart0_putint(startup_time);
     uart0_putstr(" sec\n");
     char date[20];
     uart0_putstr("               \t\tDATE format=");
     epoch_to_datestr(date, startup_time);
     uart0_putstr(date);
     uart0_putstr("\n");
     // VIRT_FW_CFG
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_FW_CFG (0x09020000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_GPIO
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_GPIO (0x09030000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_UART1
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_UART1 (0x09040000)...");
     sleep(100000000);
     uart0_putstr(" [UNUSED]\n");
     // VIRT_SMMU
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_SMMU (0x09050000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_PCDIMM_ACPI
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_PCDIMM_ACPI (0x09070000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_ACPI_GED
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_ACPI_GED (0x09080000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_PVTIME
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_PVTIME (0x090a0000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_MMIO
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_MMIO (0x0a000000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_PLATFORM_BUS
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_PLATFORM_BUS (0x0c000000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_SECURE_MEM
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_SECURE_MEM (0x0e000000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // VIRT_PCIE_MMIO
     uart0_putstr("[BOOTLOADER] : \tvérification de VIRT_PCIE_MMIO (0x10000000)...");
     sleep(100000000);
     uart0_putstr(" [OK]\n");
     // Fin d'initialisation
     uart0_putstr("[BOOTLOADER] [INFO] : \tFin de l'initialisation des composantes à ");
     volatile unsigned int endinit_time = my_rtc->RTCDR;
     epoch_to_datestr(date, endinit_time);
     uart0_putstr(date);
     uart0_putstr("  (");
     uart0_putint(endinit_time - startup_time);
     uart0_putstr(" secondes)\n");
     sleep(100000000);
     uart0_putstr("[BOOTLOADER] : Entrée du «BlackDog» dans la pièce");
     sleep(300000000);
     uart0_putchar('.');
     sleep(300000000);
     uart0_putchar('.');
     sleep(300000000);
     uart0_putchar('.');
     sleep(300000000);
     uart0_putstr("\n");
     print_blackdog();
     sleep(100000000);
     uart0_putstr("[BOOTLOADER] : \tDes flammes jaillisent !!!\n");
     uart0_putstr("[BOOTLOADER] : \tDes flammes jaillisent !!!\n");
     uart0_putstr("[BOOTLOADER] : \tDes flammes jaillisent !!!\n");
     sleep(500000000);
     volatile unsigned int blackdog_time = my_rtc->RTCDR;
     epoch_to_datestr(date, blackdog_time);
     date[10] = 0;
     uart0_putstr("[BOOTLOADER] [INFO] : Le «BlackDog» fait son apparition le ");
     uart0_putstr(date);
     uart0_putstr(" à ");
     uart0_putstr(&date[11]);
     uart0_putstr("\n\n");
     sleep(100000000);
}    

void main() {
     uart0_putstr("Ggrrhh Rrrrhh Arggh (mot de passe) >>>");

     char input[32];
     uart0_getstr(input, 32);
     // uart0_putstr("\n");

     uart0_putstr("W4f w4f ! : ");
     uart0_putstr(input);
     uart0_putstr("\n");
     uart0_putstr("Vous lui jetez un os");
     sleep(300000000);
     uart0_putchar('.');
     sleep(300000000);
     uart0_putchar('.');
     sleep(300000000);
     uart0_putchar('.');
     sleep(300000000);
     uart0_putstr("\n");
     if (authent(input)) {
          uart0_putstr("Incroyable ! Le «BlackDog» adore ça, tout content de son nouveau jouet il ne fait plus attention à vous. Vous en profitez pour passer la porte.\n");
          uart0_putstr("\e[32mLe flag est formaté comme ceci : «AMSI{mot_de_passe_que_vous_avez_entré}»\n\e[0m\n"); 
     }
     else {
          uart0_putstr("Il n'a pas l'air d'apprécier le parfum. Les trois têtes vous regardent, se demandant quel goût peut avoir un être humain. \n");
          uart0_putstr("\e[31mVous êtes mort ×_×\n\e[0m\n");
     }
}

void shutdown() {
     shutdown();
}

int c_entry() {
     initialize();
     main();
     shutdown();
}
