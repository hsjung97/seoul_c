#include <stdio.h>

void fruit(int count, int next_sum);

int main(void)
{
    fruit(1,0);

    return 0;
}

void fruit(int count, int next_sum)
{

    
    int sum = 0;
    sum += count;
    next_sum += sum;


    if(count==10) {
        printf("총합: %d",next_sum);
        return;
    }
    fruit(count+1, next_sum);
}