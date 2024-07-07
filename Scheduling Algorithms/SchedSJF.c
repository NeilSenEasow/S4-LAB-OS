#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

void sjf(int n, int bt[], int at[]);

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n],at[n],i;
    
    //Arrival Time
    printf("Enter Arrival Time\n");
    for( i = 0; i < n ; i++ )   {
        scanf("%d",&at[i]);
    }
    //Burst Time
    printf("Enter Burst Time\n");
    for( i = 0; i < n ; i++ )   {
        scanf("%d",&bt[i]);
    }
    
    sjf(n, bt, at);
    
    return 0;
}

void sjf(int n, int bt[], int at[]) {
    int wt[n], tat[n], ct[n], rt[n];
    float total_wt = 0, total_tat = 0;
    int complete = 0, t = 0;

    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    while (complete != n) {
        int shortest = -1;
        int min_rt = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (at[j] <= t && rt[j] < min_rt && rt[j] > 0) {
                min_rt = rt[j];
                shortest = j;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            complete++;
            int finish_time = t + 1;
            ct[shortest] = finish_time;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }

        t++;
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

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}