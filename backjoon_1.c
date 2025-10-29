#include <stdio.h>


long long factorial(int m, int n);


int main(void){
    int N, M, t;
    long long a ,num;
    
    //printf("t의 값을 입력하세요: ");
    scanf("%d", &t);
    
    for(int i=0; i<t; i++){
        //printf("N의 값을 입력하세요: ");
        scanf("%d", &N);
        //printf("M의 값을 입력하세요: ");
        scanf("%d", &M);


        if( (N > M) || (N < 0)|| (M > 30)|| (N > 30)){
            printf("다시 입력하세요\n");
        } else {
        
            num =factorial(M, N); 
            //printf("경우의 수: %lld\n", num); 
            printf("%lld\n", num); 
        }
    }  
    return 0;
}   


/**
 *조합(M C N)을 안전하게 계산하는 함수. (팩토리얼 오버플로우 방지)
 */
long long factorial(int M, int N) {
    if (N < 0 || N > M) return 0;
    
    // M C N = M C (M-N) 성질을 이용해 N을 줄여 계산 횟수 최소화
    if (N > M / 2) {
        N = M - N;
    }

    long long result = 1;

    // 공식: (M/1) * ((M-1)/2) * ... * ((M-N+1)/N)
    for (int i = 0; i < N; i++) {
        // 곱셈과 나눗셈을 병행하여 중간 값의 오버플로우를 방지
        result = result * (M - i);
        result = result / (i + 1); 
    }
    return result;
}