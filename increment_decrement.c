#include<stdio.h>
int main(){
    int a;

    printf("enter  number :");
    scanf("%d",&a);

    // increment
    printf("value of a %d \n :" ,++a); //prefix
    printf("value of a %d \n :", a++); //postfix
    printf("value of a AFTER POSTFIX OPERATION %d \n: " ,a);

    // decrement
    printf("value of a :%d \n " ,--a); //prefix
    printf("value of a : %d \n " ,a--);//postfix
    printf("value of a AFTER POSTFIX OPERATION %d \n :" ,a);
    return 0;



}