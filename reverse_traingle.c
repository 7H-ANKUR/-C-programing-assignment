#include <stdio.h>

int main() {
    int i, j, k;
    for (i = 1; i <= 5; i++) {
        // Print leading spaces
        for (j = i; j < 5; j++) 
        {
            printf("  ");
        }
        // Print stars
        for (k = 1; k <= i; k++)
      {
            printf("* ");
        }
        // Move to the next line
        printf("\n");
    }
    return 0;
}

