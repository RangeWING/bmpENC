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
			if (p % 2 == 1) p--;			//if odd, subtract 1 to be even
			if (idx < bitlen) {				//if some data are left,
				if (data[idx++]) p++;		//and the data is 1, make the pixel be odd
			}
			newimg->pixel[i][j] = p;		//set pixel value
		}
	}

	free(data);
	setPixel(newimg);						//update pixel value to image
	return newimg;
}


char *dec_evenodd_gray(BMPImage *img) {
	uint i, j, blen, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t buf[MAX_BUF_SIZE] = { 0 };

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			uint8_t p = img->pixel[i][j];
			if (idx < MAX_BUF_SIZE) {
				buf[idx++] = p % 2;
			}
		}
	}

	return bitToStr(buf, MAX_BUF_SIZE, &blen);
}

BMPImage *enc_evenodd_rgb(BMPImage *img, uint8_t *data, uint bitlen) {
	uint i, j, idx = 0;
	uint w = img->w, h = img->h;
	BMPImage *newimg = newBMP(w, h);

	/* Implement here */

	free(data);
	setPixel(newimg);						//update pixel value to image
	return newimg;
}


char *dec_evenodd_rgb(BMPImage *img) {
	uint i, j, blen, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t buf[MAX_BUF_SIZE] = { 0 };

	/* Implement here */

	return bitToStr(buf, MAX_BUF_SIZE, &blen);
}