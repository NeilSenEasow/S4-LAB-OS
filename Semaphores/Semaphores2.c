#include <stdio.h>
#include<stdlib.h>
#include<sys/queue.h>
struct semaphore{
    Queue<process> q;
    int value;
};
 
void P(struct semaphore s)
{
    if (s.value == 1) {
        s.value = 0;
    }
    else {
        s.q.push(P); 
        sleep();
    }
}
 
void V(Semaphore s)
{
    if (s.q is empty) {
        s.value = 1;
    }
    else {
  
        // Get a process from the Waiting Queue
        Process p = q.front();
        // Remove the process from waiting 
        q.pop();
        wakeup(p);
    }
}
int main() {
    printf("This is Hemish!!");
   
    // This code is Contributed by Himesh Singh Chauhan
    return 0;
}