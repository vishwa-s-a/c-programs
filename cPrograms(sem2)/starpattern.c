#include<stdio.h>
void main()
{
  int n,i;
  printf("Enter the number for repepitation\n");
  scanf("%d",&n);
  printf("*\n");
  for(i=1;i<n;i++)
  {
    int j=0;
    for(j=0;j<i;j++)
    {
      if (j==0)
      {
        printf("*");
      }
      printf("\t*");
      if(j==(i-1))
      {
        printf("\n");
      }
    }
  }
}
