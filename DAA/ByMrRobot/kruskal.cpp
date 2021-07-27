#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int src, dst, weight;
    bool operator <=(Edge const &obj){
        return weight <= obj.weight;
    }
};
void merge(Edge* items, int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    Edge* L = new Edge[n1];
    Edge* R = new Edge[n2];
    for (int i = 0; i < n1; ++i) {
        L[i] = items[i+l];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = items[i+m+1];
    }
    int i = l, j = 0, k = 0;
    for (; i < r && j < n1 && k< n2; ++i) {
        if(L[j] <= R[k])
            items[i] = L[j++];
        else
            items[i] = R[k++];
    }
    while (j < n1)
        items[i++] = L[j++];
    while (k < n2)
        items[i++] = R[k++];
}
void mergeSort(Edge* items, int l, int r){
    if(l < r){
        int m = l+ (r-l)/2;
        mergeSort(items, l, m);
        mergeSort(items, m+1, r);
        merge(items, l, m, r);
    }
}
class DSU{
public:
    int *parent, *size;
    int n;
    DSU(int n){
        this->n = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            makeSet(i);
        }
    }
    void makeSet(int v){
        parent[v] = v;
        size[v] = 1;
    }
    int findSet(int v){
        if(parent[v] == v)
            return v;
        return parent[v] = findSet(parent[v]);
    }
    void unionSet(int u, int v){
        u = findSet(u);
        v = findSet(v);
        if (u != v){
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
void kruskal(Edge *edges, int n){
    DSU dsu(n);
    Edge ans[n];
    mergeSort(edges, 0, n-1);
    int ansPos = 0, edgePos = 0;
    while (edgePos < n){
        Edge currEdge = edges[edgePos++];
        int a = dsu.findSet(currEdge.src), b = dsu.findSet(currEdge.dst);
        if (a != b){
            ans[ansPos++] = currEdge;
            dsu.unionSet(a, b);
        }
    }
    int minCost = 0;
    cout << "The minimum spanning tree as follows :\n";
    for (int i = 0; i < ansPos; ++i) {
        minCost += ans[i].weight;
        cout << ans[i].src << "->" << ans[i].dst << " = " << ans[i].weight << "\n";
    }
    cout << "The minimum cost is " << minCost << "\n";
}
int main()
{
    fstream infile;
    infile.open("/home/tirthankar/CLionProjects/CollegeDSA4thSem/Day 3/Ex.txt", ios::in);
    if(!infile){
        cout << "Error to open the file";
        return 1;
    }
    int n;
    infile >> n;
    Edge edges[n];
    for (int i = 0; i < n; ++i) {
        infile >> edges[i].src;
        infile >> edges[i].dst;
        infile >> edges[i].weight;
    }
    infile.close();
    kruskal(edges, n);
}
