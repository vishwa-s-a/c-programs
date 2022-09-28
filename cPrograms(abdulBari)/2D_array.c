//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    //various methods to create 2d array
    int a[3][4];//classic method
    int *b[3];//using pointer and malloc(here the rows are created in stack and columns in heap)
    b[0]=(int *)malloc(4*sizeof(int));
    b[1]=(int *)malloc(4*sizeof(int));
    b[2]=(int *)malloc(4*sizeof(int));

    //now using double pointer
    int **c;
    c=(int **)malloc(3*sizeof(int *));// here the rows are created in heap and as well as columns
    c[0]=(int *)malloc(4*sizeof(int));
    c[1]=(int *)malloc(4*sizeof(int));
    c[2]=(int *)malloc(4*sizeof(int));




    return 0;
}