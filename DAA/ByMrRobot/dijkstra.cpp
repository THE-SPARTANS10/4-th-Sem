#include<bits/stdc++.h>
using namespace std;
int getNearestVertex(bool *visited, int *minDist, int n){
    int minVertex = -1, min = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && minDist[i] <= min){
            min = minDist[i];
            minVertex = i;
        }
    }
    return minVertex;
}
void printPath(int i, int *parent){
    if (parent[i] == -1)
        return;
    printPath(parent[i], parent);
    cout << i << "->";
}
void printPathsAndDist(int *minDist, int *parent, int n, int src){
    for (int i = 0; i < n; ++i) {
        if (i == src)
            continue;
        cout << src << " -> " << i << " " << minDist[i] << " "<< src <<"->";
        printPath(i, parent);
        cout << "\b\b\n";
    }
}
void dijkstra(int **adjMatrix, int n, int src){
    bool visited[n];
    int minDist[n];
    int parent[n];
    for (int i = 0; i < n; ++i) {
        minDist[i] = INT_MAX;
        visited[i] = false;
    }
    parent[src] = -1;
    minDist[src] = 0;
    for (int i = 0; i < n-1; ++i) {
        int currVertex = getNearestVertex(visited, minDist, n);
        if (minDist[currVertex] == INT_MAX)
            continue;
        visited[currVertex] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && adjMatrix[currVertex][j] && minDist[j] > minDist[currVertex]+adjMatrix[currVertex][j]){
                minDist[j] = minDist[currVertex]+adjMatrix[currVertex][j];
                parent[j] = currVertex;
            }
        }
    }
    printPathsAndDist(minDist, parent, n, src);
}
int main()
{
    fstream infile;
    infile.open("/home/tirthankar/CLionProjects/CollegeDSA4thSem/Day 3/Ex.txt", ios::in);
    if(!infile){
        cout << "Error to open the file";
        return 1;
    }
    int n, src;
    infile >> n;
    infile >> src;
    int **adjMatrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        adjMatrix[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> adjMatrix[i][j];
        }
    }
    infile.close();
    dijkstra(adjMatrix, n, src);
    return 0;
}
