/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
*/

#include "enclib.h"

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

			if (p % 2 == 1) p--;
			if (idx < bitlen) {
				if (data[idx++] == 1) p++;
			}

			/* Do not edit below */

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

				buf[idx++] = (p % 2);

				/* Do not edit below */
			}
		}
	}

	buf = realloc(buf, sizeof(uint8_t) * idx);
	return buf;
}

BMPImage *enc_evenodd_rgb(BMPImage *img, uint8_t *data, uint bitlen) {
	uint i, j, k, idx = 0;
	uint w = img->w, h = img->h;
	BMPImage *newimg = newBMP(w, h);

	/* [Assignment 1.2.1] Implement here
		For all pixel and each r, g, b,
		(1) If odd, subtract 1 to make it even
		(2) If there are some data, (use 'bitlen and idx'),
			and if the corresponding bit is 1,
			set the color value (r, g, or b) to be odd in the order of r-g-b.
	*/

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			RGB p = img->rgb[i][j];	//pixel value
			for (k = 0; k < 3; k++) {
				p.color[k] -= (p.color[k] % 2);
				if (idx < bitlen) p.color[k] += data[idx++];
			}
			newimg->rgb[i][j] = p;		//set pixel value
		}
	}



	/* Do not edit below */

	setRGB(newimg);						//update pixel value to image
	return newimg;
}


uint8_t *dec_evenodd_rgb(BMPImage *img) {
	uint i, j, k, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t *buf = calloc(MAX_BUF_SIZE, sizeof(uint8_t));
	
	/* [Assignment 1.2.2] Implement here
		(1) If the corresponding color pixel (r, g, or b) is odd, 
			set the bit of data to 1.
			Otherwise (if even), set it to 0.
	*/
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			RGB p = img->rgb[i][j];
			for (k = 0; k < 3; k++) {
				if (idx < MAX_BUF_SIZE) {
					buf[idx++] = (p.color[k] % 2);
				}
			}
		}
	}

	/* Do not edit below */

	buf = realloc(buf, sizeof(uint8_t) * idx);
	return buf;
}


BMPImage *enc_rgb_shuffle(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	uint i, j, k, m, idx = 0;
	uint w = img->w, h = img->h;
	BMPImage *newimg = newBMP(w, h);

	uint8_t *order = makeOrder(passwd, 3);

	/* [Assignment 2.1.1] Implement here
	For all pixel and each r, g, b,
	(1) If odd, subtract 1 to make it even
	(2) If there are some data, (use 'bitlen and idx'),
	and if the corresponding bit is 1,
	set the color value (r, g, or b) to be odd in the order of r-g-b.
	*/

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			RGB p = img->rgb[i][j];	//pixel value
			
			for (k = 0; k < 3; k++) {
				m = order[k] - 1;
				p.color[m] -= (p.color[m] % 2);
				if (idx < bitlen) p.color[m] += data[idx++];
			}
			
			newimg->rgb[i][j] = p;		//set pixel value
		}
	}



	/* Do not edit below */
	free(order);
	setRGB(newimg);						//update pixel value to image
	return newimg;
}


uint8_t *dec_rgb_shuffle(BMPImage *img, int passwd) {
	uint i, j, k, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t *buf = calloc(MAX_BUF_SIZE, sizeof(uint8_t));
	uint8_t *order = makeOrder(passwd, 3);

	/* [Assignment 2.1.2] Implement here
	(1) If the corresponding color pixel (r, g, or b) is odd,
	set the bit of data to 1.
	Otherwise (if even), set it to 0.
	*/
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			RGB p = img->rgb[i][j];
			for (k = 0; k < 3; k++) {
				if (idx < MAX_BUF_SIZE) {
					buf[idx++] = (p.color[order[k]-1] % 2);
				}
			}
		}
	}



	/* Do not edit below */
	free(order);
	buf = realloc(buf, sizeof(uint8_t) * idx);
	return buf;
}

BMPImage *enc_byte_shuffle(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	uint i, j, k, m, idx = 0, btlen;
	uint w = img->w, h = img->h;
	BMPImage *newimg;

	uint8_t *order = makeOrder(passwd, 4);


	/* [Assignment 3.1.1] Implement here
	For all pixel and each r, g, b,
	(1) If odd, subtract 1 to make it even
	(2) If there are some data, (use 'bitlen and idx'),
	and if the corresponding bit is 1,
	set the color value (r, g, or b) to be odd in the order of r-g-b.
	HINT: Use bitToByte()
	*/
	uint8_t *byte = bitToByte(data, bitlen, &btlen);
	uint8_t buf[4];

	for (i = 0; i < (btlen/4)*4; i+=4) {
		for (k = 0; k < 4; k++) {
			m = order[k] - 1;
			buf[k] = byte[i + m];
		}
		for (k = 0; k < 4; k++) {
			byte[i+k] = buf[k];
		}
	}

	uint8_t *bit = byteToBit(byte, btlen, NULL);

	newimg = enc_evenodd_gray(img, bit, bitlen);

	free(byte);
	free(bit);
	/* Do not edit below */
	free(order);
	setPixel(newimg);						//update pixel value to image
	return newimg;
}


