//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

/*
Quick Sort(divide and conquer algorithm)
----------------------
Time Complexity:- O(nlogn) in best case and average case , O(n^2) in worst case
                  Worst case when array is already sorted in increasing or decreasing order

Space Complexity:- O(logn) in best case or average case and O(n) in worst case due to recursion stack
*/

static int count;

int partition(int* arr,int low,int high,int n)
{
    int pivot=arr[low]; //Picking first element as pivot
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<n)
            i++;
        while(arr[j]>pivot && j>=0)
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
    cout<<"Pass "<<++count<<": ";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return j;
}

void quickSort(int* arr,int low,int high,int n)
{
    if(high<=low)
        return;
    int pivotIndex=partition(arr,low,high,n);
    quickSort(arr,low,pivotIndex-1,n);
    quickSort(arr,pivotIndex+1,high,n);
}

int main()
{
    fstream infile;
    infile.open("D:\\Engineering books and class notes\\sem4no\\Practical exam\\DAA\\input.txt", ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }

    int n;
    //cout<<"Enter array size: ";
    infile>>n;
    int* arr=new int[n];
    //cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
        infile>>arr[i];
    quickSort(arr,0,n-1,n);
    cout<<endl;
    cout<<"Array after using quick sort algorithm: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    delete [] arr;
    return 0;
}
