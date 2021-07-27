# include <bits/stdc++.h>
using namespace std;

void floydWarshall(int **adjMatrix, int n){
    int distances[n][n];
    int nextVertex[n][n];
    //initialise
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distances[i][j] = adjMatrix[i][j];
            if (adjMatrix[i][j] ==  INT_MAX)
                nextVertex[i][j] = -1;
            else
                nextVertex[i][j] = j;
        }
    }
    //actual logic
    for (int src = 0; src < n; ++src) {
        for (int dst = 0; dst < n; ++dst) {
            for (int intermediate = 0; intermediate < n; ++intermediate) {
                if (distances[src][intermediate] == INT_MAX || distances[intermediate][dst] == INT_MAX)
                    continue;
                if (distances[src][dst] > distances[src][intermediate]+distances[intermediate][dst]) {
                    distances[src][dst] = distances[src][intermediate] + distances[intermediate][dst];
                    nextVertex[src][dst] = nextVertex[src][intermediate];
                }
            }
        }
    }
    //printing distance matrix
    cout << "The distance matrix is as follows\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distances[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << distances[i][j] << " ";
        }
        cout << "\n";
    }
    //detecting negative weight cycle
    for (int i = 0; i < n; ++i) {
        if (distances[i][i] < 0){
            cout << "Negative weight cycle present\n";
            return;
        }
    }
    //printing paths
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j || nextVertex[i][j] == -1)
                continue;
            int src = i, dst = j;
            cout << "Path between " << src+1 << " and " << dst+1 << ":\n";
            while (src != dst){
                cout << src+1 << " ";
                src = nextVertex[src][dst];
            }
            cout << dst+1 << "\n";
        }
    }
}
int main(){
    fstream file;
    file.open("/home/tirthankar/CLionProjects/CollegeDSA4thSem/Day 3/Ex.txt", ios::in);
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
            string inp;
            file >> inp;
            if (inp == "INF")
                adjMatrix[i][j] = INT_MAX;
            else
                adjMatrix[i][j] = stoi(inp);
        }
    }
    file.close();
    floydWarshall(adjMatrix, n);
}