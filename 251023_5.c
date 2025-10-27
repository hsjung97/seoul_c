#include <stdio.h>

int main(void){

    int a = 10, b =20;
    const int*pa = &a;   //*pa = 20;(x) a는 pa를 간접 참조하여 바꿀 수 없다.

    printf("변수 a의 값: %d\n", *pa);
    pa = &b;


    printf("변수 b의 값: %d\n", *pa);
    pa = &a;
    a=20;
    
    printf("변수 c의 값: %d\n", *pa);

    return 0;
    
}