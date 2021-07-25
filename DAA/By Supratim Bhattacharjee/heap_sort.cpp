//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

/*
Heap sort(Sorting algorithm)
----------------------------
Time complexity:-O(nlogn) where n is number of nofes in heap
*/

void heapify(int* arr,int n,int i)
{
    int largest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;

    if(leftChild<n && arr[leftChild]>arr[largest])
        largest=leftChild;

    if(rightChild<n && arr[rightChild]>arr[largest])
        largest=rightChild;

    if(largest==i)
        return;
    else
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int* arr,int n)
{
    int nonLeafeNodesFromBottom=n/2-1;
    for (int i=nonLeafeNodesFromBottom;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
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
    //cout<<"Enter size of array: ";
    infile>>n;
    int* arr=new int[n];
    //cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
        infile>>arr[i];
    heapSort(arr,n);
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    delete [] arr;
    return 0;
}