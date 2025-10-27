#include <stdio.h>

//입력 버퍼 지우기 - 버퍼의 내용을 지워야 하는 경우
// int main(void)
// {
//     int num, grade;

//     printf("학번 입력:");
//     scanf("%d", &num);
//     getchar();
//     printf("학점 입력: ");
//     grade = getchar();
//     printf("학번 : %d, 학점 :%c", num, grade);

//     return 0;
// }


//문자열 상수 구현 방법 - **ㄴ문자열 상수가 주소란 증거**
// int main(void)
// {

//     printf("apple이 저장된 시작 주소 값: %p\n","apple");
//     printf("두 번째 문자의 주소 값: %p\n","apple" + 1);      //주소 값 출력
//     printf("첫 번째 문자: %c\n",*"apple");                 //간접 참조 연산
//     printf("두 번째 문자: %c\n",*("apple"+ 1));            //포인터 연산식
//     printf("배열로 표현한 세 번째 문자: %c\n","apple"[2]);    //배열 표현식

//     return 0;
// }

// int main(void)
// {
//     char *dessert = "apple";

//     printf("오늘 후식은 %s입니다.\n", dessert);         //문자열 출력
//     printf("오늘 후식(주소)은 %p입니다.\n", *dessert);   //문자열주소 출력
//     dessert = "banana";                             //새로운 문자열 대입
//     printf("내일 후식은 %s입니다.\n", dessert);         //바뀐 문자열 출력

//     return 0;

// }


// //scanf함수를 사용한 문자열 입력 - scanf 함수를 사용한 문자열 입력
// int main(void)
// {
//     char str[80];

//     printf("문자열 입력 : ");
//     scanf("%s", str);
//     printf("첫 번째 단어 : %s\n", str);
//     scanf("%s", str);
//     printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

//     return 0;
//}

// //gets함수를 사용한 문자열 입력 - gets 함수로 한 줄의 문자열 입력
// int main(void){
//     char str[80];
    
//     printf("공백이 포함된 문자열 입력 : ");
//     gets(str);
//     printf("입력한 문자열은 %s입니다.", str);

//     return 0;
// }

// //fgets 함수를 사용한 문자열 입력 - fgets 함수의 문자열 입력 방법
// int main(void){
//     char str[80];
    
//     printf("공백이 포함된 문자열 입력 : ");
//     fgets(str, sizeof(str), stdin);
//     printf("입력한 문자열은 %s입니다.", str);

//     return 0;
// }

//표준 입력 함수의 버퍼 공유 문제- 개행 문자로 인해 gets 함수가 입력을 못하는 경우
int main(void){

    int age;
    char name[20];

    printf("나이 입력: ");
    scanf("%d", &age);

    printf("이름 입력: ");
    gets(name);
    printf("나이: %d, 이름: %s\n", age, name);

    return 0;
}

