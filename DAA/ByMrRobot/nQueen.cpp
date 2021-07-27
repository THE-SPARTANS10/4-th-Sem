#include <bits/stdc++.h>
using namespace std;
bool possible(char **board, int row, int col, int n){
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
void nQueen(char **board, int row, int n){
    if (row == n){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (possible(board, row, col, n)){
            board[row][col]= 'Q';
            nQueen(board, row+1, n);
            board[row][col] = '_';
        }
    }

}
int main()
{
    int n;
    cin >> n;
    char **board = new char *[n];
    for (int i = 0; i < n; ++i) {
        board[i] = new char[n];
        for (int j = 0; j < n; ++j) {
            board[i][j] = '_';
        }
    }
    cout << "All the possibilities are as follows\n";
    nQueen(board, 0, n);
}
