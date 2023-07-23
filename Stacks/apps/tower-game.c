#include <stdio.h>

void MoveDisks(int count, int start, int end, int temp);

/*******************A program to solve tower hanoi problem with recurssion*******************/

/* Here, solving by recursion is much better than iteration approach.
   So, let the OS build its own stack for us, it would be btter.
*/

int main(){
        
    int count, start = 1, end = 3, temp = 2;
    printf("Enter number of disks: ");
    scanf("%d", &count);
    MoveDisks(count, start, end, temp);
    return 0;
}

/*
Pre: 
    - There are at least count disks in start tower
    - Top disk on each of temp tower and end tower is bigger than any
      of the top count in the start tower

Post:
    - The top count disks moved from tower start to end tower
    - Temp tower has returned to its inital state
*/
void MoveDisks(int count, int start, int end, int temp){
    if (count > 0){
        
        MoveDisks(count-1, start, temp, end);
        printf("Moved disk %d from %d to %d\n", count, start, end);
        MoveDisks(count-1, temp, end, start);
    }
    return;
}