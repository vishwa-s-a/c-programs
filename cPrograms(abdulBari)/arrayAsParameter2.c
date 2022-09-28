// *here we return a array from a function to main()
// *to use dynamic memory allocation you should include stdlib.h
// *in these process we cannot pass array as whole to a function instead we pass arrays address to the function
// and collect the address in function and store it in pointer to access array
// *to return the array also we follow the same and return the address of the array, store it in pointer and access it
#include<stdio.h>
#include<stdlib.h>
int * fun(int n)
{
    int *p;
    p=(int *)malloc(n*sizeof(int));
    return p;
}
int main()
{
    int *A;
    A=fun(5);
    return 0;
}