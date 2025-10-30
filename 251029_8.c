#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    FILE *fp1;

    char line[255]; // 파일을 한 줄씩 읽어 저장할 버퍼 한 줄의 최대 길이를 1024바이트로 정의
    const char *search = "Active"; // 검색할 문자열
    int count = 0; // "Active" 문자열이 발견된 총 횟수
    int line_number =0;


    //파일 열기
    fp = fopen("battery.txt", "r");
    fp1 =fopen("battery_result.txt", "w");

    if (fp == NULL) {
        printf("오류: 'battery.txt' 파일이 열리지 않았습니다. 파일 경로를 확인해주세요.\n");
        return 1;
    } 

    printf("파일이 성공적으로 열렸습니다.\n");
        

    // 파일 내용 검색 및 카운트
    // fgets 함수를 사용하여 파일의 끝(NULL)에 도달할 때까지 한 줄씩 읽습니다.
    while (fgets(line, sizeof(line), fp) != NULL) {
        // strstr 함수를 사용하여 현재 줄(line)에 검색어(search_term, "Active")가 포함되어 있는지 확인
        line_number++;


        if (strstr(line, search) != NULL) {
            count++; // 발견되면 카운트 증가

            // char *a;
            // a =fgets(line, sizeof(line), fp);

            printf("[%d]발견된 줄: %s", line_number,line);  
            fprintf(fp1,"[%d]발견된 줄: %s", line_number,line);  
            //fprintf(fp1,"[%d]발견된 STATE: %s", line_number+4,a+4);  
        }
            // fprintf(fp1,"[%d]발견된 STATE: %s", line_number+4,search+4);  
    }
    //read 파일 닫기
    fclose(fp);

    if (fp1 == NULL) {
        printf("오류: 'battery_result.txt' 파일이 열리지 않았습니다. 파일 경로를 확인해주세요.\n");
        return 1;
    } 
    //결과 출력
    printf("\n======================================\n");
    printf("파일에서 \"%s\" 문자열이 총 %d번 발견되었습니다.\n", search, count);
    printf("======================================\n");
    fprintf(fp1,"\n======================================\n");
    fprintf(fp1,"파일에서 \"%s\" 문자열이 총 %d번 발견되었습니다.\n", search, count);
    fprintf(fp1,"======================================\n");
    
    //쓰기 파일 닫기
    fclose(fp1);

    return 0;
}
