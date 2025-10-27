#include <stdio.h>
#include <math.h>

// int main(void)
// {
//     int a = 1;
//     int i;

//     for (printf("hi"); i< 3; i++)
//     {
//         a = a*2;
//     }
//     printf("a :%d\n", a);

//     return 0;

// }


int main(void)
{
    int a = 1;

    do
    {
        a = a*2;
    } while(a <10);
    printf("a: %d\n", a);

    return 0;
}