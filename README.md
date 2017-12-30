# bmpENC
Encrypt/Decrypt assignment for 2017 Winter KAIST YOUTH Camp (C-lv2, 3)  
This assignment uses BMP image file for enc/dec.  
It uses tqbmp library. You can find the description and examples from [**here**](https://github.com/RangeWING/tqbmp).

2017 겨울 KAIST YOUTH CAMP C언어 레벨2, 레벨3 창의적프로젝트 과제입니다.  
BMP 이미지 파일을 이용하여 암호화하는 과제입니다.  
tqbmp library를 사용합니다. 사용법과 예제는 [**이 링크**](https://github.com/RangeWING/tqbmp)를 참조하세요.

## Files
 + tqbmp, qdbmp: BMP handling libraries (BMP 이미지 처리 라이브러리)
 + encutil: usable utils such as bit/byte converting functions (유용한 함수)
 + enclib: the code that you should implement (구현할 파일)

## -1. 튜터님들께
[Instructor's Mannual](Instructor.md)을 대강 완성하였습니다.  
Instructor's Mannual은 캠프 전날 내려둘 예정입니다.  
필요하시면 맨 아래 연락처로 요청해주세요.  
 
## 0. Introduction
### 0.1 functions
encutil.h has some useful functions.  
encutil.h에 몇가지 유용한 함수들이 있습니다.  
+ `uint8_t *byteToBit(uint8_t *bt, uint len, uint *bitlen)`  
  - convert byte array `bt` of length `len` into the bit array of length `bitlen` 
  - 길이가 `len`인 byte 배열 `bt`를 길이가 `bitlen`인 bit array로 변환합니다.
  - Ex) bt=`{0x0F 0x33}` => `{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1}`
+ `uint8_t *bitToByte(uint8_t *b, uint len, uint *bytelen)`
  - convert bit array `b` of length `len` into the byte array of length `bytelen`
  - 길이가 `len`인 bit 배열 `b`를 길이가 `bytelen`인 byte array로 변환합니다.
  - Ex) b=`{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1}` => `{0x0F 0x33}`
+ `uint8_t *strToBit(char *bt, uint *bitlen)`
  - attach header to the string `bt` and then call `byteToBit()`
  - 문자열 `bt`에 header를 붙이고 `byteToBit()`를 호출합니다.
+ `char *bitToStr(uint8_t *b, uint len, uint *slen)`
  - call `bitToByte()` and detach header from the array.
  - `bitToByte()`를 호출하고 header를 뗍니다.
+ `uint8_t *makeOrder(int n, int len)`
  - make the order array with the integer `n` of length `len`
  - `len` 자리의 정수 `n`으로 순서 배열을 만듭니다.
  - Ex) `makeOrder(4231, 4) == {4, 2, 3, 1, 0}` (ends with 0)


### 0.2 Data 
#### 0.2.1 Header/Footer  
There are 4-byte header and footer that is automatically added to the data in order to make it able to read the data easily.   
Header and footer will be added to the data by `attachHeader()`. It is called by `strToBit()`, which is called by `encBMP()`.     
They are automatically removed by `detachHeader()`. It is called by `bitToStr()`, which is called by `decBMP()`.  
The header is `0x0F 0xFF 0x33 0x55` (4 bytes), and the footer is `0x55 0x33 0xFF 0xF0` (4 bytes).  

데이터를 읽기 쉽게 하기 위해서, 4-byte의 header와 footer가 데이터에 자동으로 더해집니다.  
header와 footer는 `attachHeader()`에 의해 데이터에 더해지는데, 이것은 `encBMP()`에 의해 호출되는 `strToBit()`가 호출합니다.  
또한 header와 footer는 `detachHeader()`에 의해 데이터에서 제거되는데, 이것은 `decBMP()`에 의해 호출되는 `bitToStr()`이 호출합니다.
header는 `0x0F 0xFF 0x33 0x55`이며, footer는 `0x55 0x33 0xFF 0xF0`입니다.

#### 0.2.2 End of data
The data always end with `0x00`. It is also added by `attachHeader()`.
 
 
## Assignments
Look at each description file
+ [Assignment 1 : Even/Odd Encryption](%5B1%5D%20Even_Odd_Encryption.md)
+ [Assignment 2 : RGB-Shuffle](%5B2%5D%20RGB_Shuffle.md)
+ [Assignment 3 : Byte-Shuffle](%5B3%5D%20Byte_Shuffle.md)
+ [Assignment 4 : Random-Shuffle	(Not for elementary)](%5B4%5D%20Random_Shuffle.md)
+ [Assignment 5 : Advanced Technique (Only for Lv3)](%5B5%5D%20Advanced_Technique.md)
+ [Assignment 6 : Creative Technique](%5B6%5D%20Creative_Technique.md)
+ [Assignment 7 : Presentation](%5B7%5D%20Presentation.md)

#### Instructor's Mannual
+ Korean: [click here](Instructor.md) 

### Contact
RangeWING (rangewing@wingdev.kr or rangewing@kaist.ac.kr)  