#include<stdio.h>

void main()   {
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n];

    for(int i = 0 ; i < n ; i++ )   {
        printf("Enter arrival time for process %d ", i+1 );
        scanf("%d",&at[i]);
        printf("Enter burst time for process %d", i+1 );
        scanf("%d",&bt[i]);
        //printf("NextPart");
    }

    printf("Table");
    for ( int j = 0 ; j < n ; j++ )   {
        printf("\t%d\t%d",at[j],bt[j]);
    }

}