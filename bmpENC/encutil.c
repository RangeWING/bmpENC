/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* Data encoding/decoding util
*/

#include <encutil.h>

uint8_t *byteToBit(uint8_t *bt, uint len, uint *bitlen) {
	uint8_t *b = calloc(sizeof(uint8_t), len * 8);
	uint i = 0;
	for (i = 0; i < len * 8; i++) {
		b[i] = ((bt[i / 8] & (0x80 >> (i % 8))) != 0);
	}
	if (bitlen != NULL)
		*bitlen = len * 8;
	return b;
}


uint8_t *bitToByte(uint8_t *b, uint len, uint *bytelen) {
	char *bt = calloc(sizeof(char), len * 8);
	uint i, j;
	uint8_t buf = 0;

	for (i = 0; i < len / 8; i++) {
		buf = 0;
		for (j = 0; j < 8; j++) {
			bt[i] = (bt[i] << 1) | (b[i * 8 + j] & 0x1);
		}
		if (bt[i] == 0) break;
	}
	
	bt = realloc(bt, sizeof(char)*i);

	if(bytelen != NULL)
		*bytelen = i;

	return bt;

}

uint8_t *strToBit(char *bt, uint *bitlen) {
	uint len = (uint)strlen(bt);
	char *buf = calloc(sizeof(char), len + 5);
	buf[0] = 0xF0; // 1111 0000
	buf[1] = 0xA5; // 1010 0101
	strcpy(&buf[2], bt);
	buf[len + 2] = 0x5A;
	buf[len + 3] = 0x0F;
	buf[len + 4] = 0x00;
	uint8_t *bit = byteToBit(buf, len + 5, bitlen);
	free(buf);

	return bit;
}

char *bitToStr(uint8_t *b, uint len, uint *slen) {
	char *buf = bitToByte(b, len, slen);
	char *str = calloc(sizeof(char), (*slen)-3);
	strncpy(str, &buf[2], (*slen)-4);
	str[*slen - 4] = 0x00; 
	free(buf);

	return str;
}
