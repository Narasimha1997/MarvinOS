#include "binary/encryption.h"
#include<stdint.h>

/*
   This is not a secure form of encryption, much higher level encryption schemes will be implemented later
*/

unsigned char nonce[NONCE_LENGTH] = {
    0x32, 0x44, 0x12, 0x33, 0x44, 0x55, 0xff, 0xff, 0xff, 0x33
};


void encrypt(char *buffer) {
    uint8_t nonce_iter = 0;

    while(*buffer) {
        unsigned char N = (uint8_t)(((uint32_t)nonce[(nonce_iter + 1) % NONCE_LENGTH] ^ BIT_32_SEED) & 0x000f);
        *buffer = (*buffer) ^ N;
        buffer ++;
    }
}

void decrypt(char *buffer) {
    //we can simply call encrypt() method, as XOR has the property = (if A^B = C, then C^B = A)

    encrypt(buffer);
}


uint32_t generate_parity_32(char *string) {
    //Parity will be calculated by XORING all characters and finally XORING it with parity
    uint32_t parity = 0;

    while(*string){ 
        parity = parity ^ (uint32_t)(*string);
        string ++;
    };

    return (parity ^ BIT_32_SEED);
}

uint8_t verify_parity_32(char *string, uint32_t parity) {
    
    uint32_t new_parity = 0;

    while(*string) {
        new_parity = new_parity ^ (uint32_t)(*string);
        string ++;
    } 

    new_parity = new_parity ^ BIT_32_SEED;

    if((new_parity ^ parity) == 0) return +1;
    
    return 0;
}



