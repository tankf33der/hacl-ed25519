#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "Hacl_Ed25519.h"

#define ARRAY(name, size) \
    uint8_t name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = 0;

int main(void) {
    ARRAY(zero, 64);
    
    Hacl_Ed25519_verify(zero, 0, zero, zero);
	return 0;
}
