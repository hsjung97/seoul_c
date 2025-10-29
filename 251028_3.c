#include <stdio.h>

// int main(void){
//     int a= 10,b=20;
//     int *pa = &a, *pb=&b;
//     int **ppa = &pa, **ppb=&pb;
//     int *pt;
    
//     pt = *ppa;
//     *ppa = *ppb;
//     *ppb = pt;

//     printf("a : %d, b:%d\n", a, b);
//     printf("*pa : %d, *pb:%d\n", *pa, *pb);

//     return 0;
// }

int *func(int a,int *x);

int main(void){

    int i;
    int x = 10;
    int *p;
    int a[100];

    for(i=0; i<100; i++){
        a[i] = i*10;
    }

    p = func(x,a);
    printf("sum = %d\n", x+a[0]+a[1]+p[0]+p[1]);
    return 0;

}

int *func(int a,int *x){
    a = a+10;
    x = x+1;
    *x = *x *2;

    return x;
}