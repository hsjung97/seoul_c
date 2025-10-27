#include <stdio.h>

// //포인터 배열 선언과 사용 - 포인터 배열로 여러 개의 문자열 출력
// int main(void){

//     char *pary[5];
//     int i;

//     pary[0] = "dog";
//     pary[1] = "elephant";
//     pary[2] = "horse";
//     pary[3] = "tiger";
//     pary[4] = "lion";

//     for(i=0; i<5; i++)
//     {
//         printf("%s\n", pary[i]);
//     }
//     return 0;
// }

//2차원 배열처럼 활용하는 포인터 배열 - 여러 개의 1차원 배열을 2차원 배열처럼 사용

int main(void)
{
    int ary1[4] = {1,2,3,4};
    int ary2[4] = {11,12,13,14};
    int ary3[4] = {21,22,23,24};
    int *pary[4] = {ary1,ary2,ary3};
    int i, j;

    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }
    return 0;

}