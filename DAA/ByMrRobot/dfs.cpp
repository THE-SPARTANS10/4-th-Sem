#include<bits/stdc++.h>
using namespace std;
class Stack{
    int *arr, top, len;
public:
    Stack(int size){
        arr = new int[size];
        len = size;
        top = -1;
    }
    int isFull(){
        if(top == len-1)
            return 1;
        else
            return 0;
    }
    int isEmpty(){
        if(top == -1)
            return 1;
        else
            return 0;
    }
    void push(int num){
        if(!isFull()){
            top++;
            arr[top] = num;
        }
        else
            cout << "Stack is full cannot make any more entries\n";
    }
    int pop(){
        if(!isEmpty()){
            int num = arr[top];
            top--;
            return num;
        }
        else{
            cout << "Stack is empty no more popping possible\n";
            return INT_MAX;
        }
    }
    int peek(){
        if (isEmpty())
        {
            cout << "Stack is empty nothing to show\n";
            return INT_MAX;
        }
        return arr[top];
    }
    void display(){
        if (isEmpty()) {
            cout << "Nothing to display\n";
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

};
void recursiveDFS(int vertex, int **adjMatrix, int n, bool visited[]){
    if (visited[vertex])
        return;
    visited[vertex] = true;
    cout << vertex <<" ";
    for (int i = 0; i < n; ++i) {
        if (adjMatrix[vertex][i] != 0)
            recursiveDFS(i, adjMatrix, n, visited);
    }
}
void iterativeDFS(int **adjMatrix, int n){
    Stack stack(n);
    stack.push(0);
    bool visited[n];
    fill(visited, visited+n, false);
    while (!stack.isEmpty()){
        int currVertex = stack.pop();
        if (visited[currVertex])
            continue;
        visited[currVertex] = true;
        cout << currVertex << " ";
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[currVertex][i] != 0 && !visited[i])
                stack.push(i);
        }
    }
}
int main(){
    fstream file;
    file.open("/home/tirthankar/CLionProjects/CollegeDSA4thSem/Day 3/Ex.txt", ios::in);//enter your own file location
    if(!file){
        cout << "Error to open the file";
        return 1;
    }
    int n;
    file >> n;
    int **adjMatrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        adjMatrix[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> adjMatrix[i][j];
        }
    }
    file.close();
    cout << "Iterative dfs\n";
    iterativeDFS(adjMatrix, n);
    cout <<"\n";
    cout << "Recursive dfs\n";
    bool visited[n];
    fill(visited, visited+n, false);
    recursiveDFS(0, adjMatrix, n, visited);
    cout << "\n";
}