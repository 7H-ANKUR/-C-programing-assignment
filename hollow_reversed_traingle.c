#include<stdio.h>
int main()
{
    int i, j;
    int n = 5; // Height of the triangle
    
    for (i = n; i >= 1; i--)  // Loop to control the rows (starts from n and decrements)
    {
        for (j = 1; j <= i; j++)  // Loop to control the columns
        {
            // Print '*' for first or last column, or for the first or last row
            if (i == n || j == 1 || j == i)
                printf("* ");
            else
                printf(" ");  // Print spaces inside the triangle
        }
        printf("\n");  // Move to the next line after each row
    }

    return 0;
}
