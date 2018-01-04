# Additional Introduction

## 0. Some information
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

### 0.3 Setting
먼저, 본 과제 파일, 즉 bmpENC를 사용할 수 있게 세팅해야 합니다.

Download ZIP을 하시거나, [**이 링크**](https://github.com/RangeWING/bmpENC/archive/master.zip)를 눌러주세요.  
그러면 이 프로젝트가 통째로 받아질텐데, bmpENC 폴더 안에 있는 파일만 사용합니다.  
사용하고 있는 IDE에서 프로젝트를 생성한 후, bmpENC 폴더 안에 있는 파일을 해당 프로젝트 위치로 붙여넣으시면 됩니다.  
Visual Studio의 경우, 파일이 자동으로 불러와지지 않으면 main.c는 '소스 파일'에, 나머지는 '헤더 파일'에 드래그해서 넣어주세요.  
또한, 해당 헤더를 main에서 찾지 못한다면 프로젝트 우측 클릭 -> 속성 -> 구성 속성 -> VC++ 디렉터리 메뉴에서 '포함 디렉터리'에 . (점 하나)를 추가해주세요. 

그래도 안 된다면, (혹은 Dev-C++이라면,) 다음과 같이 해주세요. (Windows)
- 윈도우즈 키 + R을 누르고, sysdm.cpl이라고 쓴 후 확인을 누릅니다.
- '시스템 속성' 창에서 '고급' 탭을 누른 뒤, 하단의 '환경 변수'를 누릅니다.
- 시스템 변수에서 Include를 찾아 편집을 누르고, 새로 만들기에서 `.`을 추가합니다.
  - Include가 없으면 새로 만듭니다.
- PATH를 찾아 동일하게 합니다.  

### 0.4 Handling Pictures
본 과제에서는 사진(BMP)을 다루기 위해 [tqbmp](https://github.com/RangeWING/tqbmp)를 사용합니다.  
[tqbmp](https://github.com/RangeWING/tqbmp)에 대한 설명은 해당 라이브러리 링크에 설명해 두었으니 참고해주세요.  

+ 사진의 각 픽셀 값은 0 이상 255 이하인 점을 유의해주세요. (uint8_t 형입니다.)
+ 기본적으로 unsigned형들을 사용합니다. 
  + uint8_t는 8bit (1byte) unsigned 정수입니다. 
  + uint는 uint32_t와 같으며, 32bit (4byte) unsigned 정수입니다.
+ 처리 속도 상 64x64, 128x128, 320x240 정도의 작은 사진을 권장합니다. 문자열 기준으로 각각 약 500, 2000, 10000자 저장 가능합니다.
+ Bit 단위로 문자를 쪼개기때문에, 멀티바이트인 한글은 지원되지 않을 수 있습니다. **영어만 입력해주세요.**
