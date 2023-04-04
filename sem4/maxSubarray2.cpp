// a divide and conquer based program for maximum subarray
// code was written for the purpose of da-2
#include<limits.h>
#include<stdio.h>

int max(int a, int b){
    return (a>b)?a:b;
}

int max(int a, int b, int c){
    return max(max(a,b),c);
}

int maxCrossingSum(int arr[], int l , int m, int h){

    //include elements on left of mid
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=m;i>=l;i--){
        sum=sum+arr[i];
        if(sum>left_sum)
            left_sum=sum;
    }

    //include elements on right of mid
    sum=0;
    int right_sum=INT_MIN;
    for(int i=m;i<=h;i++){
        sum=sum+arr[i];
        if(sum>right_sum)
            right_sum=sum;
    }

    //return sum of elements on left and right of mid
    return max(left_sum+right_sum-arr[m],left_sum,right_sum);
}

int maxSubArraySum(int arr[], int l, int h){
    //Invalid range: low is greater than high
    if(l>h)
        return INT_MIN;
    //BASE CASE:only one element
    if(l==h)
        return arr[l];
    
    //find middle point
    int m=(l+h)/2;

    return max(maxSubArraySum(arr,l,m-1),
                maxSubArraySum(arr,m+1,h),
                maxCrossingSum(arr,l,m,h));
}

int main()
{
    int arr[]={-3,1,8,-6,-1,2,10,-2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_sum=maxSubArraySum(arr,0,n-1);
    printf("Name: Vishwa Shivanand Appaji\nReg No:21BCI0026\n");
    printf("Maximum contiguous sum is %d\n",max_sum);
    //getchar();
    return 0;
}