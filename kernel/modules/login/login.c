#include "stdio.h"
#include "display.h"
#include "input/stdin.h"
#include "arch/types.h"
#include "encryption.h"
#include "string.h"
#include "login/login.h"


//As of now , we will be sticking with pre-defined password :
static string password = "prasanna1997\n";

void encrypt_password() {
    encrypt(password);
}

boolean login() {
    char buffer[30];
    encrypt_password();

    kb_read_line(buffer);

    //check decryption : 
    encrypt(buffer);

    if(strcmp(buffer, password) == 0) return TRUE;
    return FALSE;
}