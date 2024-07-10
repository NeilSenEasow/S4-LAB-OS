#include <stdio.h>

void sortProcessesByArrival(int num, int p[], int a[], int b[]) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap arrival times
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                
                // Swap burst times
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                
                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int p[100], a[100], b[100], c[100], t[100], w[100], i, num;

    printf("Enter number of processes: ");
    scanf("%d", &num);
   
    // Processes
    printf("Enter process IDs:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &p[i]);
    }
 
    // Arrival Times
    printf("Enter Arrival Times:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }

    // Burst Times
    printf("Enter Burst Times:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &b[i]);
    }

    // Sort processes by arrival time
    sortProcessesByArrival(num, p, a, b);

    // Calculate Completion Time
    c[0] = a[0] + b[0];  // Completion time for the first process
    for (i = 1; i < num; i++) {
        if (a[i] > c[i - 1]) {
            c[i] = a[i] + b[i];  // Process arrives after the previous process has completed
        } else {
            c[i] = c[i - 1] + b[i];  // Process arrives before the previous process has completed
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < num; i++) {
        t[i] = c[i] - a[i];  // Turnaround time
        w[i] = t[i] - b[i];  // Waiting time
    }

    // Print the results
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWaiting Time\n");
    for (i = 0; i < num; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n", p[i], a[i], b[i], c[i], t[i], w[i]);
    }

    return 0;
}