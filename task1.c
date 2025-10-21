#include <stdio.h>//

int main(){
    while (1){
        int score;
        int combos_found = 0;

        printf("Enter the NFL score (Enter 1 to stop): ");
        while (scanf("%d", &score) != 1) {
            while (getchar() != '\n'); 
            
            printf("Invalid input. Please enter a number: ");
        }


        if (score == 1){
            printf("Exiting the program.\n");
            break;
        }

        if (score < 0) {
            printf("Invalid input. Score must be a positive number.\n\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt = td_2pt + 1){
            for (int td_fg= 0; td_fg * 7 <= score; td_fg = td_fg +1) {
                for (int td = 0; td * 6 <= score; td = td + 1) {
                    for (int fg = 0; fg * 3 <= score; fg = fg + 1){
                        for (int safety = 0; safety * 2 <= score; safety = safety + 1) {
                            int current_total = (td_2pt * 8) + (td_fg * 7) + (td * 6) + (fg * 3) + (safety * 2);
                            if (current_total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                       td_2pt, td_fg, td, fg, safety);
                                combos_found = 1;
                            }
                        }    

                    }
                }
            }
        }
        if (combos_found == 0) {
            printf("No combinations found for the score %d.\n", score);
        }
        printf("\n");
    }
}