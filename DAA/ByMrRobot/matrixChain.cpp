#include <bits/stdc++.h>
using namespace std;
void printBrackets(int i , int j, int **bracket, char &ch){
    if (i == j){
        cout << ch++ ;
        return;
    }
    cout << "(";
    printBrackets(i, bracket[i][j], bracket, ch);
    printBrackets(bracket[i][j]+1, j, bracket, ch);
    cout << ")";
}
void matrixChain(int p[], int n){
    int minCost[n][n];
    int **brackets = new int *[n];
    for (int i = 0; i < n; ++i) {
        brackets[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        minCost[i][i] = 0;
    }
    for (int chainLen = 2; chainLen < n; ++chainLen) {
        for (int i = 1; i < n-chainLen+1; ++i) {
            int j = i+chainLen-1;
            minCost[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int currCost = minCost[i][k]+minCost[k+1][j]+p[i-1]*p[k]*p[j];
                if (currCost < minCost[i][j])
                {
                    minCost[i][j] = currCost;
                    brackets[i][j] = k;
                }
            }
        }
    }
    cout << "Optimal bracket ordering will be ";
    char ch = 'A';
    printBrackets(1, n-1, brackets, ch);
    cout << "\n";
    cout << "Minimum cost is " << minCost[1][n-1]<<"\n";
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    matrixChain(arr, n);
}
