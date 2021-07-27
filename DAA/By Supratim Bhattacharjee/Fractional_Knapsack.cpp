//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

/*
Fractional knapsack algorithm(Greedy algorithm)
----------------------------
Time complexity:-O(n^2) (O(n^2) for sorting and O(n) for traversing the whole profit and weight array)
Space complexity:-O(1)
*/

void knapsack(float* profit,float* weight,float w,int n)
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
    cout<<"Profit values are: "<<endl;
    int i=0;
    for(;i<n;i++)
    {
        if(weight[i]>tempWeight)
            break;
        count+=profit[i];
        tempWeight-=weight[i];
        cout<<"total of "<<profit[i]<<endl;
    }
    if(i<n)
    {
        count+=(tempWeight/weight[i])*profit[i];
        cout<<(tempWeight/weight[i])<<" part of "<<profit[i]<<endl<<endl;
    }
    cout<<"Maximum profit is: "<<count<<endl;
}


int main()
{
    /*
    Sample Input:- 

    4 50
    60 100 120 40
    10 20 30 40
    */

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
    float w;
    //cout<<"Enter capacity of Knapsack: ";
    infile>>w;
    float *profit=new float[n];
    float *weight=new float[n];
    //cout<<"Enter profit values: ";
    for(int i=0;i<n;i++)
        infile>>profit[i];
    //cout<<"Enter weight values: ";
    for(int i=0;i<n;i++)
        infile>>weight[i];
    knapsack(profit,weight,w,n);
    delete [] profit;
    delete [] weight;

    return 0;
}
