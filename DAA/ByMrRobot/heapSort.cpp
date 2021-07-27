#include <bits/stdc++.h>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void heapify(int arr[], int n, int pos) {
    int largest = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != pos) {
        swap(arr[pos], arr[largest]);
        heapify(arr, n, largest);
    }
}
void sort(int arr[], int n) {
    for (int pos = n / 2 - 1; pos >= 0; pos--)
        heapify(arr, n, pos);
    for (int pos = n - 1; pos > 0; pos--) {
        swap(arr[0], arr[pos]);
        heapify(arr, pos, 0);
        displayArray(arr, n);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, n);
    displayArray(arr, n);
}