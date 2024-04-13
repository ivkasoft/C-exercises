#include <stdio.h>
#include <math.h>

void input(int *time, float *percent, float *amount) {
    do{
        printf("Enter the deposit time:\n");
        scanf("%d",time);
        if (*time<0 || *time>10) {
            printf("Invalid input!\n");
        }
    }while(*time<0 || *time>10);

    printf("Enter percent:\n");
    scanf("%f",percent);
    *percent/=100;

    printf("Enter amount:\n");
    scanf("%f",amount);
}

void printCalc(int time, float percent, float amount) {
    float simple, cap;
    simple=time*percent*amount;
    cap=amount*pow(1+percent, time);
    printf("Nr. period: %d\nSimple: %f\nCapitalized: %f\nDeposit/simple: %f", time,simple,cap,(float)amount/simple);
}

int main() {
    int time;
    float percent, amount;

    input(&time, &percent, &amount);
    printCalc(time, percent, amount);

    return 0;
}