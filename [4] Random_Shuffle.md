## Assignment 4 : Random-Shuffle	(Not for elementary)
+ 중고등학생 캠프 (2,3차 캠프)용 과제입니다. 1차 캠프에서는 생략합니다.  

### 설명
rand()함수가 srand()로 입력한 seed에 따라 같은 seed일 때는 항상 같은 순서로 난수를 발생시키는 것을 이용한 방법입니다.  
+ 컴파일러 및 컴퓨터에 따라 다른 결과가 나올 수 있음을 유의해야합니다.

#### 4.1 첫 난수만 이용
생성된 처음 난수만 이용합니다.  
입력된 passwd를 이용해 랜덤 시드를 입력하고,  (`srand()`)
처음 난수를 이용하여 순서를 생성한 뒤 이 순서로 byte-shuffle합니다.  

+ 입력된 숫자를 순서로 바꾸기 위해, `encutil.c`의 `intToOrder()`함수를 구현하세요.
  `intToOrder()`함수는 임의의 정수를 `makeOrder()`의 입력 형태, 즉 1 이상 len 이하의 중복되지 않은 숫자로 구성된 정수로 바꾸어야 합니다.
   Hint: len진법을 사용하세요.
   
#### 4.2 자리마다 난수 이용
4-byte 단위로 순서를 바꿉니다.  
예를 들어, 데이터가 `0x0F 0xFF 0x33 0x55 0x11 0x22 0x33 0x44`이고,  
각 자리마다 생성된 난수를 `intToOrder()`하여 생성된 순서가 3-1-4-2, 1-4-2-3라고 가정하면, 
따라서 첫 4byte는 3-1-4-2 순서로 섞고, 다음 4byte는 1-4-2-3으로 섞어서,  
`0x33 0x0F 0x55 0xFF 0x11 0x44 0x22 0x33`이 생성됩니다.

#### 4.3 반전
순서를 바꾸지 않고, 생성되는 난수에 따라 **바이트**를 반전시킵니다.  
매 바이트마다 난수를 생성해서, 짝수면 그대로 두고 홀수면 바이트의 각 비트에 대해 0을 1로, 1을 0으로 바꿔 저장합니다. (비트 반전 연산자 ~를 사용하세요.) 
Byte 단위로 하는 것을 권장합니다.  
예를 들어, 데이터가 `0x0F 0xFF 0x33 0x55 0x11 0x2C 0x33 0xA4`이고,  
생성한 랜덤값이 순서대로 `661 789 1 54 23 87 0 241`이라면, 결과값은 `F0 FF CC 55 EE D3 33 5B`입니다.

+ Byte 단위로 할 때, 데이터의 끝인 `0x00`과 `0xFF`를 반전한 값인 `0x00`을 구분할 수 없습니다. 따라서 `0xFF`은 반전하지 않습니다.


## 4.1 Implementation
Implement `enc_random_shuffle_first()` and `dec_random_shuffle_first()` functions in enclib.c  
The codes can be very short (3~5 lines).  

enclib.c의 `enc_random_shuffle_first()`와  `dec_random_shuffle_first()` 함수를 구현하세요.  
3~5줄 정도로 매우 짧게 구현할 수 있습니다.

## 4.2 Implementation
Implement `enc_random_shuffle_each()` and `dec_random_shuffle_each()` functions in enclib.c  

enclib.c의 `enc_random_shuffle_each()`와  `dec_random_shuffle_each()` 함수를 구현하세요.

## 4.3 Implementation
Implement `enc_random_invert()` and `dec_random_invert()` functions in enclib.c  
Be careful that you must NOT invert 0xFF in order not to be ended there. (Indistinguishable with the end of data)  

enclib.c의 `enc_random_invert()`와  `dec_random_invert()` 함수를 구현하세요.  
0xFF는 반전하지 않아야 하는 점 유의해주세요.