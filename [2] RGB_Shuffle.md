# Assignment 2 : RGB-Shuffle
Use RGB value, using the order specified by the parameter 'passwd'.  
RGB 값을 입력된 순서대로 사용한다. 매개변수 passwd를 사용하여라.
## 2.1 Implementation
### 2.1.1 Encryption
For all pixel and each r, g, b,
Implement `enc_evenodd_rgb()` function in enclib.c  
enclib.c의 `enc_evenodd_rgb()` 함수를 완성하라.
모든 픽셀과 각 픽셀의 r, g, b값에 대해서,
1. 	If odd, subtract 1 to make it even  
	픽셀 값이 홀수이면 1을 빼서 짝수로 만든다.
2. 	If there are some data, (use 'bitlen and idx'), and if the corresponding bit is 1,  
	set the color value (r, g, or b) to be odd in the order of r-g-b.  
	남은 데이터가 있고, (bitlen, idx 변수를 활용하라), 대응하는 bit가 1이면 픽셀 r, g, b 중 하나를 r-g-b 순서대로 홀수로 만든다.
			
### 2.1.2 Decryption
Implement `dec_evenodd_rgb()` function in enclib.c    
enclib.c의 `dec_evenodd_rgb()` 함수를 완성하라.
1. 	If the corresponding color pixel (r, g, or b) is odd, set the bit of data to 1.
	Otherwise (if even), set it to 0.  
	만약 픽셀 값 r, g, 또는 b가 홀수이면, data의 bit를 1로 설정한다. 아니라면, (짝수라면), 0으로 설정한다.

## 2.2 Find Password
TODO

## 2.3 How to find password easily?
TODO