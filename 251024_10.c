#include <stdio.h>

//getchar함수와 putchar함수
// int main(void){
//     int ch;             //입력 문자를 저장할 변수

//     ch = getchar();    //함수가 반환하는 문자를 바로 저장
//     printf("입력한 문자 : ");
//     putchar(ch);            //입력한 문자 출력
//     putchar('\n');          //개행 문자 출력

//     return 0;
// }

//scanf함수가 문자를 입력하는 과정
// int main(void){
//     char ch;
//     int i;

//     for(i=0; i<3; i++){
//         scanf("%c", &ch);
//         printf("%c", ch);
//     }
//     return 0;
// }


//scanf함수의 반환값 활용
int main(void){
    
    int res;
    char ch;

    while(1){
        res = scanf("%c", &ch);
        if(res == -1)break;
        printf("%d", ch);
    }
    return 0;
}