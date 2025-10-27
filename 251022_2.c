#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10



int main(void){
    
    
    srand(time(NULL));

    int N, i;
    int delta;
    int plus_speed  = 0;
    int minus_speed = 0;
    //int speed[NUM];

    int speed[NUM];
    speed[0] = (rand()% 51) + 50;    


    for (i=1; i< NUM; i++){
        //printf("주행 로그 입력:");
                
        // // 배열 인덱스를 i로 사용하여 올바른 위치에 입력
        // if (scanf("%d", &speed[i]) != 1) {
        //     printf("잘못된 입력입니다.\n");
        //     return 1;
        // }


        //랜덤인데 그다음숫자가 그전숫자 10범위안에 나오게끔
        //speed[i] = (rand()% 200) + 1;
        
        int prev_speed = speed[i-1];

        
        int m_value = prev_speed+10; if(m_value >200){ m_value = 200;}
        int l_value = prev_speed-10; if(l_value <0){ l_value = 0;}

       
        // min_val 부터 max_val 범위 내의 랜덤 값 생성
        // 공식: (rand() % (Max - Min + 1)) + Min
        //speed[i] = (rand() % (max_val - min_val + 1)) + min_val;
        speed[i] = (rand()% (m_value - l_value + 1)) + l_value;




        //10번마다 배열요소 간 오름차순내림차순 정한후 셀렉해서 speed랜덤화(추가해야함)
         

            // for(k=1; k<10; k++){
               
                 
            //     temp = speed[i]
            //     speed[i] = speed[i-1];

            // }





        printf("%d\n", speed[i]);
      

        delta = speed[i]-speed[i-1];
        
        if (delta > 10){
            plus_speed++;
        } else if (delta < -10){
            minus_speed++;

        } 
        
        



    }
    printf("급가속 횟수: %d\n", plus_speed);
    printf("급정거 횟수: %d\n", minus_speed);

}

