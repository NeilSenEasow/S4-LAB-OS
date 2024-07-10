#include<stdio.h>

void main() {
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest;
    static int barray[20], parray[20];
    printf("\n\t\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of the blocks:\n");
    for(i = 0; i < nb; i++) {  // Changed to 0-based indexing
        printf("Block no.%d: ", i + 1);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the processes:\n");
    for(i = 0; i < np; i++) {  // Changed to 0-based indexing
        printf("Process no.%d: ", i + 1);
        scanf("%d", &p[i]);
    }
    for(i = 0; i < np; i++) {  // Changed to 0-based indexing
        lowest = 10000;  // Reset lowest for each process
        for(j = 0; j < nb; j++) {  // Changed to 0-based indexing
            if(barray[j] != 1) {
                temp = b[j] - p[i];
                if(temp >= 0 && lowest > temp) {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 0; i < np && parray[i] != 0; i++)  // Changed to 0-based indexing
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i], parray[i] + 1, b[parray[i]], fragment[i]);
}
