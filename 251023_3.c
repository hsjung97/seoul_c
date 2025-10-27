#include <stdio.h>

int main(void){
    int a;
    double b;
    char c;
    int *pa; //pa라는 변수를 선언하고 초기화하는 역할을 모두포함


    pa = &a;
    *pa = 10;



    printf("int형 변수의 주소 : %p\n", &a);  //%p 16진수 
    printf("double형 변수의 주소 : %p\n", &b);
    printf("char형 변수의 주소 : %p\n", &c);


    //포인터를 사용하면 a를 initial하지않고 접근가능??
    printf("포인터로 a값 출력 : %d\n", *pa);  //*pa는 a의 값(10)
    printf("포인터 pa값 출력 : %p\n", pa);   //pa는 a의주소(%d로 출력(x))
    printf("변수명으로 a값 출력 : %d\n", a); 


    return 0;


}