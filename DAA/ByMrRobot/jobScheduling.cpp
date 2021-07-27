#include <bits/stdc++.h>
using namespace std;
class Job{
public:
    int index, profit, deadline;
    bool operator >=(Job const &obj){
        return profit >= obj.profit;
    }
};
void merge(Job* jobs, int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    Job* L = new Job[n1];
    Job* R = new Job[n2];
    for (int i = 0; i < n1; ++i) {
        L[i] = jobs[i+l];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = jobs[i+m+1];
    }
    int i = l, j = 0, k = 0;
    for (; i < r && j < n1 && k< n2; ++i) {
        if(L[j] >= R[k])
            jobs[i] = L[j++];
        else
            jobs[i] = R[k++];
    }
    while (j < n1)
        jobs[i++] = L[j++];
    while (k < n2)
        jobs[i++] = R[k++];
}
void mergeSort(Job* jobs, int l, int r){
    if(l < r){
        int m = l+ (r-l)/2;
        mergeSort(jobs, l, m);
        mergeSort(jobs, m+1, r);
        merge(jobs, l, m, r);
    }
}
void scheduleJobs(Job* jobs, int n){
    int result[n];
    bool time[n];
    mergeSort(jobs, 0, n-1);
    for (int i = 0; i < n; ++i) {
        cout << jobs[i].profit << " ";
    }
    cout <<"\n";
    fill(time, time+n, false);
    for (int i = 0; i < n; ++i) {
        for(int j = min(n, jobs[i].deadline)-1; j >= 0; j--){
            if (!time[j]){
                time[j] = true;
                result[j] = i;
                break;
            }
        }
    }
    int profit = 0;
    cout << "The sequence will be:\n";
    for (int i = 0; i < n; ++i) {
        if (time[i]){
            cout << jobs[result[i]].index << " ";
            profit += jobs[result[i]].profit;
        }
    }
    cout << "\n";
    cout << "The profit is : "<<profit << "\n";
}
int main(){
    int n;
    cin >> n;
    Job* jobs = new Job[n];
    for(int i = 0; i < n; i++)
        jobs[i] = Job();
    cout << "Enter the profits\n";
    for(int i = 0; i < n; i++)
        cin >> jobs[i].profit;
    cout << "Enter the deadlines\n";
    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].deadline;
        jobs[i].index = i+1;
    }
    scheduleJobs(jobs, n);
    return 0;
}

//100 19 27 25 15
//2 1 2 1 3