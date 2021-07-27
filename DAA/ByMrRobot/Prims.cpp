#include <bits/stdc++.h>
using namespace std;
int* key, *parent;
class Compare {
public:
    bool operator()(int i, int v) {
        return key[i] > key[v];
    }
};
void print(int** graph, int n){
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1)
            continue;
        cout <<( i+1) << " " << (parent[i]+1) << " -> " << graph[i][parent[i]] <<"\n";
    }
}
void findMSTByPrims(int** graph, int n){
    unordered_set<int>includedInMST;
    key = new int[n];
    parent = new int[n];
    for (int i = 0; i < n; ++i) {
        key[i] = INT_MAX;
    }
    parent[0] = -1;
    key[0] = 0;
    priority_queue<int , vector<int>, Compare>pq;
    for (int i = 0; i < n; ++i) {
        pq.push(i);
    }
    for (int i = 0; i < n; ++i) {
        int minKey = pq.top();
        cout << minKey << "\n";
        pq.pop();
        includedInMST.insert(minKey);
        for (int j = 0; j < n; ++j) {
            if (graph[minKey][j] != 0 && includedInMST.find(j) == includedInMST.end() && graph[minKey][j] < key[j]) {
                key[j] = graph[minKey][j];
                parent[j] = minKey;
            }
        }
    }
    print(graph, n);
}
int main(){
    int n;
    int** graph;
    cout << "Enter number of edges\n";
    cin >> n;
    graph = new int* [n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    findMSTByPrims(graph, n);
    return 0;
}