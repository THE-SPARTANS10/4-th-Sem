//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
#include<climits>
using namespace std;
typedef long long ll;

/*
Dijkstra's Algorithm(Greedy algorithm)
----------------------
Time Complexity:-O(n^2)
*/

void printAdjacencyMatrix(int** adj,int n)
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

int findDistMinVertex(int* dist,bool* vis,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && (minVertex==-1 || dist[minVertex]>dist[i]))
            minVertex=i;
    }
    return minVertex;
}

void dijkstraAlgo(int** graph,bool* vis,int n,int sv,int dv)
{
    int* dist=new int[n];
    int* parent=new int[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        vis[i]=false;
    }
    parent[sv]=-1;
    dist[sv]=0;

    for(int i=0;i<n-1;i++)
    {
        int minVrtx=findDistMinVertex(dist,vis,n);
        vis[minVrtx]=true;
        for(int j=0;j<n;j++)
        {
            if(graph[minVrtx][j]!=0 && !vis[j])
            {
                int sourceToNeighbourDist=dist[minVrtx]+graph[minVrtx][j];
                if(sourceToNeighbourDist<dist[j])
                {
                    dist[j]=sourceToNeighbourDist;
                    parent[j]=minVrtx;
                }
            }
        }
    }

    cout<<"Minimum distance from vertex "<<sv<<" to vertex "<<dv<<" is: "<<dist[dv]<<endl;

    delete [] dist;
    delete [] parent;
}

int main()
{
    fstream infile;
    infile.open("D:\\Engineering books and class notes\\sem4no\\Practical exam\\DAA\\input.txt", ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }

    int n,e,sourceVertex,destinationVertex;
    //cout<<"Enter number of vertices of graph: ";
    infile>>n;
    //cout<<"Enter number of edges of graph: ";
    infile>>e;
    int** adj=new int*[n];
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        adj[i]=new int[n];
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;

    for(int i=0;i<e;i++)
    {
        //cout<<"Enter connected verties of graph:"<<endl;
        int first,second,weight;
        infile>>first>>second;
        //cout<<"Enter weight between "<<first<<" node and "<<second<<" node: ";
        infile>>weight;
        adj[first][second]=weight;
        adj[second][first]=weight;
    }

    //cout<<"Enter source vertex: ";
    infile>>sourceVertex;
    //cout<<"Enter destination vertex: ";
    infile>>destinationVertex;

    if(sourceVertex>=0 && sourceVertex<n && destinationVertex>=0 && destinationVertex<n)
    {
        dijkstraAlgo(adj,visited,n,sourceVertex,destinationVertex);
    }
    else
        cout<<"Vertex number out of range"<<endl;

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;
    delete [] visited;

    return 0;
}
