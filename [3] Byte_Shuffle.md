# Assignment 3 : Byte-Shuffle
### 설명
Byte 단위로 섞습니다. (흑백만 한다고 가정합니다.)  
비밀번호는 편의상 4자리로 가정하고, 4개 단위로 섞습니다.  
예를 들어, 정보가 `0x0F 0xFF 0x33 0x55 0x11 0x22 0x33 0x44`였고 비밀번호가 2314라면,  
섞은 결과는 `0xFF 0x33 0x0F 0x55 0x22 0x33 0x11 0x44`가 됩니다.  
dec_...함수의 결과는 항상 bit array이므로 분석하려면 bitToByte()를 사용하는 것이 좋습니다.  

## 3.1 Implementation
### 3.1.1 Encryption
Implement `enc_byte_shuffle()` function in enclib.c  
Hint: Use `bitToByte()` function.

enclib.c의 `enc_byte_shuffle()` 함수를 완성하라.
Hint: `bitToByte()` 함수를 사용하여라.


### 3.1.2 Decryption
Implement `dec_byte_shuffle()` function in enclib.c    
enclib.c의 `dec_byte_shuffle()` 함수를 완성하라.

## 3.2 Find Password
Find the encoded string from the images (`*.enc.bmp`) in `img/3` folder.
`img/3` 폴더에서 `.enc.bmp`로 끝나는 이미지들을 해독하여 숨겨진 글을 찾으세요.  
Hint: **byte** array를 읽고, header를 이용하여 원본이 어떻게 되어야 하는지 생각해보세요.

## 3.3 How to find password easily?
3.2의 과정, 즉 shuffle된 데이터를 원래대로 되돌리는 과정을 알고리즘으로 표현해보세요.  
순서도, 의사코드(pseudocode) 등으로 나타내세요.