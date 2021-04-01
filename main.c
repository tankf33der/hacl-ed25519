#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "Hacl_Ed25519.h"

#define ARRAY(name, size) \
    uint8_t name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

int main(void) {
    ARRAY(hash, 64);
    ARRAY(key,  32);
    ARRAY(pub,  32);
    ARRAY(in,   32);
    
	Hacl_Ed25519_secret_to_public(pub, key);
    Hacl_Ed25519_sign(hash, key, 32, in);
    Hacl_Ed25519_verify(pub, 32, in, hash);

	return 0;
}
