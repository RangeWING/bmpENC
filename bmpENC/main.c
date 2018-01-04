/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
* sample code
* for KAIST 2017 Winter YOUTH Camp, C lv2, lv3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tqbmp.h"
#include "enclib.h"

int main() {
	BMPImage *img, *newimg;
	uint blen, i;
	uint8_t *buf, *bbuf;
	char *str;

	const char bmpfile[256] = "img/test.bmp";
	char data[] = "test";

	/*	Encryption
		1. open a BMP file
		2. convert data to bit array 
		3. use enc_... function to get the encoded image 
		4. write the encoded image to file and close images
		+ Do NOT forget to free and close the array from dec/enc and images  */


	/*	Decryption
		1. open the encrypted BMP file
		2. use dec_... function to get the bit array from the encoded image
		3. use bitToByte() to get the byte array and print them (use %02X)
		4. use bitToStr() to get the string from the bit array and print it
		+ Do NOT forget to free and close the array from dec/enc and images 
		+ If decoding function does not operate well, then bitToStr() will return NULL (you should check it)*/


	return 0;
}
