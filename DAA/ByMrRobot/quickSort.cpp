#include <bits/stdc++.h>
using namespace std;

int partitionByLomuto(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j < r; ++j) {
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return (i+1);
}
int partitionByHoare(int *arr, int l , int r){
    int pivot = arr[l];
    int i = l-1, j = r+1;
    while (true){
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        arr[i] = arr[i]^arr[j]^(arr[j] = arr[i]);
    }
}
void quickSort(int arr[], int l, int r){
    if (l < r){
//        int p = partitionByLomuto(arr, l, r);
//        quickSort(arr, l , p-1);
//        quickSort(arr, p+1, r);
        int p = partitionByHoare(arr, l, r);
        quickSort(arr, l , p);
        quickSort(arr, p+1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    cout << "Sorted array is :\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
