#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
struct item{
    int weight,value;
    item(int weight,int value)
    {
        this->weight=weight;
        this->value=value;
    }
};
// this is a intermediate function to sort the item and is used in sort() function
// according to val/weight ratio
bool cmp(struct item a, struct item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}

//the important greedy function to solve problem
double fractionalKnapsack(int W,struct item arr[],int N)
{
    //sorting items on basis of ratio
    sort(arr,arr+N,cmp);
    //sort(starting point of array, ending point of array,a function based on which we sort them)
    double finalValue=0.0;

    // now looping through all items
    for(int i=0;i<N;i++)
    {
        //if adding item wont overflow, then add it completely
        if(arr[i].weight<=W)
        {
            W-=arr[i].weight;
            finalValue+=arr[i].value;
        }

        //if we can't add current item, then we add fractional part of it
        else{
            finalValue+=arr[i].value*((double)W/(double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int W=50;// this is the total final capacity of knapsack
    item arr[]={{60,10},{100,20},{120,30}};
    int N=sizeof(arr)/sizeof(arr[0]);//gets the length of the array 

    //making the function call
    cout<<fractionalKnapsack(W,arr,N);
    return 0;
}