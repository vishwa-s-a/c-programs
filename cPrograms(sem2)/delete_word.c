#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,x,y,temp;
    char a[100],b[50];
    printf("Enter the string :\n");
    gets(a);
    printf("The entered string is : %s\n",a);
    printf("Enter the word to be deleted from the string : ");
    gets(b);
    x=strlen(a);
    y=strlen(b);
    for(int i=0;i<x;i++)
    {
        temp=i;// this is to know from which index we exactly get the word
        for(int j=0;j<y;j++)
        {
            if(a[i]==b[j])
            {
                i++;
            }
        }
        if((i-temp)==y)// we are checking whether the complete word to be removed is matching with the word present in the string
        {
            i=temp;// we give value of temp to i as temp is storing the value of index from where word is found.
            for(j=i;j<(x-y);j++)
            {
                a[j]=a[j+y];
            }
            a[j]='\0';// to indicate the end of the string
        }

    }
    printf("The new modified string is : %s",a);
    return 0;
}