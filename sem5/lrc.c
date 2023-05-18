#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 
void lrcCheck(char data[5][9])
{
    int i=0,j=0,count=0;
    for(i=0;i<8;i++)
    {
        count=0;
        for(j=0;j<4;j++)
        {
            if(data[j][i] == '1')
            count+=1;
        }
        // even parity check
        if(count%2==0)
        data[4][i]='0';

        else
        data[4][i]='1';
    }
}

bool receiverCheck(char data[5][9])
{
    int i=0,j=0,count=0;
    char temp;
    for(i=0;i<8;i++)
    {
        count=0;
        for(j=0;j<4;j++)
        {
            if(data[j][i] == '1')
            count+=1;
        }
        // even parity check
        if(count%2==0)
        temp='0';
        else
        temp='1';

        if(temp != data[4][i])
        return false;
    }
    return true;
}
int main(){
char arr1[5][9];// here we even though we are actually collecting 8 bit data but we give one more bit for null character
printf("Enter the data which has to be sent: \n");
for (int i = 0; i < 4; i++)
{
    scanf("%8s",arr1[i]);// here we wanna restrict the length of input to be accepted as 8 so we make room for null character after
    //that
    fflush(stdin);
}

//now we call the lrc check function which will add the lrc for the data on the ending part of the char array
lrcCheck(arr1);
printf("data to be sent is : \n");
for (int i = 0; i < 5; i++)
{
    printf("%s\n",arr1[i]);
}

printf("Parity bits/LRC added is %s\n",arr1[4]);

if(receiverCheck(arr1))
{
    printf("No errors encountered\n");
}
else{
    printf("errors encountered\n");
}
return 0;

}