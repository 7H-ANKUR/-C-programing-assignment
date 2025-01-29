#include <stdio.h>

typedef struct {
    int runs;
    int isOut;
} Batsman;

int main() {
    Batsman batsmen[2] = {{0, 0}, {0, 0}};
    int striker = 0;
    int totalRuns = 0;
    int wickets = 0;
    int overs = 0;
    int balls = 0;
    int choice, runs;

    printf("Cricket Score Board\n");
    printf("-------------------\n");

    while(1) {
        // Display current score
        printf("\nCurrent Score: %d/%d\n", totalRuns, wickets);
        printf("Overs: %d.%d\n", overs, balls);
        printf("Batsman 1: %d %s\n", batsmen[0].runs, batsmen[0].isOut ? "(out)" : "");
        printf("Batsman 2: %d %s\n", batsmen[1].runs, batsmen[1].isOut ? "(out)" : "");

        // Display menu
        printf("\n1. Add runs\n2. Add wicket\n3. Add ball\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch(choice) {
            case 1:
                printf("Enter runs scored (0-6): ");
                scanf("%d", &runs);
                if (runs < 0 || runs > 6) {
                    printf("Invalid input! Runs should be between 0-6\n");
                    continue;
                }
                
                totalRuns += runs;
                batsmen[striker].runs += runs;
                
                // Swap striker for odd runs
                if (runs % 2 != 0) {
                    striker = 1 - striker;
                }
                
                balls++;
                break;

            case 2:
                if (wickets >= 10) {
                    printf("All out! Cannot add more wickets.\n");
                    continue;
                }
                
                wickets++;
                batsmen[striker].isOut = 1;
                
                if (wickets < 10) {
                    // Bring in new batsman
                    batsmen[striker].runs = 0;
                    batsmen[striker].isOut = 0;
                }
                
                balls++;
                break;

            case 3:
                balls++;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        // Update overs and balls
        if (balls >= 6) {
            overs++;
            balls = balls % 6;
        }

        // Check for all out
        if (wickets >= 10) {
            printf("\nAll out! Final Score: %d/%d\n", totalRuns, wickets);
            break;
        }
    }

    printf("\nFinal Score: %d/%d in %d.%d overs\n", totalRuns, wickets, overs, balls);
    return 0;
}
