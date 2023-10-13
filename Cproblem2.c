#include <stdio.h>

void combos(int score) {
    int td2, td1, td0, fgs, s;
    for (td2 = 0; td2 <= score / 8; td2++) {
        for (td1 = 0; td1 <= score / 7; td1++) {
            for (td0 = 0; td0 <= score / 6; td0++) {
                for (fgs = 0; fgs <= score / 3; fgs++) {
                    for (s = 0; s <= score / 2; s++) {
                        if ((8 * td2 + 7 * td1 + 6 * td0 + 3 * fgs + 2 * s) == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD + 1pt, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td0, td1, fgs, s);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter 0 or 1 to STOP\n");

    while (1) {
        int score;
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        printf("Possible combinations of scoring plays:\n");
        combos(score);
    }

    return 0;
}
