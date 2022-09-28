// here for finding the reverse of the number dont take rem>0 condition as we will simply add one more zero at the end
// instead we can take num!=0 
# include<stdio.h>
void main()
{
   int num=3456,rev=0;
   int rem;
   do{
       rem=num%10;
       num=num/10;
       rev=rev*10+rem;
   }while(num!=0);
   printf("The reverse of the number is %d",rev);
   
}