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
	//char data[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam interdum tristique sapien, vulputate euismod metus egestas non. Integer vulputate sapien sagittis, ornare ipsum in, suscipit odio. Curabitur dignissim hendrerit dolor in pellentesque. Curabitur iaculis elit vel nisl vehicula blandit. Sed ullamcorper urna quis vulputate interdum. Vestibulum at orci dignissim mauris vehicula aliquet. Nunc orci orci, maximus in risus vulputate, venenatis fringilla elit. Pellentesque interdum leo quis velit pulvinar pretium. Aenean posuere, magna blandit semper rutrum, nisi odio malesuada nunc, ut vulputate ex orci sed odio. Maecenas at maximus mauris. Phasellus gravida leo id pretium finibus. Suspendisse pharetra fermentum sagittis.\nMauris ex dui, auctor eu lorem eget, scelerisque placerat diam. Cras ac semper nisi, et mattis magna. Sed non ultrices turpis. Sed feugiat ante elit. Duis est dui, facilisis ut nisl in, luctus porttitor dui. Cras tincidunt quis nulla ut vulputate. Aenean at ligula id velit molestie commodo sed ac est. Suspendisse tincidunt et risus quis gravida.\nSed nec varius tortor. Morbi dapibus nisl non turpis aliquam, ac ornare velit consectetur. Quisque pulvinar eros ipsum, non facilisis erat maximus sed. Mauris lobortis suscipit malesuada. Duis tristique, massa posuere semper molestie, sem enim cursus nibh, eu lobortis elit nisi nec massa. Nullam accumsan libero diam, eget finibus dui tristique ornare. Quisque commodo bibendum turpis vel dictum. Sed non nunc elementum diam volutpat suscipit. Vestibulum ac sagittis massa. Phasellus maximus tellus sed elit vestibulum, vitae venenatis urna semper. Vestibulum eget imperdiet nisl, in consectetur odio.";
	char data[] = "test";

	MD5_CTX mc;
	MD5Init(&mc);
	MD5Update(&mc, data, strlen(data));
	MD5Final(&mc);
	printf("%s\n", mc.digest)

	// encrypt
	img = openBMP(bmpfile);
	buf = strToBit(data, &blen);	//convert string(data) to bit array
	//newimg = enc_rgb_shuffle(img, buf, blen, 213);
	newimg = enc_random_invert(img, buf, blen, 777);	//encrypt - change this 
	free(buf);

	writeBMP(newimg, "img/test.bmp");
	closeBMP(img);
	closeBMP(newimg);
	system("pause");

	//decrypt
	img = openBMP("img/test.bmp");
	//buf = dec_rgb_shuffle(img, 213);
	buf = dec_random_invert(img, 777);	//decrypt
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
	if (str != NULL) {
		printf("%s", str);
		free(str);
	}
	system("pause");

	return 0;
}
