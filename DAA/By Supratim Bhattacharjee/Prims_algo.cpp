//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
#include<climits>
using namespace std;
typedef long long ll;

/*
Prim's algorithm(Greedy algorithm)
----------------------------
Time complexity:- O(n^2) where n is number of vertices and e number of edges
Space complexity:- O(n) for extra arrays
*/

int findMinimumVertex(int* weight,bool* visited,int n)
{
    int minVrtx=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVrtx==-1 || weight[i]<weight[minVrtx]))
            minVrtx=i;
    }
    return minVrtx;
}

void primsAlgo(int** graph,int n)
{
    int totalWeight=0;
    int* parent=new int[n];
    int* weight=new int[n];
    bool* visited=new bool[n];

    for(int i=0;i<n;i++)
    {
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    parent[0]=-1;
    weight[0]=0;

    for(int i=0;i<n;i++)
    {
        int minimumVertex=findMinimumVertex(weight,visited,n);
        visited[minimumVertex]=true;
        for(int j=0;j<n;j++)
        {
            if(graph[minimumVertex][j]!=0 && !visited[j])
            {
                if(graph[minimumVertex][j]<weight[j])
                {
                    weight[j]=graph[minimumVertex][j];
                    parent[j]=minimumVertex;
                }
            }
        }
    }

    cout<<"MST is: "<<endl;
    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
            cout<<"From vertex "<<parent[i]<<" to "<<i<<" vertex weight of MST is "<<weight[i]<<endl;
        else
            cout<<"From vertex "<<i<<" to "<<parent[i]<<" vertex weight of MST is "<<weight[i]<<endl;
        totalWeight+=weight[i];
    }
    cout<<"Total weight of MST is: "<<totalWeight<<endl;
}

void printAdjacencyMatrix(int** adj,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
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

    int n,e;
    //cout<<"Enter number of vertices of graph: ";
    infile>>n;
    //cout<<"Enter number of edges of graph: ";
    infile>>e;

    int** adj=new int*[n];
    for(int i=0;i<n;i++)
    {
        adj[i]=new int[n];
        for(int j=0;j<n;j++)
            adj[i][j]=0;
    }

    for(int i=0;i<e;i++)
    {
        int first,second,weight;
        //cout<<"Enter connected verties of graph:"<<endl;
        infile>>first>>second;
        //cout<<"Enter weight between "<<first<<" node and "<<second<<" node: ";
        infile>>weight;
        adj[first][second]=weight;
        adj[second][first]=weight;
    }

    primsAlgo(adj,n);

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;

    return 0;
}
