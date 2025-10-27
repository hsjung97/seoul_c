#include <stdio.h>

int main(void)
{
    char small,cap = 'G';

    if((cap >= 'A') && (cap <= 'Z'))
    {
        small = cap +('a' - 'A'); //a:97 A:65
    }
    printf("대문자: %c %c", cap,'\n');
    printf("소문자: %c", small);

    return 0;
}