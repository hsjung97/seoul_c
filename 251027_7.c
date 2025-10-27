//가로세로의 합 구하기
//5행 6열 2차원 배열을 선언하고  마지막 열의 요소에는  각 행의 합을 저장하고 
//마지막 행의 요소에는 각 열의 합을 저장한 후 전체 배열의 값을 출력하세요.

#include <stdio.h>

int main(void){

    int score[5][6] = {
        {1,2,3,4,5,0},
        {6,7,8,9,10,0},
        {11,12,13,14,15,0},
        {16,17,18,19,20,0},
        {0,0,0,0,0,0}
    };



        for(int i=0; i<4; i++){
            for(int j=0; j<5; j++){
                score[i][5] += score[i][j];
            }
        }

        for(int x=0; x<6; x++){
            for(int y=0; y<4; y++){
                score[4][x] += score[y][x];
            }
        }

    


        printf("==========출력===========\n");
        for(int q=0; q<5; q++){
            printf("\n");
            for(int w=0; w<6; w++){         
                printf("%d  ", score[q][w]);
            }
        }
        return 0;
    }
  




    



