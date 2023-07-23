#include <stdio.h>

double Fibonacci_iteration(int n);
double Fibonacci_recursion(int n);

int main(){

    int n;

    printf("Enter the number: ");
    scanf("%d", &n);

    double result = Fibonacci_iteration(n);

    printf("Fibonacci of %d is: %lf\n", n, result);
    
    return 0;
}

/*******************Fibonacci with iteraion*******************/
/*
Pre:
    - Don't enter a negative number
Post:
    - Store the output in an int data type.
*/
double Fibonacci_iteration(int n){

    double oneBack, twoBack, current;
    int i;
    
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else // n > 1
    {
        twoBack = 0;
        oneBack = 1;
        for (i = 2; i <= n; i++){
            current = twoBack + oneBack;
            twoBack = oneBack;
            oneBack = current;
        }
        return current;
    }
}



/*******************Fibonacci with recusrsion*******************/
/*
Pre:
    - Don't enter a negative number
Post:
    - Store the output in an int data type.
*/
double Fibonacci_recursion(int n){
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else // n > 1
        return (Fibonacci_recursion(n-1) + Fibonacci_recursion(n-2));
}
