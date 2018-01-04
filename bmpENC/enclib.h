/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
*/

#ifndef _ENCLIB_H_
#define _ENCLIB_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "encutil.h"
#include "tqbmp.h"

BMPImage *enc_evenodd_gray(BMPImage *img, uint8_t *data, uint bitlen);
uint8_t *dec_evenodd_gray(BMPImage *img);

BMPImage *enc_evenodd_rgb(BMPImage *img, uint8_t *data, uint bitlen);
uint8_t *dec_evenodd_rgb(BMPImage *img);

BMPImage *enc_rgb_shuffle(BMPImage *img, uint8_t *data, uint bitlen, int passwd);
uint8_t *dec_rgb_shuffle(BMPImage *img, int passwd);

BMPImage *enc_byte_shuffle(BMPImage *img, uint8_t *data, uint bitlen, int passwd);
uint8_t *dec_byte_shuffle(BMPImage *img, int passwd);

BMPImage *enc_random_shuffle_first(BMPImage *img, uint8_t *data, uint bitlen, int passwd);
uint8_t *dec_random_shuffle_first(BMPImage *img, int passwd);

BMPImage *enc_random_shuffle_each(BMPImage *img, uint8_t *data, uint bitlen, int passwd);
uint8_t *dec_random_shuffle_each(BMPImage *img, int passwd);

BMPImage *enc_random_invert(BMPImage *img, uint8_t *data, uint bitlen, int passwd);
uint8_t *dec_random_invert(BMPImage *img, int passwd);





#endif