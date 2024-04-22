#include<stdio.h>

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

    //value of c[0] before sorting
    c[0] = b[0] - a[0];
    int temp = c[0];

    //Sorting Arrival Time
    int j;  
    for (i = 0; i < num - 1; i++)  {  
       for (j = 0; j < num - i - 1; j++)  {  
          if (a[j] > a[j + 1])  {  
             int temp = a[j];  
             a[j] = a[j + 1];  
             a[j + 1] = temp;  
          }  
       }  
    }  
    printf("Sorted AT\n");
    for( i = 0 ; i < num ; i++ )   {
        printf("%d\t",a[i]);
    }
    printf("\n");

    //Sorting Burst Time
    //int j;  
    for (i = 0; i < num - 1; i++)  {  
       for (j = 0; j < num - i - 1; j++)  {  
          if (b[j] > b[j + 1])  {  
             int temp = b[j];  
             b[j] = b[j + 1];  
             b[j + 1] = temp;  
          }  
       }  
    }  
    printf("Sorted AT\n");
    for( i = 0 ; i < num ; i++ )   {
        printf("%d\t",b[i]);
    }
    printf("\n");
   
   
    //Completion Time
    printf("c[0]: %d",temp);
    printf("\n");
   
    for( i = 1 ; i<num-1 ; i++ )   {
        c[i] = c[i-1] + b[i];
    }

    printf("Process\tArrival Time  Burst Time  Completion Time  TAT  Waiting Time\n");
    for( i = 0; i < num ; i++ )   {
        printf("   %d\t",p[i]);
        printf("     %d\t",a[i]);
        printf("           %d\t",b[i]);
        printf("          %d\n",c[i]);
    }
}