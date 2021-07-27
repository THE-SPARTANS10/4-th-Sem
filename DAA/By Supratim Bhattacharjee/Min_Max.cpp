//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

class MaxAndMin
{
    public:
    int max;
    int min;
    MaxAndMin(int mMax,int mMin)
    {
        max=mMax;
        min=mMin;
    }
};

/*
Min-Max algorithm(divide and conquer algorithm)
---------------------------------------------------------
Time complexity:-O(n) but number of comparasions are less
Space complexity:-O(n) due to recursion stack used
*/

int minimum(int a,int b)
{
    return a>b?b:a;
}

int maximum(int a,int b)
{
    return a>b?a:b;
}

MaxAndMin minMax(int* arr,int low,int high)
{
    if(low==high)
    {
        MaxAndMin ans(arr[low],arr[low]);
        return ans;
    }
    else if(low==high-1)
    {
        if(arr[high]>arr[low])
        {
            MaxAndMin ans(arr[high],arr[low]);
            return ans;
        }
        else
        {
            MaxAndMin ans(arr[low],arr[high]);
            return ans;
        }
    }
    else
    {
        int mid=low+(high-low)/2; // to avoid datatype overflow
        MaxAndMin leftPart=minMax(arr,low,mid);
        MaxAndMin rightPart=minMax(arr,mid+1,high);

        int overallMax=maximum(leftPart.max,rightPart.max);
        int overallMin=minimum(leftPart.min,rightPart.min);
        MaxAndMin ans(overallMax,overallMin);
        return ans;
    }
}

int main()
{
    /*
    Input to be given :-

    10
    4 2 7 -678 83 122 1000 46 10 87

    */
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
    MaxAndMin result=minMax(arr,0,n-1);

    cout<<"Maximum element in array: "<<result.max<<endl<<"Minimum element in array:"<<" "<<result.min<<endl;

    delete [] arr;
    return 0;
}
