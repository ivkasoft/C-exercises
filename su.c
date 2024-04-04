#include <stdio.h>
int main(){
    //1: Find the longest seqence and its lenght
    /*
    int num;
    printf("Enter size of array: ");
    scanf("%d",&num);
    int nums[num];
    printf("Enter elements: ");
    for(int i=0;i<num;i++){
        scanf("%d",&nums[i]);
    }
    int count=0,countall=0,elem;
    for(int i=0;i<num-1;i++){
        if(nums[i]==nums[i+1]){
            count++;
            if(count>=countall){
                countall=count;
                elem=nums[i];
            }
        }
        else{
            count=0;
        }
    }
    printf("The longest seqence: ");
    for(int i=0;i<countall+1;i++){
        printf("%d ",elem);
    }
    printf("\n");
    printf("Lenght: %d",countall+1);*/

    //2 a1>a2<a3>a4< ...
    /*
    int num;
    int flagEven=1,flagOdd=1;
    printf("Enter size of array: ");
    scanf("%d",&num);
    int nums[num];
    printf("Enter elements: ");
    for(int i=0;i<num;i++){
        scanf("%d",&nums[i]);
    }
    //even
    for (int i=0;i<num-1;i=i+2){
        if(nums[i]<nums[i+1]){
            //
        }
        else{
            flagEven=0;
            break;
        }
    }
    //odd
    for (int i=1;i<num-1;i=i+2){
        if(nums[i]>nums[i+1]){
            //
        }
        else{
            flagOdd=0;
            break;
        }
    }
    if(flagEven==1&&flagOdd==1){
        printf("All conditions are met!");
    }
    else{
        printf("Conditions are NOT met!");
    }*/

    //3: "1,2,3,4,5" => "5,4,3,2,1"
    /*
    int num;
    int flagEven=1,flagOdd=1;
    printf("Enter size of array: ");
    scanf("%d",&num);
    int nums[num];
    printf("Enter elements: ");
    for(int i=0;i<num;i++){
        scanf("%d",&nums[i]);
    }
    int swap,start=0,end=num-1;
    while (start < end) { 
        swap = nums[start]; 
        nums[start] = nums[end]; 
        nums[end] = swap; 
        start++; 
        end--;
    }
    for(int i=0;i<num;i++){
        printf("%d",nums[i]);
    }*/


    //4: Shift array with entered num of possitions
    int num,k,temp,newId;
    printf("Enter size of array: ");
    scanf("%d",&num);
    int nums[num];
    printf("Enter elements: ");
    for(int i=0;i<num;i++){
        scanf("%d",&nums[i]);
    }
    printf("Enter number of possitions: ");
    scanf("%d", &k);

    k =k%num; // Ensure k is within array bounds
    for(int i = 0; i < num; i++) {
        // Calculate the new index after shifting
        newId = (i + num - k) % num;

        // Swap the elements
        temp = nums[i];
        nums[i] = nums[newId];
        nums[newId] = temp;
    }
     printf("Swifted array: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", nums[i]);
    }
    

    //5 Printing the element of an array by an entered possition
    /*
    int num,elem,swap;
    printf("Enter size of array: ");
    scanf("%d",&num);
    int nums[num];
    printf("Enter elements: ");
    for(int i=0;i<num;i++){
        scanf("%d",&nums[i]);
    }
    printf("Enter position: ");
    scanf("%d",&elem);
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=swap;
            }
        }
    }
    printf("The element is: %d",nums[num-elem]);*/



    //6: Find the longest subsequence in an input
    /*
    int num,maxDec=1,maxInc=1;
    printf("Enter size of array: ");
    scanf("%d",&num);
    int nums[num];
    printf("Enter elements: ");
    for(int i=0;i<num;i++){
        scanf("%d",&nums[i]);
    }
    //length of the longest increasing subsequence
    for (int i = 0; i < num; i++) {
        int len = 1;
        for (int j = i + 1; j < num; j++) {
            if (nums[j] > nums[j - 1]) len++;
            else break;
        }
        if (len > maxInc)
            maxInc = len;
    }
    
    //length of the longest decreasing subsequence
    for (int i = 0; i < num; i++) {
        int len = 1;
        for (int j = i + 1; j < num; j++) {
            if (nums[j] < nums[j - 1])len++;
            else break;
        }
        if (len > maxDec) maxDec = len;
    }
    if (maxInc > maxDec){
        printf("length of the longest increasing subsequence: %d\n", maxInc);
    }
    else{
        printf("length of the longest decreasing subsequence: %d\n", maxDec);
    }*/

    return 0;
}