/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* Data encoding/decoding util
*/

#include <encutil.h>

const uint DATA_HEADER = 0x5533FF0F; //0F FF 33 55
const uint DATA_FOOTER = 0x0FFF3355; //55 33 FF 0F

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

	for (i = 0; i < len / 8; i++) {
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
	char *buf = calloc(sizeof(char), len + DATA_HEADER_LENGTH);
	strcpy(buf, bt);
	attachHeader(&buf, len);

	uint8_t *bit = byteToBit(buf, len + DATA_HEADER_LENGTH, bitlen);
	free(buf);

	return bit;
}

char *bitToStr(uint8_t *b, uint len, uint *slen) {
	char *buf = bitToByte(b, len, slen);
	detachHeader(&buf, *slen+1);
	return buf;
}

void attachHeader(uint8_t **b, uint len) {
	uint8_t *buf = calloc(sizeof(uint8_t), len + DATA_HEADER_LENGTH);

	memcpy(buf, &DATA_HEADER, 4);

	memcpy(&buf[4], *b, len);
	memcpy(&buf[len + 4], &DATA_FOOTER, 4);
	buf[len + 8] = 0x00;
	free(*b);

	*b = buf;
}

void detachHeader(uint8_t **b, uint len) {
	uint8_t *buf = calloc(sizeof(uint8_t), len - DATA_HEADER_LENGTH + 1);
	memcpy(buf, &((*b)[4]), len - DATA_HEADER_LENGTH);
	buf[len - DATA_HEADER_LENGTH] = 0x00;
	free(*b);
	*b = buf;
}

BMPImage *encBMP(BMPImage *img, char *str, BMPImage *(*encfn)(BMPImage *, uint8_t *, uint)) {
	uint blen;
	uint8_t *dbit = strToBit(str, &blen);

	return encfn(img, dbit, blen);
}

char *decBMP(BMPImage *img, uint8_t *(*decfn)(BMPImage *)) {
	uint blen;
 	uint8_t *buf = decfn(img);
	return bitToStr(buf, MAX_BUF_SIZE, &blen);
}