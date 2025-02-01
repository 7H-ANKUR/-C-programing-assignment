#include <stdio.h>
#include <string.h>

// Define a structure for a batsman
typedef struct {
    int runs;
    int isOut;
    char name[20];
} Batsman;

int main() {
    // Initialize an array of batsmen with initial values
    Batsman batsmen[11] = {
        {0, 0, "Batsman 1"}, {0, 0, "Batsman 2"}, {0, 0, "Batsman 3"},
        {0, 0, "Batsman 4"}, {0, 0, "Batsman 5"}, {0, 0, "Batsman 6"},
        {0, 0, "Batsman 7"}, {0, 0, "Batsman 8"}, {0, 0, "Batsman 9"},
        {0, 0, "Batsman 10"}, {0, 0, "Batsman 11"}
    };
    
    int striker = 0;     // Index of the current striker
    int nonStriker = 1;  // Index of the current non-striker
    int totalRuns = 0;   // Total runs scored
    int wickets = 0;     // Total wickets fallen
    int overs = 0;       // Total overs bowled
    int balls = 0;       // Total balls bowled in the current over
    int nextBatsman = 2; // Index of the next batsman to come
    int maxOvers = 20;   // Maximum number of overs in the innings

    // Display the header for the scoreboard
    printf("                                                                                                                          \n ");
    printf("                                                                                                                           \n");

    printf("                                                   -------------------\n");

    printf("___________________________________________________Cricket Score Board_________________________________________________________\n");
    printf("                                                   -------------------\n");

    while(1) {
        // Display current score and overs
        printf("\nCurrent Score: %d/%d", totalRuns, wickets);
        printf("\tOvers: %d.%d\n", overs, balls);
        
        // Display striker status with marker
        printf("\nStriker:    %s - %d %s %s", 
               batsmen[striker].name, 
               batsmen[striker].runs,
               batsmen[striker].isOut ? "(out)" : "",
               "[STRIKER]");
        
        // Display non-striker status
        printf("\nNon-Striker: %s - %d %s\n", 
               batsmen[nonStriker].name, 
               batsmen[nonStriker].runs,
               batsmen[nonStriker].isOut ? "(out)" : "");

        // Display options for the user
        printf("\n1. Add runs\n2. Add wicket\n3. Add ball\n4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        // Exit the loop if user chooses to exit
        if (choice == 4) break;

        switch(choice) {
            case 1: {
                // Add runs to the striker's score and total runs
                int runs;
                printf("Enter runs scored (0-6): ");
                scanf("%d", &runs);
                
                if (runs < 0 || runs > 6) {
                    printf("Invalid runs! Must be 0-6\n");
                    break;
                }
                
                totalRuns += runs;
                batsmen[striker].runs += runs;
                
                // Swap positions for odd runs
                if (runs % 2 != 0) {
                    int temp = striker;
                    striker = nonStriker;
                    nonStriker = temp;
                }
                
                balls++;
                break;
            }
            case 2:
                // Add a wicket and update the striker
                if (wickets >= 10) {
                    printf("All out! No more wickets.\n");
                    break;
                }
                
                batsmen[striker].isOut = 1;
                wickets++;
                
                if (nextBatsman < 11) {
                    striker = nextBatsman;
                    nextBatsman++;
                }
                
                balls++;
                break;
                
            case 3:
                // Add a ball to the current over
                balls++;
                break;
                
            default:
                // Handle invalid choices
                printf("Invalid choice!\n");
                break;
        }

        // Update overs and rotate strike if needed
        if (balls >= 6) {
            overs++;
            balls = 0;
            // Swap striker and non-striker at over completion
            int temp = striker;
            striker = nonStriker;
            nonStriker = temp;
        }

        // Check if innings is over
        if (wickets >= 10 || overs >= maxOvers) {
            printf("\nInnings Over!\n");
            break;
        }
    }

    // Display final scorecard
    printf("\nFinal Scorecard:\n");
    printf("Total: %d/%d in %d.%d overs\n", totalRuns, wickets, overs, balls);
    printf("\nBatsmen:\n");
    for (int i = 0; i < 11; i++) {
        printf("%s - %d %s %s%s\n", 
               batsmen[i].name,
               batsmen[i].runs,
               batsmen[i].isOut ? "(out)" : "(not out)",
               (i == striker) ? "[STRIKER] " : "",
               (i == nonStriker) ? "[NON-STRIKER]" : "");
    }

    return 0;
}
