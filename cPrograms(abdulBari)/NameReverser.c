//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int i=0;
    int key1,key=0;
    char name[50],name2[50];
    printf("Enter the name: ");
    gets(name);
    for(;i<strlen(name);i++)
    {
        if((int)name[i]==32)
        {
            key=i;
            key1=key;
            int j=0;
            do
            {
                name2[j++]=name[key+1];
                key++;
            }while(name[key]!='\0');
        }
    }
    printf("Your name: ");
    for(i=0;i<strlen(name2);i++)
    {
        printf("%c",name2[i]);
    }
    printf(" ");
    for(i=0;i<key1;i++)
    {
        printf("%c",name[i]);
    }
    return 0;
}