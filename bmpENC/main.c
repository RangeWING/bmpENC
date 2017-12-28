/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
* sample code
* for KAIST 2017 Winter YOUTH Camp, C lv2, lv3
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tqbmp.h>
#include <enclib.h>

int main() {
	BMPImage *img, *newimg;
	uint blen, i;
	uint8_t *buf, *bbuf;
	char *str;

	const char bmpfile[256] = "img/white.bmp";
	char data[] = "--data?--testdata Hello,world!\nHELLO HELLO Repeat\n";

	// encrypt
	img = openBMP(bmpfile);
	buf = strToBit(data, &blen);	//convert string(data) to bit array
	newimg = enc_byte_shuffle(img, buf, blen, 1324);	//encrypt 
	free(buf);

	writeBMP(newimg, "img/test.bmp");
	closeBMP(img);
	closeBMP(newimg);
	system("pause");

	//decrypt
	img = openBMP("img/test.bmp");
	buf = dec_evenodd_gray(img);	//decrypt
	bbuf = bitToByte(buf, MAX_BUF_SIZE, &blen);
	for (i = 0; i < blen*8; i++) {
		printf("%d", buf[i]);
		if (i % 4 == 3) printf(" ");
	}
	printf("\n");

	for (i = 0; i < blen; i++) {
		printf("%02X ", bbuf[i]);
	}
	printf("\n");

	str = bitToStr(buf, MAX_BUF_SIZE, &blen);	//convert bit array into string
	free(buf);
	closeBMP(img);

	//check
	printf("%s", str);
	free(str);	
	system("pause");

	return 0;
}
