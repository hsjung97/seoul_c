#include <stdio.h>
#include <string.h>

//문자열을 대입하는 strcpy함수 - strcpy함수의 사용법
// int main(void)
// {
//     char str1[80] = "strawberry";
//     char str2[80] = "apple";
//     char *ps1 = "banana";
//     char *ps2 = str2;
//
//     printf("최초 문자열 : %s\n", str1);
//     strcpy(str1, str2);
//     printf("바뀐 문자열 : %s\n", str1);
//
//     strcpy(str1, ps1);
//     printf("바뀐 문자열 : %s\n", str1);
//
//     strcpy(str1, ps2);
//     printf("바뀐 문자열 : %s\n", str1);
//
//     strcpy(str1, "banana");
//     printf("바뀐 문자열 : %s\n", str1);
//
//     return 0;
// }



// 원하는 개수의 문자만을 복사하는 strncpy - strncpy함수를 사용한 문자열 복사
// int main(void)
// {
//     char str[20] = "mango tree";
//     strncpy(str, "apple-pie",5);
//     printf("%s\n", str);
//     return 0;
// }






// int main(void){
//     int a = 20;
//     int b = 30;

//     swap(&a,&b);

//     printf("%d,%d", a,b);
// }

// void swap(int *a, int *b){
//     int temp;
    
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }