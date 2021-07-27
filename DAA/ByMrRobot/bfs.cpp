#include<bits/stdc++.h>
using namespace std;
class LinearQueue{
    int * arr;
    int front, rear, n;
public:
    LinearQueue(int size){
        n = size;
        arr = new int[n];
        front = 0;
        rear = -1;
    }
    bool isFull(){
        return rear == n-1;
    }
    bool isEmpty(){
        return front == rear+1;
    }
    void enqueue(int num){
        if(isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty() && rear != -1)
            rear = -1;
        arr[++rear] = num;
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty\n";
            return INT_MAX;
        }
        return arr[front++];
    }
    void print(){
        if (isEmpty()){
            cout << "Queue is empty nothing to display\n";
            return;
        }
        for (int i = front; i < rear+1; ++i)
        {
            cout << arr[i]<<" ";
        }
        cout <<"\n";
    }

};
void BFS(int **adjMatrix, int n){
    LinearQueue queue(n);
    queue.enqueue(0);
    bool visited[n];
    fill(visited, visited+n, false);
    while (!queue.isEmpty()){
        int currVertex = queue.dequeue();
        if (visited[currVertex])
            continue;
        visited[currVertex] = true;
        cout << currVertex << " ";
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[currVertex][i] != 0 && !visited[i])
                queue.enqueue(i);
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
    cout << "BFS\n";
    BFS(adjMatrix, n);
    cout <<"\n";
}