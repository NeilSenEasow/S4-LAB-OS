#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

void priorityScheduling(int n, int bt[], int at[], int priority[]);

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of processes.\n");
        return 1;
    }
    
    int *burstTimes, *arrivalTimes, *priorities;
    burstTimes = (int *)malloc(n * sizeof(int));
    arrivalTimes = (int *)malloc(n * sizeof(int));
    priorities = (int *)malloc(n * sizeof(int));
    
    if (burstTimes == NULL || arrivalTimes == NULL || priorities == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter burst times, arrival times, and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst time: ");
        if (scanf("%d", &burstTimes[i]) != 1 || burstTimes[i] <= 0) {
            printf("Invalid input for burst time.\n");
            return 1;
        }
        printf("Arrival time: ");
        if (scanf("%d", &arrivalTimes[i]) != 1 || arrivalTimes[i] < 0) {
            printf("Invalid input for arrival time.\n");
            return 1;
        }
        printf("Priority: ");
        if (scanf("%d", &priorities[i]) != 1 || priorities[i] < 0) {
            printf("Invalid input for priority.\n");
            return 1;
        }
    }
    
    priorityScheduling(n, burstTimes, arrivalTimes, priorities);
    
    // Free allocated memory
    free(burstTimes);
    free(arrivalTimes);
    free(priorities);
    
    return 0;
}

void priorityScheduling(int n, int bt[], int at[], int priority[]) {
    int *wt, *tat, *ct;
    float total_wt = 0, total_tat = 0;
    
    wt = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    
    if (wt == NULL || tat == NULL || ct == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    int time = 0, completed = 0;
    
    while (completed != n) {
        int minPriorityProcess = -1;
        int minPriority = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && priority[i] < minPriority && bt[i] > 0) {
                minPriority = priority[i];
                minPriorityProcess = i;
            }
        }
        
        if (minPriorityProcess == -1) {
            time++;
            continue;
        }
        
        ct[minPriorityProcess] = time + bt[minPriorityProcess];
        time += bt[minPriorityProcess];
        tat[minPriorityProcess] = ct[minPriorityProcess] - at[minPriorityProcess];
        wt[minPriorityProcess] = tat[minPriorityProcess] - bt[minPriorityProcess];
        
        total_wt += wt[minPriorityProcess];
        total_tat += tat[minPriorityProcess];
        
        bt[minPriorityProcess] = 0;
        
        completed++;
    }
    
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], priority[i], ct[i], wt[i], tat[i]);
    }
    
    if (n != 0) {
        printf("Average Waiting Time: %.2f\n", total_wt / n);
        printf("Average Turnaround Time: %.2f\n", total_tat / n);
    } else {
        printf("Average Waiting Time: N/A\n");
        printf("Average Turnaround Time: N/A\n");
    }
    
    // Free allocated memory
    free(wt);
    free(tat);
    free(ct);
}
