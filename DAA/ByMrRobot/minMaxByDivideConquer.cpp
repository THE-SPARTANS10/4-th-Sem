# include <bits/stdc++.h>
using namespace std;
int comparisons = 0;
int getMax(int* arr, int l , int r){
    if (l == r)
        return arr[l];
    int mid = (l+r)/2;
    int maxFromLeft = getMax(arr, l, mid);
    int maxFromRight = getMax(arr, mid + 1, r);
    return max(maxFromLeft, maxFromRight);
}
int getMin(int* arr, int l , int r){
    if (l == r)
        return arr[l];
    int mid = (l+r)/2;
    int maxFromLeft = getMin(arr, l, mid);
    int maxFromRight = getMin(arr, mid + 1, r);
    comparisons++;
    return min(maxFromLeft, maxFromRight);
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Max of array is " << getMax(arr, 0, n-1) << "\n";
    cout << "Min of array is " << getMin(arr, 0, n-1) << "\n";
    cout << comparisons << "\n";
}