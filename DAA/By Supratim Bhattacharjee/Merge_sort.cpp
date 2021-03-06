//Name:- Supratim Bhattacharjee
//MERGE SORT
//Time Complexity:-O(nlogn) both in best case and worst case
//Space Complexity:-O(n) for the extra array

/*
Merge sort is a divide and conquer sorting algorithm cause in this sort the array is devided 
into sublists with 1 element at first, then these sublists are merged appropriately using 
merge algorithm(merging two sorted array) and at last we get the sorted array back.
*/

#include<iostream>
#include<fstream>
using namespace std;

static int pass;

//Function to display array elements
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Function to merge two sorted subarrays
void merge(int arr[], int low, int mid, int high,int n)
{
    //Determining the size of two subarrays
    int size1 = mid - low + 1;
    int size2 = high - mid;

    //Creating two subarrays with given size
    int temp1[size1];
    int temp2[size2];

    //copying first part of array into temp1 subarray
    for(int i=0;i<size1;i++)
        temp1[i]=arr[low+i];
    //copying secons part of array into temp2 subarray
    for (int j=0;j<size2;j++)
        temp2[j]=arr[mid+1+j];
    
    //i will point at the first element of temp1 subarray
    int i=0;
    //j will point at the first element of temp2 subarray
    int j=0;
    //k will point at the lower bound of arr array
    int k=low;

    //This while loop will go until any sublist gets exhausted
    while(i<size1 && j<size2)
    {
        if (temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i];
            i++;
        }
        else
        {
            arr[k]=temp2[j];
            j++;
        }
        k++;
    }

    //Second(temp2) sublist got exhausted so copying remaining elements of temp1 to arr 
    while (i<size1)
        arr[k++]=temp1[i++];

    //First(temp1) sublist got exhausted so copying remaining elements of temp2 to arr
    while (j<size2)
        arr[k++]=temp2[j++];

    cout<<"Pass "<<++pass<<": ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Function for merge sort
void mergeSort(int arr[], int low, int high,int n)
{
    //Checking if lowerbound and upperbound are not same or sublist has more than 2 elements
    if(low<high)
    {
        //Finding mid index of the sublist
        int mid=low+(high-low)/2; //For avoiding datatype overflow
        //Applying mergeSort for the first subarray
        mergeSort(arr, low, mid,n);
        //Applying mergeSort for the second subarray
        mergeSort(arr, mid+1, high,n);
        //Merging two sorted subarrays
        merge(arr,low,mid,high,n);
    }
}

int main()
{

    /*
    Input to be given :-

    9
    5 4 3 2 1 10 11 12 100

    */

    fstream infile;
    infile.open("D:\\Engineering books and class notes\\sem4no\\Practical exam\\DAA\\input.txt", ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }

    int n;
    //cout << "Enter the size of the array: ";
    infile>>n;

    int arr[n];
    //cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
        infile >> arr[i];

    cout << "Before merge sort array elements: ";
    displayArray(arr, n);

    mergeSort(arr, 0, n-1, n);

    cout << "After merge sort array elements: ";
    displayArray(arr, n);

    return 0;
}
