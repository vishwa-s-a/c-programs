#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   char a[100],b[100];
   int i,k,j=0;
   printf("Enter the string :\n");;
   gets(a);
   k=strlen(a);
   for(i=(k-1);i>=0;i--)
   {
      b[j]=a[i];
      j++;  
   }
   for(i=0;i<k;i++)
   {
      if(a[i] != b[i])
      {
         printf("This string is not a palindrome\n");
         exit(0);
      }
   
   }
   printf("The string is a palindrome\n");
   return 0;
}