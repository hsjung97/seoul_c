#include <stdio.h>
// //이중 포인터 활용2: 포인터 배열을 매개변수로 받는 함수 - 포인터 배열의 값을 출력하는 함수
// void print_str(char **pps, int cnt);

// int main(void){
//     char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
//     int count;

//     count = sizeof(ptr_ary)/ sizeof(ptr_ary[0]);
//     print_str(ptr_ary, count);

//     return 0;
// }

// void print_str(char **pps,int cnt)
// {
//     int i;
//     for(i=0; i<cnt; i++){
//         printf("%s\n", pps[i]);
//     }
// }

// //배열 요소의 주소와 배열의 주소 - 주소로 쓰이는 배열명과 배열의 주소 비교
// int main(void){
//     int ary[5];

//     printf(" ary의 값 : %u\t", ary);
//     printf("ary의 주소: %u\n", &ary);  //4차이
//     printf(" ary +  1: %u\t", ary+1);
//     printf(" &ary + 1: %u\n", &ary+1); //20차이

//     return 0;
// }


//2차원 배열과 배열 포인터 - 2차원 배열의 값을 출력하는 함수

void print_ary(int (*)[4]);

int main(void)
{
    int ary[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    print_ary(ary);

    return 0;
}

void print_ary(int (*pa)[4])
{
    int i, j;
    
    printf("==========결과==========\n");
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
          printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}
