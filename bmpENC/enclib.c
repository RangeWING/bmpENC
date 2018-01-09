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


/* Below is only for level 3 */


/* enc_hash
** parameters:
**	BMPImage *img: an image to encode
**	uint8_t *data: bit array of data
**	uint bitlen: the length of data
**	int passwd: the password of encoding; any integer is accepted
*/
BMPImage *enc_hash(BMPImage *img, uint8_t *data, uint bitlen, int passwd) {
	BMPImage *newimg;
	uint8_t *byte, *bit;

	/* [Assignment 5.1.1] Implement here
		HINT: Use MD5()
		Be careful that you must NOT invert 0xFF in order not to be ended there
	*/

	
	/* Do not edit below */
	return newimg;
}

/* dec_random_invert
** parameters:
**	BMPImage *img: an encoded image to decode
**	int passwd: the password of encoding; any integer is accepted
*/
uint8_t *dec_hash(BMPImage *img, int passwd) {
	uint8_t *buf, *byte;

	/* [Assignment 5.1.2] Implement here
		HINT: Use MD5()
		Be careful that you must NOT invert 0xFF, 0x00
	*/


	/* Do not edit below */
	return buf;
}

BMPImage *enc_file_rgb(BMPImage *img, FILE *file) {
	BMPImage *newimg;
	size_t size;
	uint blen, n;
	uint8_t *buf, *bit;
	rewind(file);
	
	fseek(file, 0, SEEK_END);
	size = ftell(file);	//size(length) of the file in byte
	rewind(file);

	
	/* [Assignment 5.2]
		There are at least two ways to implement this.
		(1) Read and store the whole file in a buffer and then call enc_evenodd_.. function
		(2) Read the small part of the file and encode it to the file.
			Repeat it until the file ends (EOF).
		The first one is simple, but quite inefficient.
		The second one is quite complex, but more efficient than (1).

		I recommend you to use (1), because the time may not sufficient in the camp.
		But if you are expert of C, then you may enjoy to use (2).

		If you use (1), you should use attachHeader() before using byteToBit(),
		since byteToBit() does not attach header.
		
		If you decided to implement this as (2), you should encode the header and the footer also. 
		byteToBit() does not attach header, and also attachHeader() will attach the headers for every section of data.
		The header should be at the head and the tail of the while data, not at the middle.
	*/

	/* 	[Assignment 5.2.1] Implement Here 
		The implementation can be short (5~8 lines) */
		
		
	/* Do not edit below */

	free(buf);
	free(bit);

	return newimg;
}

FILE *dec_file_rgb(BMPImage *img, FILE *decfile) {
	size_t size;
	uint blen, n;
	uint8_t *byte, *bit;
	
	/*  [Assignment 5.2.2] Implement Here
	    you must increase MAX_BUF_SIZE in encutil.h to 50000, for ~5KB file
		Use bitToByte_strict() function instead of bitToByte(), since we cannot know the file size 
		The implementation can be short (4~6 lines) */

	free(bit);
	free(byte);

	return decfile;
}