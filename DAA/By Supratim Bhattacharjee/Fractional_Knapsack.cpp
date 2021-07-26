//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

/*
Fractional knapsack algorithm(Greedy algorithm)
----------------------------
Time complexity:-O(n^2) (O(n^2) for sorting and O(n) for traversing the whole profit and weight array)
Space complexity:-O(1)
*/

float knapsack(float* profit,float* weight,float w,int n)
{
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        int maxIndx=i;
        for(ll j=i+1;j<n;j++)
        {
            if(profit[j]/weight[j]>profit[maxIndx]/weight[maxIndx])
                maxIndx=j;
        }
        if(i!=maxIndx)
        {
            swap(profit[i],profit[maxIndx]);
            swap(weight[i],weight[maxIndx]);
        }
    }
    float tempWeight=w;
    int i=0;
    for(;i<n;i++)
    {
        if(weight[i]>tempWeight)
            break;
        count+=profit[i];
        tempWeight-=weight[i];
    }
    if(i<n)
        count+=(tempWeight/weight[i])*profit[i];
    return count;
}


int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    float w;
    cout<<"Enter capacity of Knapsack: ";
    cin>>w;
    float *profit=new float[n];
    float *weight=new float[n];
    cout<<"Enter profit values: ";
    for(int i=0;i<n;i++)
        cin>>profit[i];
    cout<<"Enter weight values: ";
    for(int i=0;i<n;i++)
        cin>>weight[i];
    int maxProfit=knapsack(profit,weight,w,n);
    cout<<"Maximum profit is: "<<maxProfit<<endl;
    delete [] profit;
    delete [] weight;

    return 0;
}
