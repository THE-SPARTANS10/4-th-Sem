//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

/*
Quick Sort(divide and conquer algorithm)
----------------------
Time Complexity:- O(nlogn) in best case, O(n^2) in worst case
Space Complexity:- O(n) due to recursion stack
*/

int partition(int arr[],int low,int high)
{
    int pivot=arr[low]; //Picking first element as pivot
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quickSort(int arr[],int low,int high)
{
    if(high<=low)
        return;
    int pivotIndex=partition(arr,low,high);
    quickSort(arr,low,pivotIndex-1);
    quickSort(arr,pivotIndex+1,high);
}

int main()
{
    int arr[]={4,7,6,-3,2,8,1,56,34,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}