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

## 0. Introduction
### 0.1 functions
TODO

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
 
## Assignment 1 : Even/Odd Encryption
You should implement even/odd encryption/decryption.  
The pixel value should be **ODD** when the corresponding bit is **1**, and it should be **EVEN** when the corresponding one is **0**.  
홀수/짝수 암호화/복호화를 구현하세요.  
대응하는 bit가 **1**일 때 픽셀 값을 **홀수**로, **0**일 떄는 **짝수**로 설정합니다.

### 1.1 Grayscale
Use only grayscale value. Use `pixel` array of BMPImage.  
흑백 값만 사용합니다. BMPImage 구조체의 `pixel` 배열을 사용하세요.
#### 1.1.1 Encryption
Implement `enc_evenodd_gray()` function in enclib.c  
enclib.c의 `enc_evenodd_gray()` 함수를 완성하라.
1. 	If odd, subtract 1 to make it even  
	픽셀 값이 홀수이면 1을 빼서 짝수로 만든다.
2. 	If there are some data, (use 'bitlen and idx'), and if the corresponding bit is 1, set the pixel (p) to be odd.  
	남은 데이터가 있고, (bitlen, idx 변수를 활용하라), 대응하는 bit가 1이면 픽셀 p를 홀수로 만든다.
			
#### 1.1.2 Decryption
Implement `dec_evenodd_gray()` function in enclib.c    
enclib.c의 `dec_evenodd_gray()` 함수를 완성하라.
1. 	If the pixel (p) is odd, set the bit of data to 1.  Otherwise (if even), set it to 0.  
	만약 픽셀 값 p가 홀수이면, data의 bit를 1로 설정한다. 아니라면, (짝수라면), 0으로 설정한다.
			
### 1.2 RGB
Use RGB value, in order of R-G-B. Use `rgb` array of BMPImage.  
RGB 값을 R-G-B 순서로 사용한다. BMPImage 구조체의 `rgb` 배열을 사용하여라.
#### 1.2.1 Encryption
For all pixel and each r, g, b,
Implement `enc_evenodd_rgb()` function in enclib.c  
enclib.c의 `enc_evenodd_rgb()` 함수를 완성하라.
모든 픽셀과 각 픽셀의 r, g, b값에 대해서,
1. 	If odd, subtract 1 to make it even  
	픽셀 값이 홀수이면 1을 빼서 짝수로 만든다.
2. 	If there are some data, (use 'bitlen and idx'), and if the corresponding bit is 1,  
	set the color value (r, g, or b) to be odd in the order of r-g-b.  
	남은 데이터가 있고, (bitlen, idx 변수를 활용하라), 대응하는 bit가 1이면 픽셀 r, g, b 중 하나를 r-g-b 순서대로 홀수로 만든다.
			
#### 1.2.2 Decryption
Implement `dec_evenodd_rgb()` function in enclib.c    
enclib.c의 `dec_evenodd_rgb()` 함수를 완성하라.
1. 	If the corresponding color pixel (r, g, or b) is odd, set the bit of data to 1.
	Otherwise (if even), set it to 0.  
	만약 픽셀 값 r, g, 또는 b가 홀수이면, data의 bit를 1로 설정한다. 아니라면, (짝수라면), 0으로 설정한다.
	
## Assignment 2 : RGB-Shuffle
Use RGB value, using the order specified by the parameter 'passwd'.  
RGB 값을 입력된 순서대로 사용한다. 매개변수 passwd를 사용하여라.
### 2.1 Implementation
#### 2.1.1 Encryption
For all pixel and each r, g, b,
Implement `enc_evenodd_rgb()` function in enclib.c  
enclib.c의 `enc_evenodd_rgb()` 함수를 완성하라.
모든 픽셀과 각 픽셀의 r, g, b값에 대해서,
1. 	If odd, subtract 1 to make it even  
	픽셀 값이 홀수이면 1을 빼서 짝수로 만든다.
2. 	If there are some data, (use 'bitlen and idx'), and if the corresponding bit is 1,  
	set the color value (r, g, or b) to be odd in the order of r-g-b.  
	남은 데이터가 있고, (bitlen, idx 변수를 활용하라), 대응하는 bit가 1이면 픽셀 r, g, b 중 하나를 r-g-b 순서대로 홀수로 만든다.
			
#### 2.1.2 Decryption
Implement `dec_evenodd_rgb()` function in enclib.c    
enclib.c의 `dec_evenodd_rgb()` 함수를 완성하라.
1. 	If the corresponding color pixel (r, g, or b) is odd, set the bit of data to 1.
	Otherwise (if even), set it to 0.  
	만약 픽셀 값 r, g, 또는 b가 홀수이면, data의 bit를 1로 설정한다. 아니라면, (짝수라면), 0으로 설정한다.

### 2.2 Find Password
TODO

### 2.3 How to find password easily?
TODO

## Assignment 3 : Byte-Shuffle
TODO

## Assignment 4 : Random-Shuffle	(Not for elementary)
TODO

## Assignment 5 : Hashing	(Only for Lv3)
TODO

## Assignment 6 : Creative Technique
TODO

## Assignment 7 : Presentation
TODO
			