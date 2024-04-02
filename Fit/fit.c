#include<stdio.h>

void FF() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    printf("\n\t\tMemory Management Scheme - First Fit");
    for(i = 0; i < 10; i++) {
        flags[i] = 0;
        allocation[i] = -1;
    }
    printf("\nEnter no. of blocks: ");
    scanf("%d", &bno);
    printf("Enter size of each block: ");
    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("Enter no. of processes: ");
    scanf("%d", &pno);
    printf("Enter size of each process: ");
    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for(i = 0; i < pno; i++) {
        for(j = 0; j < bno; j++) {
            if(bsize[j] >= psize[i]) {
                allocation[i] = j;
                bsize[j] -= psize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void BF() {
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];
    printf("\n\t\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the processes:\n");
    for(i = 1; i <= np; i++) {
        printf("Process no.%d: ", i);
        scanf("%d", &p[i]);
    }
    for(i = 1; i <= np; i++) {
        for(j = 1; j <= nb; j++) {
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
        lowest = 10000;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 1; i <= np && parray[i] != 0; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
}

void WF() {
    int bsize[20], psize[20], all[20], m, n, i, j;
    printf("\n\t\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of Blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each block: ");
    for(i = 0; i < m; i++)
        scanf("%d", &bsize[i]);
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &psize[i]);
        all[i] = -1;
    }
    for(i = 0; i < n; i++) {
        int worstplace = -1;
        for(j = 0; j < m; j++) {
            if(bsize[j] >= psize[i]) {
                if(worstplace == -1)
                    worstplace = j;
                else if(bsize[worstplace] < bsize[j])
                    worstplace = j;
            }
        }
        if(worstplace != -1) {
            all[i] = worstplace;
            bsize[worstplace] -= psize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if(all[i] != -1)
            printf("%d\n", all[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int ch;
    do {
        printf("\n||MEMORY ALLOCATION||");
        printf("\n1. First Fit");
        printf("\n2. Best Fit");
        printf("\n3. Worst Fit");
        printf("\n4. EXIT");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                FF();
                break;
            case 2:
                BF();
                break;
            case 3:
                WF();
                break;
            case 4:
                break;
            default:
                printf("\nINVALID CHOICE");
                break;
        }
    } while(ch != 4);
    return 0;
}