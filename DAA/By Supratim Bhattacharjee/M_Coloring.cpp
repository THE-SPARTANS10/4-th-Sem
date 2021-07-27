//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

/*
M coloring(Backtracking)
----------------------
Time Complexity:- O(m^n) where n is number of nodes of graph and m is number of colors
Space Complexity:- O(n)+O(m) due to color array and recursion stack apart for graph storage
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

void colorGraphHelper(int currentNode,int* colors,int m,int n,int** graph)
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
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(isSafeToColor(currentNode,colors,graph,n,i))
            {
                colors[currentNode]=i;
                colorGraphHelper(currentNode+1,colors,m,n,graph);
                colors[currentNode]=-1;
            }
        }
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
    fstream infile;
    infile.open("D:\\Engineering books and class notes\\sem4no\\Practical exam\\DAA\\input.txt", ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }

    int m;
    int n,e;
    //cout<<"Enter number of vertices of graph: ";
    infile>>n;
    //cout<<"Enter number of edges of graph: ";
    infile>>e;
    int** adj=new int*[n];
    for(int i=0;i<n;i++)
        adj[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;

    for(ll i=0;i<e;i++)
    {
        //cout<<"Enter connected verties of graph:"<<endl;
        ll first,second;
        infile>>first>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }

    //cout<<"Enter number of colors: ";
    infile>>m;

    colorGraph(adj,m,n);

    if(possibility==0)
        cout<<"There are no posibilities to color the graph"<<endl;
    else
        cout<<"Number of posibilities to color the graph : "<<possibility<<endl;

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;

    return 0;
}
