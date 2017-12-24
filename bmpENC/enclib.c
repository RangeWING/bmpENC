/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
*/

#include <enclib.h>

BMPImage *enc_evenodd_gray(BMPImage *img, uint8_t *data, uint bitlen) {
	uint i, j, idx = 0;
	uint w = img->w, h = img->h;
	BMPImage *newimg = newBMP(w, h);

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			uint8_t p = img->pixel[i][j];	//pixel value

			/* [Assignment 1.1.1] Implement here
				(1) If odd, subtract 1 to make it even
				(2) If there are some data, (use 'bitlen and idx'),
					and if the corresponding bit is 1, set the pixel (p) to be odd.
			*/

			newimg->pixel[i][j] = p;		//set pixel value
		}
	}

	setPixel(newimg);						//update pixel value to image
	return newimg;
}


uint8_t *dec_evenodd_gray(BMPImage *img) {
	uint i, j, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t *buf = calloc(MAX_BUF_SIZE, sizeof(uint8_t));

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			uint8_t p = img->pixel[i][j];
			if (idx < MAX_BUF_SIZE) {
				/* [Assignment 1.1.2] Implement here
					(1) If the pixel (p) is odd, set the bit of data to 1. 
						Otherwise (if even), set it to 0.
				*/
			}
		}
	}

	buf = realloc(buf, sizeof(uint8_t) * idx);
	return buf;
}

BMPImage *enc_evenodd_rgb(BMPImage *img, uint8_t *data, uint bitlen) {
	uint i, j, idx = 0;
	uint w = img->w, h = img->h;
	BMPImage *newimg = newBMP(w, h);

	/* [Assignment 1.2.1] Implement here
		For all pixel and each r, g, b,
		(1) If odd, subtract 1 to make it even
		(2) If there are some data, (use 'bitlen and idx'),
			and if the corresponding bit is 1,
			set the color value (r, g, or b) to be odd in the order of r-g-b.
	*/

	setPixel(newimg);						//update pixel value to image
	return newimg;
}


uint8_t *dec_evenodd_rgb(BMPImage *img) {
	uint i, j, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t *buf = calloc(MAX_BUF_SIZE, sizeof(uint8_t));
	
	/* [Assignment 1.2.2] Implement here
		(1) If the corresponding color pixel (r, g, or b) is odd, 
			set the bit of data to 1.
			Otherwise (if even), set it to 0.
	*/

	buf = realloc(buf, sizeof(uint8_t) * idx);
	return buf;
}