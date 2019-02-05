#ifndef __ENCRYPTION_H
#define __ENCRYPTION_H


//this is just a random seed 
#define BIT_32_SEED 0xff3262

#define NONCE_LENGTH 10

void encrypt(char *string);


void decrypt(char *string);


#endif