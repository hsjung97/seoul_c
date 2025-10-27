#include <stdio.h>

int main(void)
{
    int score[5];
    int i;
    int total = 0;
    double avg = 0;
    int count;

    count = sizeof(score) / sizeof(score[0]);

    for( i=0; i<count; i++)
    {
        printf("숫자 입력:");
        scanf("%d", &score[i]);
    }

    for( i=0; i<count; i++)
    {
        total += score[i];
    }
    avg = total /(double)count;

    for(i=0; i<count; i++)
    {
        printf("5%d", score[i]);
    }
    printf("\n");

    printf("평균 : %.1lf\n", avg);

    return 0;

}