#include<stdio.h>
int main()
{
    int i, j;
    int n = 5; 
    
    for (i = 1; i<=n; i++)  
    {
        for (j = 1; j <= i; j++)  
        {
           
            if (i == n || j == 1 || j == i)
                printf("* ");
            else
                printf("  ");  
        }
        printf("\n");  
    }

    return 0;
}
