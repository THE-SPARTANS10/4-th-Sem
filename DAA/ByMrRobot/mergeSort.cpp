#include <bits/stdc++.h>
using namespace std;
int pass = 0;
void merge(int arr[], int l, int m, int r, int n){
    int sizeA = m - l + 1, sizeB = r - m;
    int arrA[sizeA];
    int arrB[sizeB];
    int i = 0;
    for (int j = l;i < sizeA; ++i, j++) {
        arrA[i] = arr[j];
    }
    for (int j = 0; j < sizeB; ++j) {
        arrB[j] = arr[j+m+1];
    }
    int posA = 0, posB = 0;
    for (i = l; i <= r && posA < sizeA && posB < sizeB; i++){
        pass++;
        if (arrA[posA] < arrB[posB]){
            arr[i] = arrA[posA];
            posA++;
        }
        else{
            arr[i] = arrB[posB];
            posB++;
        }
    }
    for (;posA < sizeA; posA++, i++)
        arr[i] = arrA[posA];
    for(;posB < sizeB; posB++, i++)
        arr[i] = arrB[posB];
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void mergeSort(int arr[], int start, int end, int n){
    if (start >= end)
        return;
    int mid = (start+end)/2;
    mergeSort(arr, start, mid, n);
    mergeSort(arr, mid+1, end, n);
    merge(arr, start, mid, end, n);
}
int main() {
    int n;
    cin >>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n-1, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "Number of passes are : " << pass <<"\n";
    return 0;
}
