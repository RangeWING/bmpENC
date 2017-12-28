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

### 1. Even/Odd
Assignment 1은 Even/Odd 기법, 즉 LSB를 이용한 암호화입니다.  
이 기법은 사진의 각 픽셀에 하나의 **Bit**를 숨기는 방법으로, 픽셀값이 **짝수**이면 **0**을, **홀수**이면 **1**을 나타냅니다.  
예를 들어, 흑백 사진의 픽셀을 읽었을 때 값이 순서대로 `17 125 70 32`라면, 숨겨진 값은 `1100`입니다.  

구현 방법에 대해서는 [Assignment 1 : Even/Odd Encryption](%5B1%5D%20Even_Odd_Encryption.md) 파일을 참고해주세요.


### 2. RGB-Shuffle
Assignment 2는 E/O RGB 기법대로 저장할 때,  
R-G-B 순서대로 저장하지 않고 G-B-R 등 다른 방법으로 저장하는 기법입니다.  
다른 사람이 사진에 데이터가 숨겨져있다는 것을 눈치채도 실제 데이터를 파악하기 어렵게 하기 위해서 이와 같은 일을 합니다. (라고 설명해주시면 됩니다.)  

마찬가지로 구현 방법은 [Assignment 2 : RGB-Shuffle](%5B2%5D%20RGB_Shuffle.md)를 참고해주세요.

암호 분석은 RGB가 bit단위로 섞여있기 때문에, bit단위로 분석해야 합니다.  
dec_...함수를 통해 얻은 bit array를 출력해본 뒤, README의 0.2.1 Header/Footer를 참고해서 데이터를 찾아주세요.  
정상적인 데이터는 항상 `0x0F 0xFF 0x33 0x55`로 시작합니다.  
이를 bit단위로 보면 `0000 1111 1111 1111 0011 0011 0101 0101`입니다. 출력된 Bit를 보고 정상적인 헤더를 어떻게 섞으면 이와 같은 bit가 나올 지 생각해보세요.  


