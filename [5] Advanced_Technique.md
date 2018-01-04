## Assignment 5 : Advanced Technique (Only for Lv3)
C언어 레벨3용 과제입니다. C언어 레벨2에서는 생략합니다.
### 5.1 Hashing
TODO
### 5.2 File encryption
TODO
### 5.3 Compression [Optional]
TODO

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