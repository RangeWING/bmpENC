/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* Data encoding/decoding util
*/

#ifndef _ENC_UTIL_H_
#define _ENC_UTIL_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <tqbmp.h>

typedef unsigned long uint;

uint8_t *byteToBit(uint8_t *bt, uint len, uint *bitlen);
uint8_t *bitToByte(uint8_t *b, uint len, uint *bytelen);
uint8_t *strToBit(char *bt, uint *bitlen);
char *bitToStr(uint8_t *b, uint len, uint *slen);



#endif