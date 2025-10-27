#include <stdio.h>

// 함수 선언 (main 함수 위에 명확하게 정의)
long long sum_index_of_black(const int label[], int N);
double avg_index_of_black(long long sum_index, int black_count);


long long sum_index_of_black(const int label[], int N){
    long long sum_index = 0;
    long long index_avg = 0;

    for(int i= 0; i< N; i++){
        sum_index += (long long)i * label[i];
    }
    return sum_index;
}

double avg_index_of_black(long long sum_index, int black_count){
    if (black_count == 0) {
        return 0.0; // 0으로 나누는 오류 방지
    }
    return (double)sum_index / black_count;
}



int main(void){

    int N;
    int threshold;
    int black_count = 0;

    long long sum_index;
    double index_avg;
    
    //입력
    printf("N입력: ");
    scanf("%d", &N);

    printf("threshold입력: ");
    scanf("%d", &threshold);

    int value[N];
    int label[N];

        printf("====%d개의 value를 입력하세요====\n", N);

        for(int i=0; i<N; i++){

            printf("value[%d]을 입력하세요: ", i);
        
        if (scanf("%d", &value[i]) != 1) {
            printf("잘못된 입력입니다. 프로그램 종료.\n");
            return 1; 
        }

            if(value[i] < threshold){
                label[i] = 1;
                black_count += 1;
            } else {
                label[i] = 0;
            }


    }
    // 1. 합계 계산 및 저장: 루프가 끝난 후 호출
    sum_index = sum_index_of_black(label, N);
    
    // 2. 평균 계산 및 저장: black_count를 인자로 넘겨 호출
    index_avg = avg_index_of_black(sum_index, black_count);

    // 최종 출력
    printf("\n===출력 예시====\n");
    printf("black_count = %d\n", black_count);
    // long long 출력은 %lld
    printf("sum_index = %lld\n", sum_index); 
    // double 출력은 %.2f (소수점 둘째 자리까지)
    printf("index_avg = %.2f\n", index_avg); 

    return 0;
}


