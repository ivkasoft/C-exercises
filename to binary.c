#include <stdio.h>
#include <string.h>

//function coverts decimal to binary
int toBinary(int n){
    char arr[32];
    int m, index = 0;

    if (n == 0) {
        arr[index++] = '0';
    }
    while (n != 0) {
        m = n % 2;
        arr[index++] = m + '0';
        n = n / 2;
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    return 0;
}

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    toBinary(num);

    return 0;
}
