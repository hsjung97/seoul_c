#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
   double N, m, SF, DM, R, T, G;
   double c = 0.018;
   double g = 9.81;
   double w;


    
    printf("구동 바퀴 수 N[ea]:");    if (scanf("%lf", &N) != 1) return 1;
    printf("총 하중(질량) m [kg]:");    if (scanf("%lf", &m) != 1) return 1;
    printf("안전 계수 SF [safety Factor]:");    if (scanf("%lf", &SF) != 1) return 1;
    printf("설계 마진 DM [Design Margin]:");    if (scanf("%lf", &DM) != 1) return 1;

    for (int i = 0; i<10; i++){
    printf("=============%d회 반복=============\n", i);
    printf("바퀴 반지름 R [m]:");     if (scanf("%lf", &R) != 1) return 1;
    printf("토크 T [N*m]:");    if (scanf("%lf", &T) != 1) return 1;
    printf("감속비 G:");     if (scanf("%lf", &G) != 1) return 1;


    //입력범위 검증
    // if( V <= 0 || C <= 0 || n <= 0 ||  I_load <= 0 || vel < 0 || R <= 0 || R>= 1 || eta<= 0 || eta > 100){
    //     printf("입력값 범위를 확인하세요\n");
    //     return 1;
    // }


    w = m * g;

    //필요한 최소 견인력(안전계수 포함)
    const double Fmin  = c * w * SF * DM;

    //모터가 낼 수 있는 견인력
    const double Fmotor = ((T * G )/ R)*N;

 
    //출력결과
    printf("-----------------실행결과-----------------\n");
    printf("필요한 최소 견인력 Fmin              :  %.1f N\n", Fmin);
    printf("모터가 낼 수 있는 견인력 Fmotor       :  %.1f N\n", Fmotor);
    
    if(Fmin > Fmotor){
        printf("보다 큰 모터나 감속비가 필요합니다.\n");
    } else {
        printf("괜찮습니다.\n");

    }

    }
    return 0;


}