//insertion sort in C
#include <math.h>
#include <stdio.h>
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{	
    int i, key, j;
	for (i = 1; i < n; i++)
    {
		key = arr[i];
		j = i - 1;
		printf("i = %d j = %d key = %d \t", i, j, key);
		while (j >= 0 && arr[j] > key) 
        {	        
            arr[j + 1] = arr[j];
			j = j - 1;
			printf("\n inside loop round %d with j = %d \n ", i, j);
			printArray(arr, n);
		}
		arr[j + 1] = key;
		printArray(arr, n);
	}
}


/* Driver program to test insertion sort */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
