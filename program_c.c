#include <stdio.h>

int main() {
    printf("Hello world!\n");
    //print the values of the array accessed by pointer
    int x[]={2,6,4,1};
    int* p=x;
    for(int i=0;i<4;i++){
        printf("%d\n",*(p+i));
    }
    
    return 0;
}