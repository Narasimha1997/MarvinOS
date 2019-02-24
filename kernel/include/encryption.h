#ifndef __ENCRYPTION_H
#define __ENCRYPTION_H

#include <stdint.h>


//this is just a random seed 
#define BIT_32_SEED 0xff3262

#define NONCE_LENGTH 10

void encrypt(char *string);

void decrypt(char *string);

uint32_t generate_parity_32(char *string);

uint8_t verify_parity_32(char *string, uint32_t parity);


#endif