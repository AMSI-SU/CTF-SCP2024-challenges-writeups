# Solution

## Autopsy
En utilisant **autopsy**, on trouve un fichier **.pcap** dans les fichiers supprimés. On peut également trouver une liste de mot de passe (dans les fichiers non-supprimés): **w0rdl1st_old.txt**

## Airecrack-ng
En utilisant **airecrack-ng**, on peut bruteforce le fichier .pcap et trouver le mot de passe Wifi:

> sudo apt install aircrack-ng
> aircrack-ng f0016696.pcap -w ./w0rdl1st_old.txt

## Output
```bash
Reading packets, please wait...
Opening f0016696.pcap

Invalid packet capture length 0 - corrupted file?
Read 1398 packets.

   #  BSSID              ESSID                     Encryption

   1  3A:02:8E:7D:03:C8  Freebox-F726              WPA (1 handshake)

Choosing first network as target.

Reading packets, please wait...
Opening f0016696.pcap

Invalid packet capture length 0 - corrupted file?
Read 1398 packets.

1 potential targets



                               Aircrack-ng 1.6 

      [00:00:13] 99224/99865 keys tested (7630.29 k/s) 

      Time left: 0 seconds                                      99.36%

                     KEY FOUND! [ GZVPQpX)c)C#B^V-599+ ]


      Master Key     : 87 CC A2 AE 7F 37 5F 79 4D 1D 71 6C C3 06 EC 9C 
                       CE 9F 0C 27 55 99 B0 8C 97 FB 4F E0 0D D7 4F 3A 

      Transient Key  : E9 78 BF CD 39 11 CB 24 6F D2 9E A4 35 40 94 7F 
                       88 E5 01 76 2B DE E4 3E 03 09 B0 A0 2C 01 9C A8 
                       7C 96 F1 C9 08 73 45 59 E0 5E FE 28 BE F0 AC DF 
                       69 C9 54 4A BD 87 4F 7B AF A9 57 9D DE D2 E1 AB 

      EAPOL HMAC     : 75 38 AA EE 68 CF 05 F4 37 D0 83 4F 55 CA 52 66 

```