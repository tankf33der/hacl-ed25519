#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "Hacl_Ed25519.h"

#define ARRAY(name, size) \
    uint8_t name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

//@ ensures \result == 0;
int sign_check_ed25519(void) {
    ARRAY(hash1, 64);
    ARRAY(hash2, 64);
    ARRAY(key,   32);
    ARRAY(pub1,  32);
    ARRAY(pub2,  32);
    ARRAY(in,    32);
    int status = 0;
    
	Hacl_Ed25519_secret_to_public(pub2, key);
    Hacl_Ed25519_sign(hash2, key, 32, in);
    Hacl_Ed25519_verify(pub2, 32, in, hash2);	// as bool: 1 - ok, 0 - wrong
    return status;
}

int main(void) {
	int status = 0;
	
	sign_check_ed25519();

	printf("%s\n", status != 0 ? "FAIL" : "OK");	
	return status;
}
