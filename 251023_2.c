#include <stdio.h>

//#define N 5

float adc_to_voltage(int adc_voltage, float Vref);
float voltage_to_distance(float voltage, float k);
float voltage_to_adc(float vol_i, float Vref);

float adc_to_voltage(int adc_voltage, float Vref){
    // 1023.0f를 사용하여 부동 소수점 나눗셈을 강제합니다.
    float voltage = ((float)adc_voltage * 1023.0f) / Vref; 
    return voltage;
}

float voltage_to_distance(float voltage, float k){
    //0으로 나누는 것을 방지
    if(voltage ==0.0f){
        return 0.0f;
    }
    
    float distance = k / voltage;
    return distance;
}

float voltage_to_adc(float vol_i, float Vref){
    if(Vref == 0.0f) {
        return 0.0f; 
    }

    float adc_o = (float)(vol_i *1023.0f)/ Vref; 
    return adc_o;
}


int main(void){

    int N;
    float k=0;
    float Vref=0;
    //int adc[N];

    printf("N입력: ");
    scanf("%d", &N);

    int adc[N];
    float adc_v[N];
    float distance_v[N];
    float adc_o[N];


    printf("Vref입력 : ");
    scanf("%f", &Vref);

    printf("거리 변환 상수(k)입력 : ");
    scanf("%f", &k);


    for(int i = 0; i<N; i++){
        
        printf("adc입력: ");
        if(scanf("%d", &adc[i]) != 1){
            printf("잘못된 입력입니다.\n");
        return 1;
        }
        
        adc_v[i] = adc_to_voltage(adc[i], Vref);
        distance_v[i]=voltage_to_distance(adc_v[i],k);
        
        //전압을 이용해서 adc값을 구한다.
        adc_o[i] = voltage_to_adc(adc_v[i], Vref);




        printf("========실행결과=======\n");
        printf("ADC = %d\n", adc[i]);
        printf("전압 = %f\n", adc_v[i]);
        printf("거리 = %f\n", distance_v[i]);
        printf("전압을 이용해서 구한 adc값 = %f\n", adc_o[i]);
    }
}