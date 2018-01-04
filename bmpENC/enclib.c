/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
*/

#include "enclib.h"

/* enc_evenodd_gray
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
*/
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



			/* Do not edit below */

			newimg->pixel[i][j] = p;		//set pixel value
		}
	}

	setPixel(newimg);						//update pixel value to image
	return newimg;
}

/* dec_evenodd_gray
** parameters:
**	BMPImage *img: an encoded image to decode
*/
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



				/* Do not edit below */
			}
		}
	}

	buf = realloc(buf, sizeof(uint8_t) * idx);
	return buf;
}


/* enc_evenodd_rgb
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
*/
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



	/* Do not edit below */

	setRGB(newimg);						//update pixel value to image
	return newimg;
}


/* dec_evenodd_rgb
** parameters:
**	BMPImage *img: an encoded image to decode
*/
uint8_t *dec_evenodd_rgb(BMPImage *img) {
	uint8_t *buf;
	/* [Assignment 1.2.2] Implement here
		(1) If the corresponding color pixel (r, g, or b) is odd, 
			set the bit of data to 1.
			Otherwise (if even), set it to 0.
	*/



	/* Do not edit below */

	return buf;
}

/* enc_rgb_shuffle
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
**	int passwd: the order (1~3) to shuffle (ex: 231)
*/
BMPImage *enc_rgb_shuffle(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;
	/* [Assignment 2.1.1] Implement here 
		Also you should implement and use makeOrder() in encutil.c */


	/* Do not edit below */
	return newimg;
}


/* dec_rgb_shuffle
** parameters:
**	BMPImage *img: an encoded image to decode
**	int passwd: the shuffled order (1~3) (ex: 231)
*/
uint8_t *dec_rgb_shuffle(BMPImage *img, int passwd) {
	uint8_t *buf;
	/* [Assignment 2.1.2] Implement here 
		Also you should implement and use makeOrder() in encutil.c */


	/* Do not edit below */
	return buf;
}


/* enc_byte_shuffle
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
**	int passwd: the order (1~4) to shuffle (ex: 2431)
*/
BMPImage *enc_byte_shuffle(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;
	uint8_t *byte, *bit;
	uint8_t tmp[4];


	/* [Assignment 3.1.1] Implement here
		HINT: Use bitToByte()
	*/

	/* Do not edit below */
	return newimg;
}

/* dec_byte_shuffle
** parameters:
**	BMPImage *img: an encoded image to decode
**	int passwd: the order (1~4) to shuffle (ex: 2431)
*/
uint8_t *dec_byte_shuffle(BMPImage *img, int passwd) {
	uint8_t *buf, *byte;
	uint8_t tmp[4];

	/* [Assignment 3.1.2] Implement here
		HINT: Use bitToByte()
	*/
	

	/* Do not edit below */
	return buf;
}


/* enc_random_shuffle_first
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
**	int passwd: the password (seed) of encoding; any integer is accepted
*/
BMPImage *enc_random_shuffle_first(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;

	/* [Assignment 4.1.1] Implement here
		This code can be very short (3~5 lines)
		HINT: Use enc_byte_shuffle()
		Do NOT forget to use srand()
		Also you should implement and use intToOrder() in encutil.c */



	/* Do not edit below */
	return newimg;
}

/* dec_random_shuffle_first
** parameters:
**	BMPImage *img: an encoded image to decode
**	int passwd: the password (seed) of encoding; any integer is accepted
*/
uint8_t *dec_random_shuffle_first(BMPImage *img, int passwd) {
	uint8_t *buf;
	/* [Assignment 4.1.2] Implement here
		This code can be very short (3~5 lines)
		HINT: Use dec_byte_shuffle()
		Do NOT forget to use srand()
		Also you should implement and use intToOrder() in encutil.c */



	/* Do not edit below */
	return buf;
}

/* enc_random_shuffle_each
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
**	int passwd: the password (seed) of encoding; any integer is accepted
*/
BMPImage *enc_random_shuffle_each(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;
	uint8_t buf[4];
	uint8_t *byte, *bit;

	/* [Assignment 4.2.1] Implement here
		HINT: Use bitToByte()
		Do NOT forget to use srand()
	*/

	
	/* Do not edit below */
	return newimg;
}

/* dec_random_shuffle_each
** parameters:
**	BMPImage *img: an encoded image to decode
**	int passwd: the password (seed) of encoding; any integer is accepted
*/
uint8_t *dec_random_shuffle_each(BMPImage *img, int passwd) {
	uint8_t *buf, *byte;
	uint8_t tmp[4];

	/* [Assignment 4.2.2] Implement here
		HINT: Use bitToByte()
		Do NOT forget to use srand()
	*/


	/* Do not edit below */
	return buf;
}

/* enc_random_invert
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
**	int passwd: the password (seed) of encoding; any integer is accepted
*/
BMPImage *enc_random_invert(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;
	uint8_t *byte, *bit;

	/* [Assignment 4.3.1] Implement here
		HINT: Use bitToByte(), byteToBit(), enc_evenodd_gray()
		Do NOT forget to use srand()
		Be careful that you must NOT invert 0xFF in order not to be ended there
	*/

	
	/* Do not edit below */
	return newimg;
}

/* dec_random_invert
** parameters:
**	BMPImage *img: an encoded image to decode
**	int passwd: the password (seed) of encoding; any integer is accepted
*/
uint8_t *dec_random_invert(BMPImage *img, int passwd) {
	uint8_t *buf, *byte;

	/* [Assignment 4.2.2] Implement here
		HINT: Use bitToByte(), byteToBit(), dec_evenodd_gray()
		Do NOT forget to use srand()
		Be careful that you must NOT invert 0xFF, 0x00
	*/


	/* Do not edit below */
	return buf;
}