#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tqbmp.h>

BMPImage *even_odd_gray(BMPImage *img);
uint8_t *byteToBit(char *bt, uint len);
uint8_t *bitToByte(uint8_t *b, uint len);

int main() {
	UCHAR r, g, b;
	uint w, h, i, j, idx = 0;
	BMPImage *img, *newimg;

	const char bmpfile[256] = "./mr+kaist_128.bmp";
	char data[] = "--<data>";
	data[0] = 0xFF;
	data[1] = 0xFF;
	uint dlen = strlen(data);
	uint8_t *dbit = byteToBit(data, dlen);

	img = openBMP(bmpfile);
	w = img->w;
	h = img->h;

	newimg = newBMP(w, h);


	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			uint8_t p = img->pixel[i][j];
			if(p % 2 == 1) p--;
			if (idx < dlen*8) {
				if (dbit[idx++]) p++;
			}
			newimg->pixel[i][j] = p;
		}
	}

	setPixel(newimg);
	writeBMP(newimg, "test.bmp");

	closeBMP(img);
	closeBMP(newimg);

	system("pause");

	img = openBMP("test.bmp");

	uint8_t buf[1024] = { 0 };
	idx = 0;

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			uint8_t p = img->pixel[i][j];
			if (idx < 1024) {
				buf[idx++] = p % 2;
			}
		}
	}

	char *str = bitToByte(buf, 1024);
	printf("%s", str);
	free(str);
	
	closeBMP(img);
	system("pause");

	return 0;
}


BMPImage *even_odd_gray(BMPImage *img) {

}

uint8_t *byteToBit(char *bt, uint len) {
	uint8_t *b = calloc(sizeof(uint8_t), len * 8);
	uint i = 0;
	for (i = 0; i < len * 8; i++) {
		b[i] = ((bt[i / 8] & (0x80 >> (i % 8))) != 0);
	}
	return b;
}


char *bitToByte(uint8_t *b, uint len) {
	char *bt = calloc(sizeof(char), len * 8);
	uint i, j;
	uint8_t buf = 0;

	for (i = 0; i < len/8; i++) {
		buf = 0;
		for (j = 0; j < 8; j++) {
			bt[i] = (bt[i] << 1) | (b[i * 8 + j] & 0x1);
		}
		if (bt[i] == 0) break;
	}
	return bt;

}