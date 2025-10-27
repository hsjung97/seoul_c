#include <stdio.h>
#include <string.h>

int main(void)
{
    int a;
    int b,c;
    unsigned int ac;
    char fruit[20] = "strawberry";
    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    income = 455;
    //tax_rate = 1.2;
    tax = income * tax_rate;
    printf("세금은 %.lf입니다.\n", tax);




    ac = 123123313;

    a=1;


    printf("%d\n", a);
    printf("Be happy\n");
    printf("My friend\n");
    
    
    printf("%d\n", ac);
    ac = -1;
    //printf("%u\n", ac);
    printf("%d\n", ac);

    printf("딸기: %s\n", fruit);
    strcpy(fruit, "banana");
    printf("%s\n", fruit);


    char grade;
    char name[20];

    printf("학점 입력 : ");
    scanf("%c", &grade);
    printf("이름 입력:");
    scanf("%s", name);
    printf("%s의 학점은 %c입니다.\n", name, grade);









    return 0;



}