uint8_t *dec_byte_shuffle(BMPImage *img, int passwd) {
	uint i, j, k, blen, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t *buf, *byte;
	uint8_t *order = makeOrder(passwd, 4);

	/* [Assignment 3.1.2] Implement here
	(1) If the corresponding color pixel (r, g, or b) is odd,
	set the bit of data to 1.
	Otherwise (if even), set it to 0.
	*/
	uint8_t tmp[4];
	buf = dec_evenodd_gray(img);
	byte = bitToByte(buf, MAX_BUF_SIZE, &blen);

	for (i = 0; i < (blen / 4) * 4; i += 4) {
		for (k = 0; k < 4; k++) {
			j = order[k] - 1;
			tmp[j] = byte[i + k];
		}
		for (k = 0; k < 4; k++) {
			byte[i + k] = tmp[k];
		}
	}

	free(buf);

	buf = byteToBit(byte, blen+1, NULL);

	free(byte);

	/* Do not edit below */
	free(order);
	return buf;
}

BMPImage *enc_random_shuffle_first(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;
	srand(passwd);
	int order = intToOrder(rand(), 4);
	newimg = enc_byte_shuffle(img, data, bitlen, order);

	return newimg;
}

uint8_t *dec_random_shuffle_first(BMPImage *img, int passwd) {
	uint8_t *buf;
	srand(passwd);
	int order = intToOrder(rand(), 4);
	buf = dec_byte_shuffle(img, order);

	return buf;
		
}

BMPImage *enc_random_shuffle_each(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	uint i, j, k, m, idx = 0, btlen;
	uint w = img->w, h = img->h;
	BMPImage *newimg;

	uint8_t *order;


	/* [Assignment 4.2.1] Implement here
	For all pixel and each r, g, b,
	(1) If odd, subtract 1 to make it even
	(2) If there are some data, (use 'bitlen and idx'),
	and if the corresponding bit is 1,
	set the color value (r, g, or b) to be odd in the order of r-g-b.
	HINT: Use bitToByte()
	*/
	uint8_t *byte = bitToByte(data, bitlen, &btlen);
	uint8_t buf[4];

	srand(passwd);

	for (i = 0; i < (btlen / 4) * 4; i += 4) {
		order = makeOrder(intToOrder(rand(), 4), 4);
		for (k = 0; k < 4; k++) {
			m = order[k] - 1;
			buf[k] = byte[i + m];
		}
		for (k = 0; k < 4; k++) {
			byte[i + k] = buf[k];
		}
		free(order);
	}

	uint8_t *bit = byteToBit(byte, btlen, NULL);

	newimg = enc_evenodd_gray(img, bit, bitlen);

	free(byte);
	free(bit);
	/* Do not edit below */
	setPixel(newimg);						//update pixel value to image
	return newimg;
}

uint8_t *dec_random_shuffle_each(BMPImage *img, int passwd) {
	uint i, j, k, blen, idx = 0;
	uint w = img->w, h = img->h;
	uint8_t *buf, *byte;
	uint8_t *order;

	/* [Assignment 4.2.2] Implement here
	(1) If the corresponding color pixel (r, g, or b) is odd,
	set the bit of data to 1.
	Otherwise (if even), set it to 0.
	*/
	uint8_t tmp[4];
	buf = dec_evenodd_gray(img);
	byte = bitToByte(buf, MAX_BUF_SIZE, &blen);
	srand(passwd);

	for (i = 0; i < (blen / 4) * 4; i += 4) {
		order = makeOrder(intToOrder(rand(), 4), 4);
		for (k = 0; k < 4; k++) {
			j = order[k] - 1;
			tmp[j] = byte[i + k];
		}
		for (k = 0; k < 4; k++) {
			byte[i + k] = tmp[k];
		}
		free(order);
	}

	free(buf);

	buf = byteToBit(byte, blen + 1, NULL);

	free(byte);

	/* Do not edit below */
	return buf;
}

BMPImage *enc_random_invert(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	uint i, btlen;
	BMPImage *newimg;


	/* [Assignment 4.2.1] Implement here
	For all pixel and each r, g, b,
	(1) If odd, subtract 1 to make it even
	(2) If there are some data, (use 'bitlen and idx'),
	and if the corresponding bit is 1,
	set the color value (r, g, or b) to be odd in the order of r-g-b.
	HINT: Use bitToByte()

	BE CAREFUL THAT YOU SHOULD NOT INVERT 0xFF SO THAT IT COULD NOT END THERE
	*/
	uint8_t *byte = bitToByte(data, bitlen, &btlen);
	srand(passwd);

	for (i = 0; i < btlen; i++) {
		if (rand() % 2 == 1 && byte[i] != 0xFF) byte[i] = ~byte[i];
	}

	uint8_t *bit = byteToBit(byte, btlen, NULL);

	newimg = enc_evenodd_gray(img, bit, bitlen);

	free(byte);
	free(bit);
	/* Do not edit below */
	setPixel(newimg);						//update pixel value to image
	return newimg;
}

uint8_t *dec_random_invert(BMPImage *img, int passwd) {
	uint i,  blen;
	uint8_t *buf, *byte;

	/* [Assignment 4.2.2] Implement here
	(1) If the corresponding color pixel (r, g, or b) is odd,
	set the bit of data to 1.
	Otherwise (if even), set it to 0.
	*/

	buf = dec_evenodd_gray(img);
	byte = bitToByte(buf, MAX_BUF_SIZE, &blen);
	srand(passwd);

	for (i = 0; i < blen; i++) {
		if (rand() % 2 == 1 && byte[i] != 0xFF)  byte[i] = ~byte[i];
	}

	free(buf);
	buf = byteToBit(byte, blen + 1, NULL);
	free(byte);

	/* Do not edit below */
	return buf;
}