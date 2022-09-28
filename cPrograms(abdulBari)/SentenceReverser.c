//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char input[100],output[100][100];
    int i,w=0,c=0;
    printf("Enter the sentence: ");
    gets(input);
    for(i=0;input[i];i++)
    {
        if(input[i]!=32)
        {
            output[w][c++]=input[i];
        }
        else{
            output[w][c]=0;
            c=0;
            w++;
        }
    }
    for(i=w;i>=0;i--)
    {
        printf("%s ",output[i]);
    }
    printf("\b");
    return 0;
}