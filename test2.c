#include <stdio.h>

int main(void)
{
    int a=5, b=5;
    int pre, post;
    double res;

    pre = (++a) * 3;
    post = (b++) * 3;

    printf("초깃값 a = %d, b = %d\n", a, b);
    printf("전위형 : (a++)*3 =  %d, 후위형:(b++)*3 = %d\n", pre, post);

    a =20, b=3;
    res = ((double)a) / ((double)b);
    printf("a = %d, b= %d\n", a, b);
    printf("a/b result: %.lf\n", res);

    a = (int)res;
    printf("(int) %.1lf result : %d\n" ,res, a);

    a=10;
    double d = 3.4;

    printf("int value : %d\n", sizeof(a));
    printf("double value : %d\n", sizeof(d));
    printf("integer value : %d\n", sizeof(10));
    printf("susic value : %d\n", sizeof(1.5+3.4));
    printf("char value : %d\n", sizeof(char));

    a=10, b=20; 
    int big;
    big = (a>b) ? a:b;
    printf("큰 값 : %d\n", big);



    int x = 10;
    int y = 20;

    printf("x & y : %d\n", x & y);
    printf("x ^ y : %d\n", x ^ y);
    printf("x | y : %d\n", x | y);
    printf("~x : %d\n", ~x);
    printf("x << 1 : %d\n", x << 1);
    printf("x >> 2 : %d\n", x >> 2);




    return 0;


}