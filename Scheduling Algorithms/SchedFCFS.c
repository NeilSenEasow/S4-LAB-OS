/*FCFS Scheduling algorithm automatically executes the queued processes and requests in the order of their arrival. It allocates the job that first arrived in the queue to the CPU, then allocates the second one, and so on.*/

//FIFO queue.

/*Preemptive scheduling allows a running process to be interrupted by a high priority process, whereas in non-preemptive scheduling, any new process has to wait until the running process finishes its CPU cycle. */

/*FCFS follows a preemptive approach.*/


#include<stdio.h>

//void BurstTime

int main()   {
    int p[100],a[100],b[100],c[100],t[100],w[100],i,num;
    printf("Enter number of processes: ");
    scanf("%d",&num);
    
    //Processes
    printf("Enter process\n");
    for( i = 0; i < num ; i++ )   {
        scanf("%d",&p[i]);
    }
    
    //Arrival Time
    printf("Enter Arrival Time\n");
    for( i = 0; i < num ; i++ )   {
        scanf("%d",&a[i]);
    }

    //Burst Time
    printf("Enter Burst Time\n");
    for( i = 0; i < num ; i++ )   {
        scanf("%d",&b[i]);
    }

    //Completion Time
    c[0] = b[0] + a[0];
    //printf("%d\n",c[0]);
    
    for( i = 1 ; i<num ; i++ )   {
        c[i] = c[i-1] + b[i];
    }
    
    //Turn Around Time
    for( i = 0 ; i < num ; i++ )   {
         t[i] = c[i] - a[i];
    }

    //Waiting Time
    for( i = 0 ; i < num ; i++ )   {
        w[i] = t[i] - b[i];
    }

    //Table
    printf("Process\tArrival Time  Burst Time  Completion Time  TAT  Waiting Time\n");
    for( i = 0; i < num ; i++ )   {
        printf("   %d\t",p[i]);
        printf("     %d\t",a[i]);
        printf("           %d\t",b[i]);
        printf("          %d\t",c[i]);
        printf("    %d\t",t[i]);
        printf("     %d\n",w[i]);
    }  
   
    //Gantt Chart
    printf("\n\n");
    printf("Gantt Chart\n");
    //printf("--------------------\n");
    for( i = 0 ; i < num ; i++ )   {
        printf("    %d\t ",p[i]);
    }
    //printf("%d\t ",p[i]);
    printf("\n");
    printf("%d\t",a[0]);
    for( i = 0 ; i < num ; i++ )   {
        printf("%d\t",c[i]);
    }
    
}


















