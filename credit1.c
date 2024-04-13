#include <stdio.h>
#include <math.h>

typedef struct {
    int time;
    float percent;
    float amount;
} Account;

void input(Account accounts[], int num) {
    for (int i = 0; i < num; i++) {
        do {
            printf("Enter the deposit time for account %d:\n", i + 1);
            scanf("%d", &accounts[i].time);
            if (accounts[i].time < 0 || accounts[i].time > 10) {
                printf("Invalid input!\n");
            }
        } while (accounts[i].time < 0 || accounts[i].time > 10);

        printf("Enter percent for account %d:\n", i + 1);
        scanf("%f", &accounts[i].percent);
        accounts[i].percent /= 100;

        printf("Enter amount for account %d:\n", i + 1);
        scanf("%f", &accounts[i].amount);
    }
}

void printCalc(Account accounts[], int num_accounts) {
    float simple, cap;
    for (int i = 0; i < num_accounts; i++) {
        simple = accounts[i].time * accounts[i].percent * accounts[i].amount;
        cap = accounts[i].amount * pow(1 + accounts[i].percent, accounts[i].time);
        printf("Account %d:\n", i + 1);
        printf("Nr. period: %d\nSimple: %f\nCapitalized: %f\nDeposit/simple: %f\n\n", accounts[i].time, 
        simple, cap, accounts[i].amount / simple);
    }
}

int main() {
    int num;
    printf("Enter the number of accounts:\n");
    scanf("%d", &num);

    Account accounts[num];

    input(accounts, num);
    printCalc(accounts, num);

    return 0;
}
