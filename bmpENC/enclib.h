/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* BMP image encoding/decoding library: for assignment
*/

#ifndef _ENCLIB_H_
#define _ENCLIB_H_

#include <stdlib.h>
#include <stdint.h>
#include <encutil.h>
#include <string.h>
#include <tqbmp.h>

#define MAX_BUF_SIZE 4096

BMPImage *enc_evenodd_gray(BMPImage *img, char *str);
char *dec_evenodd_gray(BMPImage *img);
BMPImage *enc_evenodd_rgb(BMPImage *img, char *str);
char *dec_evenodd_rgb(BMPImage *img);

#endif