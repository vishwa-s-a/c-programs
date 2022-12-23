//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#define N 8
//global variables
int i=0,j=0;

//here i represents row and j represents columns
void display(int board[N][N])
{
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    // here in this function we will check all possible attacks from other queen
    for(j=0;j<col;j++)
    {
        if(board[row][j])
        return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        return false;
    }
    for(i=row,j=col;i<N && j>=0;i++,j--)
    {
        if(board[i][j])
        return false;
    }
    return true;
    
}
bool nQueenUtil(int board[N][N], int col)
{
    //terminating condition for the recursive functions
    if(col>=N)
    return true;

    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            if(nQueenUtil(board,col+1))
            {
                return true;
            }
            board[i][col]=0;
            //printf("Back-Tracking\n");

        }
    }
    return false;
}
bool solveNQueen()
{
    int board[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }
    if(nQueenUtil(board,0)==false)
    {
        printf("The solution does not exit");
        return false;
    }
    display(board);
    return true;
}
int main()
{
    printf("Name:Vishwa Shivanand Appaji\nReg no:21BCI0026\n");
   solveNQueen();
    return 0;
}