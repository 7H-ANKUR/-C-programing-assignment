#include<stdio.h>
int main(){
    float c,f;

    printf("enter temperature in celsius:");
    scanf("%f",&c);

    f=(9.0/5.0*c)+32;

    printf("the temperature in fahreheit :%f",f);
    return 0;
}