#include <stdio.h>

int main(void)
{
    int ary[5];
    int i;

    *(ary +0) = 10;
    *(ary +1) = *(ary + 0) +10;
    *(ary +2) = *(ary + 1) +10;
    *(ary +3) = *(ary + 2) +10;
    *(ary +4) = *(ary + 3) +10;

    printf("다섯번째 배열 요소에 키보드 입력:");
    scanf("%d", ary+5);

    for(i=0; i<6; i++){
        printf("%5d\n", *(ary +i));
    }

    return 0;
}