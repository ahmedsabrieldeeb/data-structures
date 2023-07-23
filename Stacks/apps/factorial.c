#include <stdio.h>

double Factorial_iteration(int n);
double Factorial_recursion(int n);

int main(){

    int n;

    printf("Enter the number: ");
    scanf("%d", &n);

    double result = Factorial_recursion(n);

    printf("Factorial of %d is :%lf\n", n, result);
    
    return 0;
}

/*******************Factorial with iteraion*******************/
/*
Pre:
    - Don't enter a negative number
Post:
    - Store the output in a double data type.
*/
double Factorial_iteration(int n){

    double product = 1;

    for ( ;n>=1; n--)
        product *= n;

    return product;
}



/*******************Factorial with recusrsion*******************/
/*
Pre:
    - Don't enter a negative number
Post:
    - Store the output in a double data type.
*/
double Factorial_recursion(int n){

    return (n == 0) ? 1 : n*Factorial_recursion(n-1);
}
