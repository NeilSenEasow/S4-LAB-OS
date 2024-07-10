#include <stdio.h>

void main() {
    int bsize[20], psize[20], all[20], m, n, i, j;

    printf("\n\t\tMemory Management Scheme - Worst Fit");
    
    // Input number of blocks
    printf("\nEnter the number of Blocks: ");
    scanf("%d", &m);
    
    // Input size of each block
    printf("Enter the size of each block: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &bsize[i]);
    }
    
    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Input size of each process
    printf("Enter the size of each process: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &psize[i]);
        all[i] = -1; // Initialize all allocations to -1
    }
    
    // Worst Fit Allocation
    for(i = 0; i < n; i++) {
        int worstplace = -1;
        for(j = 0; j < m; j++) {
            if(bsize[j] >= psize[i]) {
                if(worstplace == -1 || bsize[worstplace] < bsize[j]) {
                    worstplace = j;
                }
            }
        }
        if(worstplace != -1) {
            all[i] = worstplace;
            bsize[worstplace] -= psize[i];
        }
    }
    
    // Print allocation results
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if(all[i] != -1) {
            printf("%d\n", all[i] + 1); // +1 for 1-based block number
        } else {
            printf("Not Allocated\n");
        }
    }
}
