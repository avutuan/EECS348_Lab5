#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Cmin(double sales[], int n) {
    double min = sales[0];
    for (int i = 1; i < n; i++) {
        if (sales[i] < min) {
            min = sales[i];
        }
    }
    return min;
}

double Cmax(double sales[], int n) {
    double max = sales[0];
    for (int i = 1; i < n; i++) {
        if (sales[i] > max) {
            max = sales [i];
        }
    }
    return max;
}

double Cavg(double sales[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sales[i];
    }
    return sum/n;
}

void report(double sales[], int n) {
    printf("\nMonthly sales report for 2022:\n");
    char *months[] = {"January", "February" , "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Month\t\tSales\n");
    for (int i = 0; i < n; i++) {
        if (strlen(months[i]) > 7) {
            printf("%s\t$%.2lf\n", months[i], sales[i]);
        } else {
            printf("%s\t\t$%.2lf\n", months[i], sales[i]);
        }
    }
}

void summary(double sales[], int n) {
    double min = Cmin(sales, n);
    double max = Cmax(sales, n);
    double avg = Cavg(sales, n);
    char *months[] = {"January", "February" , "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\nSales Summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", min, months[0]);
    printf("Maximum sales: $%.2lf (%s)\n", max, months[n-1]);
    printf("Average sales: $%.2lf\n", avg);
}

void movingAvg(double sales[], int n) {
    printf("\nSix-Month Moving Average Report:\n");
    char *months[] = {"January", "February" , "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i <= n - 6; i++) {
        double moving_avg = 0;
        for (int j = 0; j < 6; j++) {
            moving_avg += sales[i + j];
        }
        moving_avg /= 6;
        if ((strlen(months[i]) == 7) && (strlen(months[i+5]) <= 5)) {
            printf("%s\t\t- %s\t\t$%.2lf\n", months[i], months[i+5], moving_avg);
        } else if ((strlen(months[i]) > 7) && (strlen(months[i+5]) <= 5)) {
            printf("%s\t- %s\t\t$%.2lf\n", months[i], months[i+5], moving_avg);
        } else if (strlen(months[i]) > 7) {
            printf("%s\t- %s\t$%.2lf\n", months[i], months[i+5], moving_avg);
        } else {
            printf("%s\t\t- %s\t$%.2lf\n", months[i], months[i+5], moving_avg);
        }
    }
}

void sortedReport(double sales[], int n) {
    printf("\nSales Report (Highest to Lowest):\n");
    char *months[] = {"January", "February" , "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Month\t\tSales\n");
    int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }  
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sales[indices[i]] < sales[indices[j]]) {
                int temp = indices [i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }    
    }
    for (int i = n-1; i >= 0; i--) {
        if (strlen(months[i]) > 7) {
            printf("%s\t$%.2lf\n", months[i], sales[i]);
        } else {
            printf("%s\t\t$%.2lf\n", months[i], sales[i]);
        }
    }
}

int main() {
    int n = 12;
    double sales[n];
    FILE *input = fopen("Cproblem1in.txt","r");
    for (int i = 0; i < n; i++) {
        fscanf(input, "%lf", &sales[i]);
    }
    fclose(input);
    report(sales, n);
    summary(sales, n);
    movingAvg(sales, n);
    sortedReport(sales, n);
    return 0;
}