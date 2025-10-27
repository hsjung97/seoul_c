#include <stdio.h>

int main(void){
    int a =10, b= 15, total;
    
    
    double avg;
    
    int *pa, *pb;
    
    
    //[int*pt; pt=&total;] == [int*pa = &total;]

    int *pt = &total;
    //int *pt;
    double *pg = &avg;

    //pt = &total;

    pa = &a;
    pb = &b;

    *pt = *pa + *pb;
    *pg = *pt / 2.0;

    printf("두 정수의 값 :%d, %d\n", *pa, *pb);
    printf("두 정수의 합 :%d\n", *pt);
    printf("두 정수의 평균 :%.1lf\n", *pg);

    return 0;

}