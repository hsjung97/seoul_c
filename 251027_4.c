#include <stdio.h>
#include <time.h>

// //지역 변수
// void assign(void);

// int main(void){
//     auto int a =0;

//     assgin();
//     printf("main 함수 a : %d\n", a);

//     return 0;
// }

// void assgin(void){
//     int a;

//     a = 10;
//     printf("assign 함수 a : %d\n", a);
// }


// //전역 변수

// void assign10(void);
// void assign20(void);

// int a; //전역변수는 자동초기화

// int main(void)
// {
//     printf("함수 호출 전 a값 : %d\n",a);

//     assign10();
//     assign20();

//     printf("함수 호출 후 a값 : %d\n", a);

//     return 0;
// }

// void assign10(void)
// {
//     a = 10;
// }

// void assign20(void)
// {
//     int a;

//     a = 20;
// }

// //정적 지연 변수
// void auto_func(void);
// void static_func(void);

// int main(void){

//     int i;

//     printf("일반 지역 변수(auto)를 사용한 함수...\n");
//     for(i=0; i<3; i++){
//         auto_func();
//     }

//     printf("정적 지역 변수(static)를 사용한 함수...\n");
//     for(i=0; i<3; i++){
//         static_func();
//     }
//     return 0;
// }

// void auto_func(void){
    
//     auto int a = 0;

//     a++;
//     printf("%d\n",a);
// }

// void static_func(void){
//     static int a;
//     a++;
//     printf("%d\n",a);
// }




//레지스터 변수
//register 0.012707
//int 0.022492
int main(void){
    
    clock_t start = clock();

    register int i;
    int sum = 0;

    for(i=1; i<=10000000; i++){
        sum += i;
    }

    printf("%d\n", sum);


    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("실행 시간: %f초\n", duration);

    return 0;
}