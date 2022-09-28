// counting the duplicate items in a array.
// if we have to use exit(0) for termination of the program then we have to include stdlib.h;
#include <stdio.h>
int count = 0;
void main()
{
    int i, j, a, n, k = 0;
    printf("Enter the number of elements for the array\n");
    scanf("%d", &n);
    int num[n], num2[n];
    for (i = 0; i < n; i++)
    {
        printf("Element-%d: ", i);
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (num[i] == num[j])
            {
                count++;
                break;
            }
        }
    }
    printf("Total number of duplicate elements found in the array is %d",count);
}