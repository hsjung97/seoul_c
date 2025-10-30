#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10 // 배열 최대 크기를 고정

// 함수 선언
long long sum_index_of_black(const int label[], int N);
double avg_index_of_black(long long sum_index, int black_count);

int main(void){

//공통
int length, radius, m;
int sel;

printf("===이동로봇 기본 사양 입력===\n");
printf("바퀴 간 거리 L[m]: ");
if(scanf("%d", &length) != 1)return 1;

printf("바퀴 반지름 [m]: ");
if(scanf("%d", &radius) != 1)return 1;

printf("로봇 질량 [kg]: ");
if(scanf("%d", &m) != 1)return 1;

printf("\n");
printf("===이동로봇 종합 계산기===\n");
printf("1. IR센서 반사값 임계치 분류기\n");
printf("2. 배터리 사용시간 계산\n");
printf("3. 이동로봇의 모터 적정성 여부 판단\n");
printf("4. 360도 라이다에서 최소거리/방향 찾기\n");
printf("5. 배터리 잔량 히스테리시스 경보 시스템\n");
printf("0. 종료\n");

printf("메뉴 선택: ");
if(scanf("%d", &sel) != 1)return 1;


switch(sel){

    case 1:
    printf("1. IR센서 반사값 임계치 분류기\n");
    
    int N;
    int threshold;
    int black_count = 0;

    long long sum_index;
    double index_avg;
    
    //입력
    printf("N입력 (최대 %d): ", MAX_N);
    if (scanf("%d", &N) != 1 || N <= 0 || N > MAX_N) {
        printf("잘못된 N 값입니다. (1 ~ %d 사이)\n", MAX_N);
        return 1;
    }

    printf("threshold입력: ");
    if (scanf("%d", &threshold) != 1) return 1;

    // ⭐ 수정: 고정 크기 배열 (MAX_N) 선언
    int value[MAX_N];
    int label[MAX_N];

    printf("====%d개의 value를 입력하세요====\n", N);

    for(int i=0; i<N; i++){

        printf("value[%d]을 입력하세요: ", i);
        
        if (scanf("%d", &value[i]) != 1) {
            printf("잘못된 입력입니다. 프로그램 종료.\n");
            return 1; 
        }

        if(value[i] < threshold){
            label[i] = 1; // 흑색 (Black)
            black_count += 1;
        } else {
            label[i] = 0; // 백색 (White)
        }
    }
    
    // 1. 합계 계산
    sum_index = sum_index_of_black(label, N);
    
    // 2. 평균 계산
    index_avg = avg_index_of_black(sum_index, black_count);

    // 최종 출력
    printf("\n===출력 결과====\n");
    printf("black_count = %d\n", black_count);
    printf("sum_index = %lld\n", sum_index); 
    printf("index_avg = %.2f\n", index_avg);

    break;


    case 2:
    printf("2. 배터리 사용시간 계산\n");
    double I_load, vel, R, V, C, eta;
    int n;

    printf("평균전류 I_load [A] (부하측) :");    if (scanf("%lf", &I_load) != 1) return 1;
    printf("평균속도 vel [km/h]          :");    if (scanf("%lf", &vel) != 1) return 1;
    printf("예비율 R [20%% = 0.2]         :");    if (scanf("%lf", &R) != 1) return 1;
    printf("모터 개수 n[개]              :");    if (scanf("%d", &n) != 1) return 1;

    printf("공칭전압 V [V]               :");   if (scanf("%lf", &V) != 1) return 1;
    printf("용량 C [Ah]                  :");   if (scanf("%lf", &C) != 1) return 1;
    // ⭐ 시스템 효율이 %로 입력될 가능성 때문에 100을 넘어가면 오류 처리
    printf("시스템효율 eta [90%% = 0.9]     :");    if (scanf("%lf", &eta) != 1) return 1;


    //입력범위 검증
    if( V <= 0 || C <= 0 || n <= 0 || I_load <= 0 || vel < 0 || R <= 0 || R>= 1 || eta<= 0 || eta > 1.0){ // eta > 100을 eta > 1.0으로 수정
        printf("입력값 범위를 확인하세요 (eta는 0~1.0 사이)\n");
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
    printf("사용 가능 에너지 E_usable  :  %.1f Wh\n",       E_usable);
    printf("런타임 t                   :  %.1f h (%.1f min)\n", t_h, t_min);
    // ⭐ 수정: km/n을 km\n으로 변경
    printf("주행거리 d                 :  %.1f km\n",         d_km);
    break;

    case 3:
    printf("3. 이동로봇의 모터 적정성 여부 판단\n");
    double mass_kg, torque, gear, radius_m, SF, margin; // 변수명 충돌 방지 및 단위 명확화
    int wheels;
    const double g = 9.81; //중력가속도 [9.81 N/㎡]
    const double c = 0.018; //구름저항계수 – 일반적인 고무바퀴 & 아스팔트
    
    //이동로봇 설계 사양 입력
    printf("총 하중(kg) : ");
    if(scanf("%lf", &mass_kg)!= 1) return 1;

    printf("구동 바퀴 수 : ");
    if(scanf("%d", &wheels)!= 1)return 1;

    printf("안전계수 : ");
    if(scanf("%lf", &SF) != 1)return 1;

    printf("설계마진(20%% == 1.2로 입력) : ");
    if(scanf("%lf", &margin) != 1)return 1;

    //모터 및 바퀴 사양 입력
    printf("모터 정격 토크(N〮m) : ");
    if(scanf("%lf", &torque) != 1) return 1;

    printf("감속비 : ");
    if(scanf("%lf", &gear) != 1) return 1;

    printf("바퀴 반지름(m) : ");
    if(scanf("%lf", &radius_m) != 1) return 1; 

    //입력 받은 값으로 견인력 계산
    double Weight_N = mass_kg * g;
    // F_min: 필요한 최소 견인력 (구름 저항력)
    double F_min = c * Weight_N * SF * margin; 
    // F_motor: 모터가 낼 수 있는 견인력
    double F_motor = (torque * gear / radius_m) * wheels;

    printf("\n필요한 최소 견인력 : %.2f [N]\n", F_min);
    printf("모터가 낼 수 있는 견인력 : %.2f [N]\n", F_motor);
    if (F_motor >= F_min){
    printf("판정 : 만족 (모터 견인력이 충분합니다.)\n");
    } else {
    printf("판정 : 불만족 (더 큰 모터나 감속비가 필요.)\n");
    }
    break;


    case 4:
    printf("4. 360도 라이다에서 최소거리/방향 찾기\n");
    
    // ⭐ 수정: 배열 크기를 360으로 늘려 전체 라이다 데이터를 처리할 수 있도록 함
    // (입력은 10개로 제한)
    double dist[360]; 
    int i, min_index = 0;
    double min_value;
    const int TEST_COUNT = 10;

    printf("%d° 라이다 거리값 입력 (테스트용으로 %d개만 입력)\n", 360, TEST_COUNT);
    
    for (i = 0; i < TEST_COUNT; i++) {
        printf("%3d° 거리(cm): ", i);
        if (scanf("%lf", &dist[i]) != 1) return 1;
    }
    
    min_value = dist[0];
    
    for (i = 1; i < TEST_COUNT; i++) {
        if (dist[i] < min_value) {
            min_value = dist[i];
            min_index = i;
        }
    }

    printf("\n[라이다 최소 거리 탐색 결과]\n");
    printf("가장 가까운 거리: %.1f cm\n", min_value);
    printf("장애물 방향: %d°\n", min_index);
    break;

    case 5: 
    printf("5. 배터리 잔량 히스테리시스 경보 시스템\n");

    
    int battery[MAX_N]; // ⭐ 수정: 배열 크기를 MAX_N으로 고정
    int warning = 0; //0:OFF, 1:ON
    
    printf("배터리 잔량(%%)을 입력하세요[MAX_N=%d]:\n", MAX_N);

    for(int i=0; i<MAX_N; i++){
        printf("잔량[%d]: ", i);
        
        if (scanf("%d", &battery[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }


        if(warning == 0 && battery[i] <= 30){
                warning = 1;
                printf("경보 상태: ON (%d)\n", warning);
            }else if (warning == 1 && battery[i] >= 35){
                warning = 0;
                printf("경보 상태: OFF (%d)\n", warning);
            }else {
                printf("경보 상태: 유지 (%d)\n", warning);
            }
            

    }
    printf("\n[배터리 히스테리시스 경보 결과] 최종 경보 상태: %d\n", warning);
    break;
    
    
    default:
    printf("종료\n");
    break;

}
return 0; // main 함수 종료 시 return 0

}

// 함수 정의
long long sum_index_of_black(const int label[], int N){
    long long sum_index = 0;
    // long long index_avg = 0; // 이 변수는 불필요

    for(int i= 0; i< N; i++){
        // label[i]가 1일 때만 인덱스를 더함 (label[i]는 0 또는 1이므로)
        sum_index += (long long)i * label[i]; 
    }
    return sum_index;
}

double avg_index_of_black(long long sum_index, int black_count){
    if (black_count == 0) {
        return 0.0; // 0으로 나누는 오류 방지
    }
    // ⭐ sum_index를 double로 캐스팅하여 정확한 나눗셈 수행
    return (double)sum_index / black_count; 
}