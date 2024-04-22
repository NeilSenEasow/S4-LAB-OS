#include<stdio.h>

void roundRobin(int n, int bt[], int at[], int quantum);

int main() {
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int burstTimes[n], arrivalTimes[n];
    
    printf("Enter burst times and arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTimes[i]);
    }
    
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    
    roundRobin(n, burstTimes, arrivalTimes, quantum);
    
    return 0;
}

void roundRobin(int n, int bt[], int at[], int quantum) {
    int wt[n], tat[n], ct[n], rem_bt[n];
    float total_wt = 0, total_tat = 0;
    
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    
    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - at[i];
                    if (wt[i] < 0)
                        wt[i] = 0;
                    rem_bt[i] = 0;
                    ct[i] = t;
                }
            }
        }
        if (done == 1)
            break;
    }
    
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], ct[i], wt[i], tat[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}