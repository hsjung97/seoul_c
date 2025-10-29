#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){


int N;
int count;

if(scanf("%d", &N)!= 1)return 0;

char num[N];
char num1[N];
int num2[N];

for(int i=0; i<N; i++){
    if(N>=20000 || N <1){
        printf("1=<N=<20000!!");
        break;
    }
        printf("[%d]문자입력", i);
        scanf("%s", &num[i]);

    num1[i]=strlen(num[i]);
    num2[i]=num1[i].sort();

    printf("%c\n",num2[i]);

    }
}