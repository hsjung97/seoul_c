//라이다 스캔데이터 개수 36
#include <stdio.h>

int main(void)
{
    int score[36];
    int count;
    int min_value;
    int min_index;


    char min_3_index[2];
    min_3_index[0] = '0';
    min_3_index[1] = '0';
    min_3_index[2] = '0';

    char min_3_value[2];
    min_3_value[0] = '0';
    min_3_value[1] = '0';
    min_3_value[2] = '0';




    count = sizeof(score) / sizeof(score[0]);

    for(int i=0; i<count; i++)
    {
        printf("숫자 입력: ");
        scanf("%d", &score[i]);
        
       
        if(i ==0){
            min_3_value[2] = score[i];
        } 
        else if(score[i] < min_3_value[2])
        {
            min_3_value[2] = score[i];
            min_3_index[2] = i;
        }
    }

    for(int j=0; j<count; j++)
    {
        if(score[j] == min_3_value[2]){
            continue;
        }
            
        if(j==0){
            min_3_value[1] = score[j];
        }    
            
        else if(score[j] < min_3_value[1]){
            min_3_value[1] = score[j];
            min_3_index[1] = j;    
        }
    }


    for(int k=0; k<count; k++)
    {
        if((score[k] == min_3_value[1]) || (score[k] == min_3_value[2])){
            continue;
        }

        if(k==0){
            min_3_value[0] = score[k];
        }

        else if(score[k] < min_3_value[0]){
            min_3_value[0] = score[k];
            min_3_index[0] = k;   
        }


    }

            
    printf("==============라이다 결과===============\n");

    printf("가장 가까운 거리:     %d\n", min_3_value[2]);
    printf("그다음 가까운 거리:   %d\n",  min_3_value[1]);
    printf("그그다음 가까운 거리: %d\n",  min_3_value[0]);

    printf("가장 가까운 장애물 방향:    %d\n", min_3_index[2]);
    printf("그다음 가까운 장애물 방향:  %d\n",  min_3_index[1]);
    printf("그그다음 가까운장애물 방향:  %d\n", min_3_index[0]);
}      