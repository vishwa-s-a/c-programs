#include<stdio.h>
#include<string.h>
int i,j,m,n,LCS_table[20][20];
char S1[20]="betacorona",S2[20]="sarbecov",b[20][20];

void IcsAlgo(){
    m=strlen(S1);
    n=strlen(S2);

    //filling 0's in the matrix
    for(i=0;i<=m;i++)
    LCS_table[i][0]=0;
    for(i=0;i<=n;i++)
    LCS_table[0][i]=0;

    //building the martix in bottom-up wat
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
        {
            if(S1[i-1]==S2[j-1])
            LCS_table[i][j]=LCS_table[i-1][j-1]+1;
            else if(LCS_table[i-1][j]>=LCS_table[i][j-1])
            LCS_table[i][j]=LCS_table[i-1][j];
            else
            LCS_table[i][j]=LCS_table[i][j-1];
        }
    }

    int index=LCS_table[m][n];
    char IcsAlgo[index+1];
    IcsAlgo[index]='\0';

    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(S1[i-1]==S2[j-1])
        {
            IcsAlgo[index-1]=S1[i-1];
            i--;
            j--;
            index--;

        }
        else if(LCS_table[i-1][j]>LCS_table[i][j-1])
        i--;
        else
        j--;
    }

    //printing the sub sequences
    printf("S1: %s\nS2: %s\n",S1,S2);
    printf("LCS: %s",IcsAlgo);
}

int main()
{
    printf("Name:Vishwa Shivanand Appaji\nReg No:21BCI0026\n");
    IcsAlgo();
    printf("\n");
}