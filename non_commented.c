#include <stdio.h>
#include <string.h>

// Define a structure for a batsman
typedef struct {
    int runs;
    int isOut;
    char name[20];
    char dismissal[20]; // To store how the batsman got out
} Batsman;

// Define a structure for a bowler
typedef struct {
    char name[20];
    int oversBowled;
} Bowler;

int main() {
    // Initialize an array of batsmen with initial values
    Batsman batsmen[11] = {
        {0, 0, "", ""}, {0, 0, "", ""}, {0, 0, "", ""},
        {0, 0, "", ""}, {0, 0, "", ""}, {0, 0, "", ""},
        {0, 0, "", ""}, {0, 0, "", ""}, {0, 0, "", ""},
        {0, 0, "", ""}, {0, 0, "", ""}
    };

    // Initialize a bowler
    Bowler currentBowler = {"", 0};

    int striker = 0;     // Index of the current striker
    int nonStriker = 1;  // Index of the current non-striker
    int totalRuns = 0;   // Total runs scored
    int wickets = 0;     // Total wickets fallen
    int overs = 0;       // Total overs bowled
    int balls = 0;       // Total balls bowled in the current over
    int nextBatsman = 2; // Index of the next batsman to come
    int maxOvers;        // Maximum number of overs in the innings (to be entered by user)
    int isFreeHit = 0;   // Flag to indicate if the next ball is a free hit

    // Prompt the user to enter the maximum number of overs
    printf("Enter the maximum number of overs: ");
    scanf("%d", &maxOvers);

    // Prompt the user to enter the names of the first two batsmen
    printf("Enter the name of the first batsman: ");
    scanf("%s", batsmen[0].name);
    printf("Enter the name of the second batsman: ");
    scanf("%s", batsmen[1].name);

    // Prompt the user to enter the name of the bowler
    printf("Enter the name of the bowler: ");
    scanf("%s", currentBowler.name);

    // Display the header for the scoreboard
    printf("                                                                                                                          \n ");
    printf("                                                                                                                           \n");

    printf("                                                   -------------------\n");

    printf("___________________________________________________Cricket Score Board_________________________________________________________\n");
    printf("                                                   -------------------\n");

    while(1) {
        // Display current score, overs, and bowler
        printf("\nCurrent Score: %d/%d", totalRuns, wickets);
        printf("\tOvers: %d.%d", overs, balls);
        printf("\tBowler: %s (%d overs)\n", currentBowler.name, currentBowler.oversBowled);
        
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
                
                // Check if it's a free hit (only run-out is allowed)
                if (isFreeHit) {
                    printf("It's a free hit! Only run-out is allowed.\n");
                    printf("Was it a run-out? (1 for Yes, 0 for No): ");
                    int isRunOut;
                    scanf("%d", &isRunOut);
                    
                    if (!isRunOut) {
                        printf("No wicket can be taken on a free hit except run-out.\n");
                        break;
                    }
                }
                
                // Ask how the batsman got out
                printf("How did the batsman get out?\n");
                printf("1. LBW\n2. Catch Out\n3. Hit Wicket\n4. Stumped\n5. Run Out\n");
                printf("Enter your choice: ");
                int dismissalChoice;
                scanf("%d", &dismissalChoice);
                
                // Set the dismissal reason based on user input
                switch(dismissalChoice) {
                    case 1:
                        strcpy(batsmen[striker].dismissal, "LBW");
                        break;
                    case 2:
                        strcpy(batsmen[striker].dismissal, "Catch Out");
                        break;
                    case 3:
                        strcpy(batsmen[striker].dismissal, "Hit Wicket");
                        break;
                    case 4:
                        strcpy(batsmen[striker].dismissal, "Stumped");
                        break;
                    case 5:
                        strcpy(batsmen[striker].dismissal, "Run Out");
                        break;
                    default:
                        printf("Invalid choice! Setting dismissal as 'Unknown'\n");
                        strcpy(batsmen[striker].dismissal, "Unknown");
                        break;
                }
                
                batsmen[striker].isOut = 1;
                wickets++;
                
                if (nextBatsman < 11) {
                    printf("Enter the name of the new batsman: ");
                    scanf("%s", batsmen[nextBatsman].name);
                    striker = nextBatsman;
                    nextBatsman++;
                }
                
                balls++;
                break;
                
            case 3:
                // Add a ball to the current over
                printf("What type of ball is it?\n");
                printf("1. Dot Ball\n2. Wide Ball\n3. No Ball\n");
                printf("Enter your choice: ");
                int ballType;
                scanf("%d", &ballType);
                
                switch(ballType) {
                    case 1:
                        // Dot Ball: No runs, ball is counted
                        balls++;
                        break;
                    case 2:
                        // Wide Ball: 1 run added to total, ball is not counted
                        totalRuns += 1;
                        break;
                    case 3:
                        // No Ball: 1 run added to total, ball is not counted, next ball is a free hit
                        totalRuns += 1;
                        isFreeHit = 1;
                        break;
                    default:
                        printf("Invalid choice! Ball not counted.\n");
                        break;
                }
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
            currentBowler.oversBowled++;

            // Swap striker and non-striker at over completion
            int temp = striker;
            striker = nonStriker;
            nonStriker = temp;

            // Prompt the user to enter the name of the new bowler
            printf("Enter the name of the new bowler: ");
            scanf("%s", currentBowler.name);

            // Reset free hit flag at the end of the over
            isFreeHit = 0;
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
        printf("%s - %d %s %s%s%s\n", 
               batsmen[i].name,
               batsmen[i].runs,
               batsmen[i].isOut ? "(out)" : "(not out)",
               batsmen[i].isOut ? batsmen[i].dismissal : "",
               (i == striker) ? "[STRIKER] " : "",
               (i == nonStriker) ? "[NON-STRIKER]" : "");
    }

    // Display bowler's performance
    printf("\nBowler: %s bowled %d overs\n", currentBowler.name, currentBowler.oversBowled);

    return 0;
}
