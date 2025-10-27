#include <stdio.h>

void print_ary(int *pa, int size);

int main(void)
{
    int ary1[5] = {10,20,30,40,50};
    int ary2[7] = {10,20,30,40,50,60,70};

    int count1;
    int count2;
    
    count1 = sizeof(ary1) / sizeof(ary1[0]);
    count2 = sizeof(ary2) / sizeof(ary1[0]);
    //count = sizeof_func(ary1);
   


    print_ary(ary1, count1);
    printf("\n");
    print_ary(ary2, count2);

    return 0;
}

void print_ary(int *pa, int count)
{
    int i;

    for(i=0; i<count; i++){
        printf("%d ", pa[i]);
    }
}

// int sizeof_func(int ary1[]){

//     return sizeof(ary1) / sizeof(ary1[0]);
// }