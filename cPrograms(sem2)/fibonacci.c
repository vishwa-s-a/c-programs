#include<stdio.h>
int main()
{
  //fibonacci series
  int i=0,num=0,num3,num1=0,num2=1;
  printf("Enter the number for the series\n ");
  scanf("%d",&num);
  printf("%d,%d,",num1,num2);
  if(num<3)
  {
    goto end;
  }
  for(i=2;i<num;i++)
  {
    num3=num1+num2;
    printf("%d,",num3);
    num1=num2;
    num2=num3;
  }
  end:

  return 0;

}
