// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     //inform
//     int l_load = 30;
//     float vel = 2.9;
//     float R = 0.1;
    
//     //battery
//     int v = 36;
//     int c = 30;
//     float eta = 0.9;

//     //condition

//     //enable energy
//     float enable_energy = v * c * eta * (1 - R);

//     //w
//     float p = (v * l_load) / eta;

//     //runtime
//     float t = enable_energy / p;

//     //km
//     float d = vel * t;
    

//     printf("W = %f,runtime = %f, km = %f", p, t, d);
// }


#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
   double I_load, vel, R, V, C, eta;
    int n;


    
    printf("평균전류 I_load [A] (부하측) :");    if (scanf("%lf", &I_load) != 1) return 1;
    printf("평균속도 vel [km/h]         :");    if (scanf("%lf", &vel) != 1) return 1;
    printf("예비율 R [20% = 0.2]       :");    if (scanf("%lf", &R) != 1) return 1;
    printf("모터 개수 n[개]             :");    if (scanf("%d", &n) != 1) return 1;

    printf("공칭전압 V [V]               :");   if (scanf("%lf", &V) != 1) return 1;
    printf("용량 C [Ah]                 :");   if (scanf("%lf", &C) != 1) return 1;
    printf("시스템효율 eta [90% = 0.9]   :");    if (scanf("%lf", &eta) != 1) return 1;


    //입력범위 검증
    if( V <= 0 || C <= 0 || n <= 0 ||  I_load <= 0 || vel < 0 || R <= 0 || R>= 1 || eta<= 0 || eta > 100){
        printf("입력값 범위를 확인하세요\n");
        return 1;
    }


    //소비전력
    const double P = ((V * I_load) / eta) * n;

    //사용 가능 에너지(Wh)
    const double E_usable = V * C * eta * (1.0 - R);

    //런타임 계산(h)
    const double t_h = E_usable / P;
    const double t_min = t_h * 60.0;

    //주행거리 계산(km)
    const double d_km = vel * t_h;

    //출력결과
    printf("-----------------사용결과-----------------\n");
    printf("사용 가능 에너지 E_usable  :  %.1f Wh\n",         E_usable);
    printf("런타임 t                 :  %.1f (%.1f min)\n", t_h, t_min);
    printf("주행거리 d                :  %.1f km/n",        d_km);

    return 0;

    
}

