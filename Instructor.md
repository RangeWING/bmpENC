## Instructor's Mannual
안녕하세요, 개발자 RangeWING입니다.  
본 과제는 C언어를 이용하여 BMP파일에 정보, 특히 문자열을 숨기는 과제입니다.  
이 Mannual에 있는 내용만 교재에 포함해도 큰 문제 없을 겁니다.  
 
과정별 Assignment는 다음과 같습니다.
+ C언어 레벨2 초등: 1, 2, 3, 6, 7  (+4)
+ C언어 레벨2 중고등: 1, 2, 3, 4, 6, 7 (+5)
+ C언어 레벨3: 1, 2, 3, 4, 5, 6, 7 (전체)


먼저, 이해를 돕기 위해 참고 자료 2가지를 준비하였으니 읽어주세요.  
+ 영상: [Principle of Steganography](https://www.youtube.com/watch?v=z_ypj5q5fzE)
+ 글: [스테가노그래피](http://blog.naver.com/PostView.nhn?blogId=namuya11&logNo=40207109776&parentCategoryNo=&categoryNo=29&viewDate=&isShowPopularPosts=true&from=search)  

위 자료 중, 두 번째에 있는 블로그 글이 도움이 될 것입니다.
수업 처음 (창의적 프로젝트 1)에서는 이 자료를 활용하여 암호화 기법 및 스테가노그래피 등에 대해 소개해주시면 됩니다.

### 시작하기 전에
먼저, 본 과제 파일, 즉 bmpENC를 사용할 수 있게 세팅해야 합니다.

Download ZIP을 하시거나, [**이 링크**](https://github.com/RangeWING/bmpENC/archive/master.zip)를 눌러주세요.  
그러면 이 프로젝트가 통째로 받아질텐데, bmpENC 폴더 안에 있는 파일만 사용합니다.  
사용하고 있는 IDE에서 프로젝트를 생성한 후, bmpENC 폴더 안에 있는 파일을 해당 프로젝트 위치로 붙여넣으시면 됩니다.  
Visual Studio의 경우, 파일이 자동으로 불러와지지 않으면 main.c는 '소스 파일'에, 나머지는 '헤더 파일'에 드래그해서 넣어주세요.  
또한, 해당 헤더를 main에서 찾지 못한다면 프로젝트 우측 클릭 -> 속성 -> 구성 속성 -> VC++ 디렉터리 메뉴에서 '포함 디렉터리'에 . (점 하나)를 추가해주세요. 학생들에게도 동일하게 세팅해주시면 됩니다.  


이제, 각 프로젝트에 대해 설명을 드리겠습니다.  
메일로 설명 드렸듯이, 구현보다는 암호가 숨겨진 이미지를 보고 분석해서 찾아내는 과정과,  
이를 간편하게 할 수 있는 방법 고안 (알고리즘 제작 or 툴 제작 등)에 초점을 맞춰주세요.

암호가 숨겨진 이미지는 img 폴더 안에 넣어둘 예정입니다.

### 0. 사진 다루기
본 과제에서는 사진(BMP)을 다루기 위해 [tqbmp](https://github.com/RangeWING/tqbmp)를 사용합니다.  
[tqbmp](https://github.com/RangeWING/tqbmp)에 대한 설명은 해당 라이브러리 링크에 설명해 두었으니 참고해주세요.  
수업에서는 이 내용을 알려주고, Example에 있는 예제 코드도 한번씩 실행해보게 하시면 됩니다.  

+ 사진의 각 픽셀 값은 0 이상 255 이하인 점을 유의해주세요. (uint8_t 형입니다.)
+ 기본적으로 unsigned형들을 사용합니다. 
  + uint8_t는 8bit (1byte) unsigned 정수입니다. 
  + uint는 uint32_t와 같으며, 32bit (4byte) unsigned 정수입니다.
+ 처리 속도 상 64x64, 128x128, 320x240 정도의 작은 사진을 권장합니다. 문자열 기준으로 각각 약 500, 2000, 10000자 저장 가능합니다.
+ Bit 단위로 문자를 쪼개기때문에, 멀티바이트인 한글은 지원되지 않을 수 있습니다. **영어만 입력해주세요.**
  
### 1. Even/Odd
Assignment 1은 Even/Odd 기법, 즉 LSB를 이용한 암호화입니다.  
이 기법은 사진의 각 픽셀에 하나의 **Bit**를 숨기는 방법으로, 픽셀값이 **짝수**이면 **0**을, **홀수**이면 **1**을 나타냅니다.  
예를 들어, 흑백 사진의 픽셀을 읽었을 때 값이 순서대로 `17 125 70 32`라면, 숨겨진 값은 `1100`입니다.  

구현 방법에 대해서는 [Assignment 1 : Even/Odd Encryption](%5B1%5D%20Even_Odd_Encryption.md) 파일을 참고해주세요.


### 2. RGB-Shuffle
Assignment 2는 E/O RGB 기법대로 저장할 때,  
R-G-B 순서대로 저장하지 않고 G-B-R 등 다른 방법으로 저장하는 기법입니다.  
(비밀번호를 지정 가능한데, 예를 들어 312를 입력하면 G-R-B 순서로 저장됩니다. makeOrder() 함수 이용하세요.)

다른 사람이 사진에 데이터가 숨겨져있다는 것을 눈치채도 실제 데이터를 파악하기 어렵게 하기 위해서 이와 같은 일을 합니다. (라고 설명해주시면 됩니다.)  

마찬가지로 구현 방법은 [Assignment 2 : RGB-Shuffle](%5B2%5D%20RGB_Shuffle.md)를 참고해주세요.

암호 분석은 RGB가 bit단위로 섞여있기 때문에, bit단위로 분석해야 합니다.  
dec_...함수를 통해 얻은 bit array를 출력해본 뒤, README의 0.2.1 Header/Footer를 참고해서 데이터를 찾아주세요.  
정상적인 데이터는 항상 `0x0F 0xFF 0x33 0x55`로 시작합니다.  
이를 bit단위로 보면 `0000 1111 1111 1111 0011 0011 0101 0101`입니다. 출력된 Bit를 보고 정상적인 헤더를 어떻게 섞으면 이와 같은 bit가 나올 지 생각해보세요.  

### 3. Byte-Shuffle
Byte 단위로 섞습니다.  
비밀번호는 편의상 4자리로 가정하고, 4개 단위로 섞습니다.  
예를 들어, 정보가 `0x0F 0xFF 0x33 0x55 0x11 0x22 0x33 0x44`였고 비밀번호가 2314라면,  
섞은 결과는 `0xFF 0x33 0x0F 0x55 0x22 0x33 0x11 0x44`가 됩니다.  
dec_...함수의 결과는 항상 bit array이므로 분석하려면 bitToByte()를 사용하는 것이 좋습니다.  
[Assignment 3 : Byte-Shuffle](%5B3%5D%20Byte_Shuffle.md)

### 4. Random-Shuffle
rand()함수가 srand()로 입력한 seed에 따라 같은 seed일 때는 항상 같은 순서로 난수를 발생시키는 것을 이용한 방법입니다.  
1. 첫 난수만 이용
생성된 처음 난수만 이용합니다. 예를 들어, 17395가 나왔다면 뒷 네자리의 순서를 이용할 수 있습니다.  
7-3-9-5의 순서는 3-1-4-2이므로 이 순서로 byte-shuffle할 수 있습니다.
(중복 숫자 발생 시, 혹은 3자리 이하 시에는 적당히 처리해주세요.)

2. 자리마다 난수 이용
4-byte 단위로 순서를 바꿉니다. 예를 들어, 데이터가 `0x0F 0xFF 0x33 0x55 0x11 0x22 0x33 0x44`이고,  
생성된 난수 2개가 `17395 0915`라고 가정하면, 각각의 순서는 3-1-4-2, 1-4-2-3입니다.  
따라서 첫 4byte는 3-1-4-2 순서로 섞고, 다음 4byte는 1-4-2-3으로 섞어서,  
`0x33 0x0F 0x55 0xFF 0x11 0x44 0x22 0x33`이 생성됩니다.

3. 순서를 바꾸지 않고, 생성되는 난수에 따라 비트를 반전시킵니다.  
매 비트마다 난수를 생성해서, 짝수면 그대로 두고 홀수면 0을 1로, 1을 0으로 바꿔 저장합니다.  

단, 컴파일러 및 컴퓨터에 따라 다른 결과가 나올 수 있음을 유의해야합니다.
[Assignment 4 : Random-Shuffle](%5B4%5D%20Random_Shuffle.md)

### 5. Hasing, file, compression
#### 5.1 Hashing
MD5 해싱을 이용하여 Byte 단위로 섞습니다.  
해싱에 대해 소개해주시면 됩니다. 괜찮은 글 첨부했으니 읽어보세요.  
[해시(Hash)란 무엇인가요?](http://blog.naver.com/PostView.nhn?blogId=korbitinc&logNo=220859113675)  

비밀번호를 hash function에 넣고 출력된 값을 **잘** 이용해서 섞으면 됩니다.  
예를 들어, hash의 각 자리값의 홀/짝에 따라 비트를 반전시킬 수 있습니다.  

hash는 아니지만 base64 소개도 좋습니다.

#### 5.2 File encryption
글이 아닌 파일을 암호화해봅니다.  
비교적 작은 사이즈의 파일을 저장해보는 것이 좋습니다.  
가장 만만한 파일로는, 텍스트 파일 (txt)도 좋습니다.  

stdio.h의 fread()함수를 이용해서 파일을 바이트 단위로 읽을 수 있습니다.  
복호화할 때에는 fwrite()함수를 이용합니다.  

### 5.3 Compression [Optional]
시간이 남으면 하시면 됩니다.  
큰 파일을 암호화하기 어려우므로, 압축하는 방법을 **소개**합니다.  
구현까지는 하기 어려울 것 같습니다.  

레벨3에서 Tree를 배우므로, 간단히 Huffman Coding 정도 소개해주시면 좋을 것 같습니다.  
+ [데이터 압축기법](http://ensxoddl.tistory.com/73)
+ [허프만 코딩](http://swlock.blogspot.kr/2016/05/huffman-coding.html)
+ [Text Compression for Web Developers](https://www.html5rocks.com/ko/tutorials/speed/txt-compression/)

[Assignment 5 : Advanced Technique](%5B5%5D%20Advanced_Technique.md)

## 6. Creative Technique
창의적인 암호화 알고리즘을 디자인하면 됩니다.  
다음 두 가지의 암호 체계를 각각 설계합니다.
1. 복호화가 어려운 암호 체계
2. 분석하여 복호화할 수 있는 암호 체계

중고등 및 레벨3에서는 디자인한 알고리즘을 실제 구현하여 이미지를 암호화해봅니다. (위의 2번)  
다른 팀에서 암호화한 이미지를 분석하여 데이터를 알아내는 과제 또한 수행합니다.  
이를 위해, 알고리즘에 다음의 조건이 필요합니다.
1. 복호화가 가능해야 합니다.
2. Random, Hash기법처럼 분석하기 어려운 기법은 사용하지 않습니다.
3. Byte 단위로 데이터를 조작합니다.

[Assignment 6 : Creative Technique](%5B6%5D%20Creative_Technique.md)




