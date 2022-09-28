// to calculate the frequency of alphabets in the given sentence
// using strings and ascii values for storing a number in the required index number.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    char b,a[100],n='a';
    char freq[26]={0};
    int i,len,m;
    printf("Enter the sentence\n");
    scanf("%[^\n]s",&a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        if(isalpha(a[i]))
        {
            b=tolower(a[i]);
            m=(b-n);                                    
            freq[m]=freq[m]+1;

        }

    }
    for(i=0;i<26;i++)
    {
        printf("%c\t%d\n",97+i,freq[i]);
    }

}
