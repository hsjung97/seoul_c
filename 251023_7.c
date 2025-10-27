#include <stdio.h>

int main(void){

    int a = 10;

    const int* b = &a;

    //b = &a;
    //*b = 20;

    a=20;
    

    //printf("%d\n",a);
    printf("%d\n",*b);
    
}