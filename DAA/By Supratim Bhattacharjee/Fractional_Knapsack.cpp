//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

/*
Fractional knapsack algorithm(Greedy algorithm)
----------------------------
Time complexity:-O(n^2)
Space complexity:-O(n)
*/

float profitCalculation(float* profit,float* result,int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
        sum+=profit[i]*result[i];
    return sum;
}

float knapsack(float* profit,float* weight,float w,int n)
{
    float *result=new float[n];
    for(int i=0;i<n;i++)
        result[i]=0;
    for(int i=0;i<n-1;i++)
    {
        int maxIndx=i;
        for(ll j=i+1;j<n;j++)
        {
            if(profit[j]/weight[j]>profit[maxIndx]/weight[maxIndx])
                maxIndx=j;
        }
        swap(profit[i],profit[maxIndx]);
        swap(weight[i],weight[maxIndx]);
    }
    float tempWeight=w;
    int i=0;
    for(;i<n;i++)
    {
        if(weight[i]>tempWeight)
            break;
        result[i]=1;
        tempWeight-=weight[i];
    }
    if(i<n)
        result[i]=tempWeight/weight[i];
    float answer=profitCalculation(profit,result,n);
    delete result;
    return answer;
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
