/*
* Author: Young-Geol Jo (rangewing@kaist.ac.kr / rangewing@wingdev.kr)
* Data encoding/decoding util
*/

#ifndef _ENC_UTIL_H_
#define _ENC_UTIL_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "tqbmp.h"

#define DATA_HEADER_LENGTH 9

#define MAX_BUF_SIZE 4096

typedef unsigned long uint;

const extern uint DATA_HEADER, DATA_FOOTER;

uint8_t *byteToBit(uint8_t *bt, uint len, uint *bitlen);
uint8_t *bitToByte(uint8_t *b, uint len, uint *bytelen);
uint8_t *strToBit(char *bt, uint *bitlen);
char *bitToStr(uint8_t *b, uint len, uint *slen);

uint8_t *makeOrder(int n, int len);
int intToOrder(int n, int len);

void attachHeader(uint8_t **b, uint len);
void detachHeader(uint8_t **b, uint len);

/*
******************************************************************
** Below is MD5 hash algorithm.									**
** Retrieved from https://people.csail.mit.edu/rivest/Md5.c		**
******************************************************************
*/

/*
**********************************************************************
** Copyright (C) 1990, RSA Data Security, Inc. All rights reserved. **
**                                                                  **
** License to copy and use this software is granted provided that   **
** it is identified as the "RSA Data Security, Inc. MD5 Message     **
** Digest Algorithm" in all material mentioning or referencing this **
** software or this function.                                       **
**                                                                  **
** License is also granted to make and use derivative works         **
** provided that such works are identified as "derived from the RSA **
** Data Security, Inc. MD5 Message Digest Algorithm" in all         **
** material mentioning or referencing the derived work.             **
**                                                                  **
** RSA Data Security, Inc. makes no representations concerning      **
** either the merchantability of this software or the suitability   **
** of this software for any particular purpose.  It is provided "as **
** is" without express or implied warranty of any kind.             **
**                                                                  **
** These notices must be retained in any copies of any part of this **
** documentation and/or software.                                   **
**********************************************************************
*/

/* typedef a 32 bit type */
typedef unsigned long int UINT4;

/* Data structure for MD5 (Message Digest) computation */
typedef struct {
	UINT4 i[2];                   /* number of _bits_ handled mod 2^64 */
	UINT4 buf[4];                                    /* scratch buffer */
	unsigned char in[64];                              /* input buffer */
	unsigned char digest[16];     /* actual digest after MD5Final call */
} MD5_CTX;

void MD5Init(MD5_CTX *mdContext);
void MD5Update(MD5_CTX *mdContext, unsigned char *inBuf, unsigned int inLen);
void MD5Final(MD5_CTX *mdContext);


/*
**********************************************************************
** End of md5.h                                                     **
******************************* (cut) ********************************
*/

#endif