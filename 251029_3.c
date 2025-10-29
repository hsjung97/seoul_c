#include <stdio.h>
//구조체 포인터와 -> 연산자

struct score
{
    int kor;
    int eng;
    int math;
    char hsjung[10];


};

int main(void){
    struct score yuni = {90,80,70,"hsj"};
    struct score *ps = &yuni;

    printf("국어: %d\n", (*ps).kor);
    printf("영어: %d\n", ps -> eng);
    printf("수학: %d\n", ps -> math);
    printf("hsjung: %s\n", ps -> hsjung);

    return 0;
}