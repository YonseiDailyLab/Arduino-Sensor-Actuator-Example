/**
Buzzer Example
Description: playing little star using tone function example

Author: Yeseong Kang (kkds002@yonsei.ac.kr)
Date Created: 2024-11-08
Last Updated: 2024-11-08

**/

#define BZ 4

char code[ ]= {'C', 'D', 'E', 'F', 'G', 'A', 'B'};
    float  freq[ ]= {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88};
    char mData[ ]="CCGGAAGpFFEEDDCpGGFFEEDpGGFFEEDpCCGGAAGpFFEEDDCp";
    const  byte mSize=sizeof(mData);

    void  setup( ) {
        pinMode(BZ, OUTPUT);
    }

    void loop( ) {
        int  playT=500;   // 1박자를 0.5초
        for (int  m=0; m<mSize; m++) {
            for(int k=0; k<7; k++) {
                if( mData[m]==code[k] ) {
                    tone(BZ, freq[k], playT);  // freq[k]의 값을 tone( )함수 전달 
                  delay(playT+10);                 // 1박자 연주
                }
            }
            if (mData[m]=='p') {                // 배열 mData[]의 문자가 'p' 인 경우
              delay(playT+10);                     // 1박자 더 쉼
            }
        }
        noTone(BZ);
        delay(2000);
    }  
