
int authent(const char *input) {
     // char password[30] = "z3Bl4cKD0GW1llByt3Yu_Aarrrgh";

     volatile unsigned int r = 1;
     volatile unsigned int i = 0;
     if      ((input[i++] ^ 'a') != 0x1b) { r = 0; }
     else if ((input[i++] ^ 'b') != 0x51) { r = 0; }
     else if ((input[i++] ^ 'c') != 0x21) { r = 0; }
     else if ((input[i++] ^ 'd') != 0x08) { r = 0; }
     else if ((input[i++] ^ 'e') != 0x51) { r = 0; }
     else if ((input[i++] ^ 'f') != 0x05) { r = 0; }
     else if ((input[i++] ^ 'g') != 0x2c) { r = 0; }
     else if ((input[i++] ^ 'a') != 0x25) { r = 0; }
     else if ((input[i++] ^ 'b') != 0x52) { r = 0; }
     else if ((input[i++] ^ 'c') != 0x24) { r = 0; }
     else if ((input[i++] ^ 'd') != 0x33) { r = 0; }
     else if ((input[i++] ^ 'e') != 0x54) { r = 0; }
     else if ((input[i++] ^ 'f') != 0x0a) { r = 0; }
     else if ((input[i++] ^ 'g') != 0x0b) { r = 0; }
     else if ((input[i++] ^ 'a') != 0x23) { r = 0; }
     else if ((input[i++] ^ 'b') != 0x1b) { r = 0; }
     else if ((input[i++] ^ 'c') != 0x17) { r = 0; }
     else if ((input[i++] ^ 'd') != 0x57) { r = 0; }
     else if ((input[i++] ^ 'e') != 0x3c) { r = 0; }
     else if ((input[i++] ^ 'f') != 0x13) { r = 0; }
     else if ((input[i++] ^ 'g') != 0x38) { r = 0; }
     else if ((input[i++] ^ 'a') != 0x20) { r = 0; }
     else if ((input[i++] ^ 'b') != 0x03) { r = 0; }
     else if ((input[i++] ^ 'c') != 0x11) { r = 0; }
     else if ((input[i++] ^ 'd') != 0x16) { r = 0; }
     else if ((input[i++] ^ 'e') != 0x17) { r = 0; }
     else if ((input[i++] ^ 'f') != 0x01) { r = 0; }
     else if ((input[i++] ^ 'g') != 0x0f) { r = 0; }
     return r;
}
