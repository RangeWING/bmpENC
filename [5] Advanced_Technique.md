## Assignment 5 : Advanced Technique (Only for Lv3)
C언어 레벨3용 과제입니다. C언어 레벨2에서는 생략합니다.  
5.3은 반드시 해주세요.  

### 5.1 Hashing [Optional]
#### (생략 가능)
MD5 해싱을 이용하여 Byte 단위로 섞습니다.  
Hash에 대한 내용은 다음 글 참조하세요.   
[해시(Hash)란 무엇인가요?](http://blog.naver.com/PostView.nhn?blogId=korbitinc&logNo=220859113675)  

비밀번호를 hash function에 넣고 출력된 값을 **잘** 이용해서 섞으면 됩니다.  
예를 들어, random invert와 유사하게 hash의 각 자리값의 홀/짝에 따라 비트를 반전시킬 수 있습니다.  

`encutil.h`의 `struct MD5Hash`와 `void MD5(struct MD5Hash *hash, char *str)` 이용하면 됩니다.  
`MD5()` 함수를 사용하면 `struct MD5Hash`의 byte 멤버에는 16 byte의 hash값이 1바이트씩 배열로 저장됩니다.  
data 멤버는 4byte 배열입니다.  

`enclib.c`의 `enc_hash()`와 `dec_hash()`를 구현하세요.  

 
#### MD5 Example
```
struct MD5Hash hash;
MD5(&hash, "Hello, MD5!");
for(int i=0; i<16; i++)
	printf("%02X", hash.byte[i]);
```

### 5.2 File encryption
#### (가능하면 하는 것이 좋으나, 생략 가능) 
글이 아닌 파일을 암호화해봅니다.  
비교적 작은 사이즈의 파일을 저장해보는 것이 좋습니다.  
가장 만만한 파일로는, 텍스트 파일 (txt)도 좋습니다.  
흑백이 아닌 컬러(RGB)에만 저장해보겠습니다.  

`stdio.h`의 `fread()`함수를 이용해서 파일을 바이트 단위로 읽을 수 있습니다.  
복호화할 때에는 `fwrite()`함수를 이용합니다.  

`enclib.c`의 `enc_file_rgb()`와 `dec_file_rgb()`를 구현하세요.  

구현 방법은 최소 2가지가 있습니다.  
+ (1) 전체 파일을 읽어서 buffer (배열)에 저장해둔 뒤, `enc_evenodd_rgb()`를 사용한다.  
+ (2) 파일의 일부분을 읽어서 이미지에 암호화하고, 이것을 끝까지 반복한다.  

1번은 간단하게 구현할 수 있으나, 메모리가 많이 필요해 비효율적입니다.  
2번은 꽤 복잡하지만 1번보다 훨씬 효율적입니다.  
하지만 여기서는 시간 관계상 1번 방식으로 구현하기를 추천합니다.  
> *[하지만 C를 사랑한다면! 2번도 즐거울 수 있겠지요 :)]*  

1번 방식으로 구현한다면, `byteToBit()`를 사용하기 전에 `attachHeader()`를 실행해줘야 합니다. `byteToBit()`는 헤더를 붙이지 않습니다.  
2번 방식으로 구현하기로 결정했다면, header와 footer를 직접 붙여줘야 합니다. `byteToBit()`는 헤더를 붙이지 않으며, `attachHeader()`는 입력받은 데이터의 일부분 앞뒤로 header와 footer를 붙입니다. 하지만 전체 데이터의 앞과 뒤에만 header와 footer가 있어야 하므로, `attachHeader()`를 사용할 수 없습니다.  

+ **주의: decoding할 때, 큰 buffer가 필요합니다.  
`encutil.h`의 MAX_BUF_SIZE를 50000으로 늘려주세요.** (그러면 5KB 정도의 파일을 암호화할 수 있습니다.)

또한, `dec_file_rgb()`를 구현할 때는, `bitToByte()`함수 대신 `bitToByte_strict()` 함수를 써야 합니다.  
문자열을 암호화할 때는 `0x00`이 나오지 않지만, 파일에는 언제든지 나올 수 있기 때문에 `0x00`으로 끝을 감지하지 못합니다.  
`bitToByte_strict()` 함수는 footer를 감지하여 끝을 맺는 함수입니다. 원형은 다음과 같습니다.  
+ `uint8_t *bitToByte_strict(uint8_t *b, uint *bytelen)`


### 5.3 Compression
큰 파일/데이터를 암호화하기 어려우므로, 압축하는 방법을 **소개**합니다.  
구현까지는 하기 어려울 것 같습니다.  

레벨3에서 Tree를 배우므로, 간단히 Huffman Coding 정도를 소개합니다. 아래 글 읽어보세요. 
+ [데이터 압축기법](http://ensxoddl.tistory.com/73)
+ [허프만 코딩](http://swlock.blogspot.kr/2016/05/huffman-coding.html)
+ [Text Compression for Web Developers](https://www.html5rocks.com/ko/tutorials/speed/txt-compression/)