//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

/*
Job sequencing with deadline(Greedy algorithm)
----------------------------
Time complexity:-O(n^2)
Space complexity:-O(n)
*/

class Job
{
    public:
        int id;
        int profit;
        int deadline;
    Job(){}
    Job(int id,int profit,int deadline)
    {
        this->id=id;
        this->profit=profit;
        this->deadline=deadline;
    }
};


int main()
{
    int n;
    cout<<"Enter number of jobs: ";
    cin>>n;
    Job jobs[n];
    bool done[n]={0};
    int numOfSlots=0;
    int maxProfit=0;
    for(ll i=0;i<n;i++)
    {
        int id,profit,deadline;
        cout<<"Enter profit of job"<<i+1<<": ";
        cin>>profit;
        cout<<"Enter deadline of job"<<i+1<<": ";
        cin>>deadline;
        Job currentJob=Job(i+1,profit,deadline);
        jobs[i]=currentJob;
    }

    for(int i=0;i<n-1;i++)
    {
        Job currentJob=jobs[i];
        int maxProfitJobIndx=i;
        for(int j=i+1;j<n;j++)
        {
            if(jobs[j].profit>jobs[maxProfitJobIndx].profit)
                maxProfitJobIndx=j;
        }
        Job temp=jobs[i];
        jobs[i]=jobs[maxProfitJobIndx];
        jobs[maxProfitJobIndx]=temp;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=min(n-1,jobs[i].deadline-1);j>=0;j--)
        {
            if(!done[j])
            {
                numOfSlots++;
                maxProfit+=jobs[i].profit;
                done[j]=true;
                break;
            }
        }
    }

    cout<<"Maximum profit is: "<<maxProfit<<" and it will take "<<numOfSlots<<" slots"<<endl;

    return 0;
}