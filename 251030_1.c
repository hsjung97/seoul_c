#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;

    int sel;

    char line[255];

    //case 1 
    const char *time = "-08:";
    //case 2 
    const char *ipv6 = "IPv6";
    //case 3 
    const char *ip = "fe80:0000:0000:0000:020c:29ff:feb7:6481";
    //case 4 
    const char *iptime = "-08:";
    const char *ip123 = "fe80:0000:0000:0000:020c:29ff:feb7:6481";

    int line_number, count;

    fp = fopen("fast.log","r");

    if(fp == NULL){
        printf("오류: 'fast.log'파일이 열리지 않았습니다.\n");
        return 1;
    }
    printf("파일이 성공적으로 열렸습니다.\n");

    printf("mode선택(01:특정시간대 ,02:IPv6, 03:특정ip ,04: 특정시간대에 특정ip): ");
    if (scanf("%d",&sel) != 1)return 1;



    switch(sel){
        case 1:
            while(fgets(line, sizeof(line), fp) != NULL){
                line_number++;
            if(strstr(line,time)!= NULL){
                count++;
            }
        }

        case 2:
            while(fgets(line, sizeof(line), fp) != NULL){
                line_number++;
            if(strstr(line,ipv6)!= NULL){
                count++;
            }    
        }

        case 3:
            while(fgets(line, sizeof(line), fp) != NULL){
                line_number++;
            if(strstr(line,ip)!= NULL){
                count++;
            }    
        }

        case 4:
            while(fgets(line, sizeof(line), fp) != NULL){
                line_number++;
            if((strstr(line,ip123)&& strstr(line,iptime))!= NULL){
                count++;
            }    
        }


        if(sel ==1 ){
            printf("[%s**:**]시간대에 보낸 ping 횟수: %d\n", time+1, count);
        } else if(sel == 2){
            printf("[%s] IPv6로 받은 ping 횟수: %d\n", ipv6, count);
        } else if(sel == 3){
            printf("[%s] 특정ip가 보낸 ping 횟수: %d\n", ip, count);
        } else if(sel == 4){
            printf("시간대: [%s**:**][%s] 특정시간대에서 특정 ip가 보낸 ping 횟수: %d\n", iptime+1, ip123, count);
        } 
    }
    fclose(fp);

    return 0;
}