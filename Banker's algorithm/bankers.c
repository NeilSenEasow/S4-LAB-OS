#include <stdio.h>

int main() {
    int n, m, available[10], need[10][10], allocation[10][10], max[10][10];
    int i, j, k, p[10], work[10], finish[10], index = 0, flag, y;

    printf("Enter number of Resource Types: ");
    scanf("%d", &m);
    printf("Enter number of Processes: ");
    scanf("%d", &n);

    printf("Enter number of instances of each Resource Type:\n");
    for (i = 0; i < m; i++) {
        printf("Resource Type %d: ", i + 1);
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    printf("Enter number of Allocated instances for each Process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        for (j = 0; j < m; j++) {
            printf("Resource Type %d: ", j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter number of Maximum instances for each Process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        for (j = 0; j < m; j++) {
            printf("Resource Type %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    // Initialize finish array
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Calculate need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Find the safe sequence
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (finish[j] == 0) {
                flag = 0;
                for (k = 0; k < m; k++) {
                    if (need[j][k] > work[k]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    p[index++] = j;
                    for (y = 0; y < m; y++) {
                        work[y] += allocation[j][y];
                    }
                    finish[j] = 1;
                }
            }
        }
    }

    // Check if all processes are finished
    flag = 1;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            flag = 0;
            printf("\nThe system is not in a safe state.\n");
            break;
        }
    }

    if (flag == 1) {
        printf("\nSafe Sequence: ");
        for (i = 0; i < n - 1; i++) {
            printf("P%d -> ", p[i] + 1);
        }
        printf("P%d\n", p[n - 1] + 1);
    }

    return 0;
}
