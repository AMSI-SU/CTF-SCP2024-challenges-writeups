

# Compilation 

Les fichiers sources "./src/" sont compilés suivant le fichier Makefile.
La fonction d'authentification est offusquée avec "obfuscator-llvm" : auth.c
Le fichier de "démarrage" du bootloader est : startup.s
C'est un wrapper vers la fonction c_entry du code principal dans : main.c
Le fichier d'édition de lien est : main.ld

### Compiler
    $ make

### Nettoyer
    $ make clean

### Émuler le firmware
    $ make run

### Tout en une commande
    $ make tout

# Ecrire son propre firmware

> board : qemu_arm (virt)

# Problèmes rencontrer 

### Éteindre la VM depuis l'exécution du firmware ?



# Sources

* https://learn.arm.com/learning-paths/embedded-systems/bare-metal/retarget/
* https://documentation-service.arm.com/static/5e8e36c2fd977155116a90b5
* https://cjhackerz.net/posts/understanding-how-bootloader-works-by-creating-your-own-firmware/
* https://de-engineer.github.io/Understanding-booting-process-and-writing-own-os/#writing-our-bootloader
* https://stackoverflow.com/questions/15999333/using-a-uart-with-a-arm-cpu
* https://stackoverflow.com/questions/63021736/how-to-echo-the-data-in-the-uart-in-arm-cortex-m3
>
* https://github.com/qemu/qemu/blob/master/hw/arm/virt.c
* https://github.com/qemu/qemu/blob/master/hw/rtc/pl031.c
* https://documentation-service.arm.com/static/5e8e36c2fd977155116a90b5




