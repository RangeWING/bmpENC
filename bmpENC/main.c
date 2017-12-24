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
	char *str;

	const char bmpfile[256] = "img/white.bmp";
	char data[] = "--data?--testdata Hello,world!\nHELLO HELLO Repeat\n";

	img = openBMP(bmpfile);
	newimg = encBMP(img, data, enc_evenodd_gray);
	writeBMP(newimg, "img/test.bmp");

	closeBMP(img);
	closeBMP(newimg);
	system("pause");

	img = openBMP("img/test.bmp");
	str = decBMP(img, dec_evenodd_gray);
	closeBMP(img);

	printf("%s", str);
	free(str);	
	system("pause");

	return 0;
}
