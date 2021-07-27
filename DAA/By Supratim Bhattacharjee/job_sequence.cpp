//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

/*
Job sequencing with deadline(Greedy algorithm)
----------------------------
Time complexity:-O(n^2)
Space complexity:-O(n) for extra array
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
    fstream infile;
    infile.open("D:\\Engineering books and class notes\\sem4no\\Practical exam\\DAA\\input.txt", ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }

    int n;
    //cout<<"Enter number of jobs: ";
    infile>>n;
    Job jobs[n];
    bool done[n]={0};
    int jobsDoneSequence[n]={0};
    int numOfSlots=0;
    int maxProfit=0;
    for(ll i=0;i<n;i++)
    {
        int id,profit,deadline;
        //cout<<"Enter profit of job"<<i+1<<": ";
        infile>>profit;
        //cout<<"Enter deadline of job"<<i+1<<": ";
        infile>>deadline;
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
                jobsDoneSequence[j]=jobs[i].id;
                done[j]=true;
                break;
            }
        }
    }


    cout<<"Sequence of jobs done:- "<<endl;
    for (int i=0;i<n;i++)
       if(jobsDoneSequence[i])
            cout<<"Job id. "<<jobsDoneSequence[i]<<"    ";
    cout<<endl<<endl;

    cout<<"Maximum profit is: "<<maxProfit<<"\nIt will take "<<numOfSlots<<" slots"<<endl;

    return 0;
}
