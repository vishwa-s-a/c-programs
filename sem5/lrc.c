#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int Size,Blocks;
void lrcCheck(char data[Blocks+1][Size+1])
{
    int i = 0, j = 0, count = 0;
    for (i = 0; i < Size; i++)
    {
        count = 0;
        for (j = 0; j < Blocks; j++)
        {
            if (data[j][i] == '1')
                count += 1;
        }
        // even parity check
        if (count % 2 == 0)
            data[Blocks][i] = '0';

        else
            data[Blocks][i] = '1';

    }

}

bool receiverCheck(char data[Blocks+1][Size+1])
{
    int i = 0, j = 0, count = 0;
    char temp;
    for (i = 0; i < Size; i++)
    {
        count = 0;
        for (j = 0; j < Blocks; j++)
        {
            if (data[j][i] == '1')
                count += 1;
        }
        // even parity check
        if (count % 2 == 0)
            temp = '0';
        else
            temp = '1';

        if (temp != data[Blocks][i])
            return false;
    }
    return true;
}
int main()
{
    printf("Enter the number of bits in each block: ");
    scanf("%d",&Size);
    printf("Enter the number of blocks: ");
    scanf("%d",&Blocks);
    char arr1[Blocks+1][Size+1]; // here we even though we are actually collecting 8 bit data but we give one more bit for null character
    printf("Enter the data which has to be sent: \n");
    for (int i = 0; i < Blocks; i++)
    {
        scanf("%s", arr1[i]); // here we wanna restrict the length of input to be accepted as 8 so we make room for null character after
        fflush(stdin);
    }
    int i;
    for(i=0;i<Size;i++)
    {
        arr1[Blocks][i]='0';
    }
    arr1[Blocks][i]='\0';
    // now we call the lrc check function which will add the lrc for the data on the ending part of the char array
    lrcCheck(arr1);
    printf("\ndata to be sent is : \n");
    for (int i = 0; i <= Blocks; i++)
    {
        if(i!=Blocks)
        printf("%s\n", arr1[i]);
        else
        printf("%s", arr1[i]);
    }
    printf("<---(added parity bits)\n");
    printf("\nParity bits/LRC added is %s\n", arr1[Blocks]);

    if (receiverCheck(arr1))
    {
        printf("No errors encountered\n");
    }
    else
    {
        printf("errors encountered\n");
    }
    return 0;
}