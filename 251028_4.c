#include <stdio.h>

// //함수 포인터의 개념 - 함수 포인터를 사용한 함수 호출
// int sum(int,int);

// int main(void){
//     int (*fp)(int,int);
//     int res;

//     fp = sum;
//     res = fp(10,20);
//     printf("result: %d\n", res);

//     return 0;
// }

// int sum(int a, int b){
//     return (a + b);
// }

//함수 포인터의 활용- 함수 포인터로 원하는 함수를 호출하는 프로그램
void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void){
    int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요: ");
    scanf("%d", &sel);

    switch(sel)
    {
        case 1: func(sum); break;
        case 2: func(mul); break;
        case 3: func(max); break;
    }
   return 0;
}

void func(int(*fp)(int,int))
{
    int a,b;
    int res;

    printf("두 정수의 값을 입력하세요:");
    scanf("%d%d", &a, &b);
    res = fp(a,b);
    printf("결괏값은 : %d\n", res);
}

int sum(int a, int b)
{
    return (a+b);
}

int mul(int a, int b)
{
    return (a*b);
}

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}