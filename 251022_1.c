#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
srand(time(NULL));

int num1 = rand() % 10;
int num2 = rand() % 100 + 1;
int num3 = rand() % 21 - 10;

printf("0~9 랜덤: %d\n", num1);
printf("1~100 랜덤: %d\n", num2);
printf("-10~10 랜덤: %d\n", num3);

return 0;
}
