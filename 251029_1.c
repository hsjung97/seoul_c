#include <stdio.h>

// //공용체- 공용체를 사용한 학번과 학점 데이터 처리
// union student
// {
//     int num;
//     double grade;
// };

// int main(void){
//     union student s1 = {315};

//     printf("학번 : %d\n", s1.num);
//     s1.grade = 4.4;
//     printf("학점 : %.1lf\n", s1.grade);
//     printf("학번 : %d\n", s1.num);
    
//     return 0;
// }

//열거형

enum season {SPRING= 5,SUMMER, FALL= 10, WINTER};

int main(void){
    enum season ss;
    char*pc = NULL;

    ss = SPRING;

    switch(ss)
    {
        case SPRING:
            pc = "inline";break;
        case SUMMER:
            pc = "swimming";break;
        case FALL:
            pc = "trip";break;
        case WINTER:
            pc = "skiing";break;
        }
        printf("나의 레저 활동 => %s\n", pc);

        return 0;


    }    
