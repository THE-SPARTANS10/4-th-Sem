//Name:- Supratim Bhattacharjee
#include<iostream>
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
----------------------------
Time complexity:-O(n)
*/

int minimum(int a,int b)
{
    return a>b?b:a;
}

int maximum(int a,int b)
{
    return a>b?a:b;
}

MaxAndMin minMax(int arr[],int low,int high)
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
        int mid=low+(high-low)/2;
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
    int arr[]={4,7,6,-3,2,8,1,56,34,23};
    MaxAndMin result=minMax(arr,0,9);

    cout<<result.max<<" "<<result.min<<endl;

    return 0;
}