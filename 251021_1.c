#include <stdio.h>
#include <string.h>
#include <math.h>

//M_PI가 정의되지 않은 경우를 대비하여 직접 정의합니다.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//M_PI 정의를 활성화하기 위해 math.h 위에 이 매크로를 정의합니다.
#define _USE_MATH_DEFINES


double clip(double val, double min_val, double max_val) {
    if (val < min_val) return min_val;
    if (val > max_val) return max_val;
    return val;
}


int main(void)
{
    double m, Tm, Nm, G, n, r, c, SF;
    double Ttot, Favail, Fneed;
    
    // sin, tan은 함수 이름이므로 변수 이름으로 사용하면 안 됩니다.
    // 변수 이름을 `sin_val` 등으로 변경했습니다.
    double sin_val, tan_val, grade; 
    
    const double g = 9.81;

    double theta, theta_deg;
    // M_PI 사용 가능 (위에 _USE_MATH_DEFINES 정의)
    theta = M_PI ; 

    printf("총 질량 m[kg]:");     if (scanf("%lf", &m) != 1) return 1;
    printf("모터 정격토크 Tm [N.m]:");     if (scanf("%lf", &Tm) != 1) return 1;
    printf("구동 모터 수 Nm  [개]:");     if (scanf("%lf", &Nm) != 1) return 1;
    printf("감속 비 G :");     if (scanf("%lf", &G) != 1) return 1;
    printf("구동 효율 n [0~1]:");     if (scanf("%lf", &n) != 1) return 1;
    printf("바퀴 반지름 r [m]:");     if (scanf("%lf", &r) != 1) return 1;
    printf("구름 계수 c [ex)0.015~0.03]:");     if (scanf("%lf", &c) != 1) return 1;
    printf("안전계수 SF [>=1]:");     if (scanf("%lf", &SF) != 1) return 1;

    Ttot = Nm * Tm * G * n;
    Favail = Ttot / r;
    Fneed = m * g;
    
    // sin(theta) = ... 와 같이 함수 호출 결과를 대입할 수 없습니다.
    // 세타(theta)를 계산하는 수식을 이용해 새로운 세타를 찾는 것으로 보입니다.
    // sin(theta) = (필요구동력 - 구름저항력) / 중력경사력 과 같은 물리적 공식으로 가정하고 계산합니다.
    
    double sin_theta_arg = (Favail/SF - (c * m * g)) / (m * g);
    
    // clip 함수를 사용해 sin(theta)의 값이 [-1, 1] 범위에 있도록 보장합니다.
    // 0과 1 사이로 제한하는 clip 함수를 사용하셨으므로 그대로 반영합니다.
    sin_val = clip(sin_theta_arg, 0.0, 1.0); 

    // sin_val을 이용해서 실제 theta 값을 역함수로 계산합니다.
    // asinh()가 아니라 arcsin(아크사인) 함수인 asin()을 사용해야 합니다.
    theta = asin(sin_val); 

    //라디안 값을 도(Degree)로 변환( 180도 = ㅠ)
    theta_deg = theta * (180.0 / M_PI);

    // tan(theta) 값을 계산합니다.
    tan_val = tan(theta); 
    
    // 등판율(Gradeability) = tan(theta) * 100 (%)
    grade = tan_val * 100;

    //출력결과
    printf("-----------------실행결과-----------------\n");
    printf("Favail                       : %.1f N\n", Favail);
    //세타를 출력하려면 `theta` 변수를 출력해야 합니다.
    printf("세타 (라디안)              : %.4f rad\n", theta); 
    printf("세타 (도)              : %.4f 도\n", theta_deg); 
    printf("등판율 (Gradeability)      : %.1f %%\n", grade); 
    
    return 0;
}