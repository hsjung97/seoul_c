#include <stdio.h>
#include <string.h>

#define SWAP(x,y,temp) ((temp)=(x),(x)=(y), (y)=(temp))  //선택 정렬


struct student {

    char name[20];             //학생이름
    int num;                   //학번
    int score[3];              //국어,영어, 수학점수
    double average;            //평균
    int sum;                   //총점
    char grade[5];             //A,B,C

};
typedef struct student hsj;

//함수 선언 수정해야함
//void print_data(hsj *ps);
void print_data(hsj h1[], int N);
void sort_students_by_sum(hsj h1[],int N);

int main(void){

    int N = 5;

    hsj h1[N];
    
 
    for(int i=0; i<N; i++){
        printf("학번을 입력하세요: ");
        if(scanf("%d", &h1[i].num) != 1)return 1;
        

        //문자열(배열) 이름 자체는 이미 주소이므로 &를 제거
        printf("이름을 입력하세요: ");
        if(scanf("%s", h1[i].name) != 1)return 1;

        printf("국어, 영어, 수학 점수을 입력하세요: ");
        if(scanf("%d %d %d", &h1[i].score[0], &h1[i].score[1], &h1[i].score[2]) != 3)return 1;

    
        h1[i].sum = h1[i].score[0]+ h1[i].score[1] + h1[i].score[2];

        //(double)추가
        h1[i].average =  (double)h1[i].sum /3;



        //배열에 문자열을 대입할 때는 strcpy함수를 사용해야 합니다.
        if(h1[i].average >= 90){
            strcpy(h1[i].grade ,"A");
        } else if(h1[i].average >= 80){
            strcpy(h1[i].grade ,"B");
        } else if(h1[i].average >= 70){
            strcpy(h1[i].grade ,"C");
        } else {
            strcpy(h1[i].grade ,"F");
        }
    
    }

    //print_data(&h1, N);
    print_data(h1, N);

    //sort_students_by_sum(h1, N);


    return 0;
}


//void print_data(hsj *ps, int N)
void print_data(hsj h1[], int N)
{
    printf("#정렬 전 데이터...\n");
    for(int i = 0; i<N; i++){
        //printf("%d  %s  %d  %d  %d  %d  %.2f  %s\n",ps -> num, ps ->name, ps-> score[0], ps->score[1], ps ->score[2], ps -> sum, ps -> average, ps->grade);
        printf("%d  %s  %d  %d  %d  %d  %.2f  %s\n",h1[i].num, h1[i].name, h1[i].score[0], h1[i].score[1], h1[i].score[2], h1[i].sum, h1[i].average, h1[i].grade);

    }


    printf("#정렬 후 데이터...\n");
    hsj temp;
    
    //버블 정렬 (Bubble Sort)
    // for (int i = 0; i < N - 1; i++) {
    //     for (int j = 0; j < N - 1 - i; j++) {
    //         // 현재 학생의 총점(sum)이 다음 학생의 총점보다 작으면 (내림차순을 위해)
    //         if (h1[j].sum < h1[j+1].sum) {
    //             // 구조체 전체를 통째로 교환합니다.
    //             temp = h1[j];
    //             h1[j] = h1[j+1];
    //             h1[j+1] = temp;
    //         }
    //     }
    // }

    //선택 정렬
    int max; 
    for(int i=0; i<N-1; i++){
        max = i;

        for(int j= j+1; j<N; j++){
            if(h1[j].sum > h1[max].sum){
                max = j;
            }
        }

         if(i != max){
            SWAP(h1[i], h1[max], temp);
         }
    }


    for(int i = 0; i<N; i++){
        printf("%d  %s  %d  %d  %d  %d  %.2f  %s\n",h1[i].num, h1[i].name, h1[i].score[0], h1[i].score[1], h1[i].score[2], h1[i].sum, h1[i].average, h1[i].grade);
    }

}