#include "crypto.h"
#include <stdlib.h>
#include <stdio.h>
void 
print_hex(unsigned char *pbtData, const size_t szBytes) {
	size_t          szPos;

	for (szPos = 0; szPos < szBytes; szPos++) {
		printf("%02x  ", pbtData[szPos]);
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int crypto_init = init_crypto_state();
	if (crypto_init != 0) {
		printf("Could not create the crypto context\n");
		return 1;
	}
	char testUID[5] = {0x1a,0x35,0xb6,0x3f,0x00};

	char *key = get_derived_key(&testUID[0]);
	printf("Key: ");
	print_hex(key, 6);
	free(key);

	const char *testBase64= "NEW2nspY";
	char testBase64Output[7];
	memset(testBase64Output,0,6);
	decodeBase64String(testBase64,8,&testBase64Output[0],6);
	printf("Base 64 Output: ");
	print_hex(testBase64Output,6);	
	return 0;
			
}


