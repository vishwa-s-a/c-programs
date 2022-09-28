// works even for octal number so to only change 2 to 8
#include<stdio.h>
#include<math.h>
int main()
{
  int i,j,num,rem,sum=0;
  printf("Enter the binary number\n");
  scanf("%d",&num);
  for(i=0;num>0;i++)
  {
    rem=num%10;
    num=num/10;
    sum=rem*pow(2,i)+sum;
  } 
  printf("the decimal number is %d",sum);
  return 0;
}
