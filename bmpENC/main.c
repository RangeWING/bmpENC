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
	uint w, h;
	BMPImage *img, *newimg;

	const char bmpfile[256] = "img/black.bmp";
	char data[] = "--data?--testdata Hello,world!\nHELLO HELLO Repeat";
	uint blen;
	uint8_t *dbit = strToBit(data, &blen);

	img = openBMP(bmpfile);
	w = img->w;
	h = img->h;

	newimg = enc_evenodd_gray(img, data);

	writeBMP(newimg, "img/test.bmp");

	closeBMP(img);
	closeBMP(newimg);

	system("pause");


	img = openBMP("img/test.bmp");

	char *str = dec_evenodd_gray(img);

	printf("%s", str);
	free(str);
	
	closeBMP(img);
	system("pause");

	return 0;
}

