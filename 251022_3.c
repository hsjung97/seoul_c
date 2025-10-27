#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

int main(void){

    int battery[NUM];
    int warning = 0; //0:OFF, 1:ON
    int level = 0;




    for(int i=0; i<NUM; i++){
        printf("배터리 잔량(%)을 입력하세요:");

        // 배열 인덱스를 i로 사용하여 올바른 위치에 입력
        if (scanf("%d", &battery[i]) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }



        if(warning == 0 && battery[i] <= 30){
                warning = 1;
                printf("%d\n", warning);
            }else if (warning == 1 && battery[i] >= 35){
                warning = 0;
                printf("%d\n", warning);
            }else {
                printf("%d\n", warning);
            }
            

    }
    printf("\n[배터리 히스테리시스 경보 결과]\n");
    
}