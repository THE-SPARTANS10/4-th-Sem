//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

/*
M coloring(Backtracking)
----------------------
Time Complexity:- O(n^m) where n is number of nodes of graph and m is number of colors
Space Complexity:- O(n)+O(n) due to color array and recursion stack
*/

static int possibility;

void printAdjacencyMatrix(int** adj,int n)
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafeToColor(int currentNode,int* colors,int** graph,int n,int currentColor)
{
    for(int i=0;i<n;i++)
    {
        if(i!=currentNode && graph[i][currentNode]==1 && colors[i]==currentColor)
            return false;
    }
    return true;
}

bool colorGraphHelper(int currentNode,int* colors,int m,int n,int** graph)
{
    //Base case
    if(currentNode==n)
    {
        cout<<"Possibility "<<possibility+1<<": "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"valid Color of node "<<i<<" is "<<colors[i]<<endl;
        }
        possibility++;
        cout<<endl;
        return false;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(isSafeToColor(currentNode,colors,graph,n,i))
            {
                colors[currentNode]=i;
                if(colorGraphHelper(currentNode+1,colors,m,n,graph))
                    return true;
                colors[currentNode]=-1;
            }
        }
        return false;
    }
}

void colorGraph(int** graph,int m,int n)
{
    int* colors=new int[m];
    for(int i=0;i<m;i++)
        colors[i]=-1;
    int initialNode=0;
    colorGraphHelper(initialNode,colors,m,n,graph);
    delete [] colors;
}

int main()
{
    int m;
    int n,e;
    cout<<"Enter number of vertices of graph: ";
    cin>>n;
    cout<<"Enter number of edges of graph: ";
    cin>>e;
    int** adj=new int*[n];
    for(int i=0;i<n;i++)
        adj[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;

    for(ll i=0;i<e;i++)
    {
        cout<<"Enter connected verties of graph:"<<endl;
        ll first,second;
        cin>>first>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }

    cout<<"Enter number of colors: ";
    cin>>m;

    colorGraph(adj,m,n);

    cout<<"Number of posibilities to color the graph : "<<possibility<<endl;

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;

    return 0;
}