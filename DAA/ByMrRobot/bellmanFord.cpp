#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int src, dst, weight;
    bool operator <=(Edge const &obj){
        return weight <= obj.weight;
    }
};
void bellmanFord(Edge *edges, int n, int m, int src){
    int dist[n];
    fill(dist, dist+n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = edges[j].src, v = edges[j].dst, weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[v] > dist[u]+weight)
                dist[v] = dist[u]+weight;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u = edges[i].src, v = edges[i].dst, weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[v] > dist[u]+weight){
            cout << "Negative weight cycle found\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << "Distance between " << src << " and " << i << " is " << dist[i] <<"\n";
    }
}
int main()
{
    fstream infile;
    infile.open("/home/tirthankar/CLionProjects/CollegeDSA4thSem/Day 3/Ex.txt", ios::in);
    if(!infile){
        cout << "Error to open the file";
        return 1;
    }
    int n, m;//nof of edges
    infile >> n;
    infile >> m;
    Edge edges[m];
    for (int i = 0; i < m; ++i) {
        infile >> edges[i].src;
        infile >> edges[i].dst;
        string s;
        infile >> s;
        edges[i].weight = stoi(s);
    }
    infile.close();
    bellmanFord(edges, n, m, 0);
}
