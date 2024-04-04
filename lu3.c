#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //1: Enter 3 numbears and swap them

    /*int a,b,c,k,arr[3];
    printf("Enter 3 numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    for(int i=0;i<3;i++){
        for(int j=0;j<3-i-1;j++){
            if (arr[j]>arr[j+1]){
                k=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=k;
            }
        }
    }
    for(int i=0;i<3;i++){
        printf("%d",arr[i]);
    }*/


    //2: Enter numbers until 0 and print the avg,min,max and (max-min)
    /*
    int n,min=1000,max=0,sum=0,num=0;
    do{
        scanf("%d",&n);
        num++;
        sum+=n;
        if(n!=0){
            if(n<min){
                min=n;
            }
        }
        if(n>max){
            max=n;
        }
    }while(n!=0);
    printf("Average: %f\n",(float)sum/(num-1));
    printf("Min: %d\n",min);
    printf("Max: %d\n",max);
    printf("max-min: %d\n",max-min);*/


    //3: Enter a past date and find out which day of the week it was
    
    int d, m, y;
    bool leap = false;

    printf("Enter day: ");
    scanf("%d", &d);
    printf("Enter month: ");
    scanf("%d", &m);
    printf("Enter year: ");
    scanf("%d", &y);
    //current date is 14.03.2024. The current date can be entered with variables
    if (d > 14 && m >= 3 && y >= 2024) {
        printf("Invalid! It needs to be a past date!\n");
    }

    // Checking if the day is valid according to the month
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31) {
            printf("Invalid! Day needs to be less than 31!\n");
        }
    } else if (m == 4 || m== 6 || m == 9 || m == 11) {
        if (d > 30) {
            printf("Invalid! Day needs to be less than 30!\n");
        }
    }

    // Checking if it is a leap year and handling number of days in February
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
        leap = true;
        printf("%d is a leap year.\n", y);
        if (m == 2 && d > 29) {
            printf("Invalid! Day needs to be less than 29!\n");
        }
    } else {
        printf("%d is not a leap year.\n", y);
        if (m == 2 && d > 28) {
            printf("Invalid! Day needs to be less than 28!\n");

        }
    }

    // Calculating the day of the week
    int monthCodes[] = {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    int monthCode = monthCodes[m - 1];
    if (leap && (m == 1 || m == 2)) {
        monthCode--;
    }

    int centuryCode;
    if (y >= 2000 && y <= 2099) {
        centuryCode = 6;
    } else if (y >= 2100 && y <= 2199) {
        centuryCode = 4;
    }

    int yearCode = (y % 100) / 4;
    int total = d + monthCode + yearCode + (y % 100) + centuryCode;
    int dayOfWeek = total % 7;

    // Printing the day of the week
    switch (dayOfWeek) {
        case 0: printf("Saturday\n"); break;
        case 1: printf("Sunday\n"); break;
        case 2: printf("Monday\n"); break;
        case 3: printf("Tuesday\n"); break;
        case 4: printf("Wednesday\n"); break;
        case 5: printf("Thursday\n"); break;
        case 6: printf("Friday\n"); break;
    }

    return 0;
}


