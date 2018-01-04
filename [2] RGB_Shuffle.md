# Assignment 2 : RGB-Shuffle
Use RGB value, using the order specified by the parameter 'passwd'.  
RGB 값을 입력된 순서대로 사용한다. 매개변수 passwd를 사용하여라.

### 추가 설명
Assignment 2는 E/O RGB 기법대로 저장할 때,  
R-G-B 순서대로 저장하지 않고 G-B-R 등 다른 방법으로 저장하는 기법입니다.  
(비밀번호를 지정 가능한데, 예를 들어 312를 입력하면 G-R-B 순서로 저장돼야 합니다. makeOrder() 함수 이용하세요.)  

암호 분석은 RGB가 bit단위로 섞여있기 때문에, bit단위로 분석해야 합니다.  
dec_...함수를 통해 얻은 bit array를 출력해본 뒤, README의 0.2.1 Header/Footer를 참고해서 데이터를 찾아주세요.  
정상적인 데이터는 항상 `0x0F 0xFF 0x33 0x55`로 시작합니다.  
이를 bit단위로 보면 `0000 1111 1111 1111 0011 0011 0101 0101`입니다. 출력된 Bit를 보고 정상적인 헤더를 어떻게 섞으면 이와 같은 bit가 나올 지 생각해보세요.  


## 2.1 Implementation
### 2.1.1 Encryption
For all pixel and each r, g, b,
Implement `enc_rgb_shuffle()` function in enclib.c  
enclib.c의 `enc_rgb_shuffle()` 함수를 완성하라.
모든 픽셀과 각 픽셀의 r, g, b값에 대해서,
1. 	If odd, subtract 1 to make it even  
	픽셀 값이 홀수이면 1을 빼서 짝수로 만든다.
2. 	If there are some data, (use 'bitlen and idx'), and if the corresponding bit is 1,  
	set the color value (r, g, or b) to be odd in the order of r-g-b.  
	남은 데이터가 있고, (bitlen, idx 변수를 활용하라), 대응하는 bit가 1이면 픽셀 r, g, b 중 하나를 r-g-b 순서대로 홀수로 만든다.
  	
+ 	Also you should implement and use `makeOrder()` in `encutil.c` to parse the password  
	password를 사용하기 위해 `encutil.c`의 `makeOrder()`도 구현해야 합니다.
			
### 2.1.2 Decryption
Implement `dec_rgb_shuffle()` function in enclib.c    
enclib.c의 `dec_rgb_shuffle()` 함수를 완성하라.
1. 	If the corresponding color pixel (r, g, or b) is odd, set the bit of data to 1.
	Otherwise (if even), set it to 0.  
	만약 픽셀 값 r, g, 또는 b가 홀수이면, data의 bit를 1로 설정한다. 아니라면, (짝수라면), 0으로 설정한다.

## 2.2 Find Password
Find the encoded string from the images (`*.enc.bmp`) in `img/2` folder.
`img/2` 폴더에서 `.enc.bmp`로 끝나는 이미지들을 해독하여 숨겨진 글을 찾으세요.  
Hint: bit array를 읽고, header를 이용하여 원본이 어떻게 되어야 하는지 생각해보세요.

## 2.3 How to find password easily?
2.2의 과정, 즉 shuffle된 데이터를 원래대로 되돌리는 과정을 알고리즘으로 표현해보세요.  
순서도, 의사코드(pseudocode) 등으로 나타내세요.