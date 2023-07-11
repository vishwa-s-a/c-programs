#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
void decToBinary(int num) {
    int index = 0;
    int temp[32];

    // Convert decimal to binary
    while (num > 0) {
        temp[index] = num % 2;
        num = num / 2;
        index++;
    }
    // Print binary representation in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d",temp[i]);
    }
    printf("\n");
}
unsigned char checksum(int sum[], int num)
{
    int total=0;
    for(int i=0;i<num;i++)
    {
        total+=sum[i];
        if(total>255)
        {
            total = (total & 0xFF) + (total >> 8);
        }
    }
    // printf("%d\n",total);
    return (unsigned char)total;
}
int main(){
    int num;
    printf("Enter the number of decimals: ");
    scanf("%d",&num);
    int sum[num];
    for (int i = 0; i < num; i++)
    {
        /* code */
        scanf("%d",&sum[i]);
    }
    unsigned char result=checksum(sum,num);
    unsigned char temp=~result;
    unsigned int temp1=(unsigned int)temp;
    printf("Checksum in decimal: %u\n",temp);
    printf("Checksum in binary: ");
    decToBinary(temp1);
    
return 0;
}