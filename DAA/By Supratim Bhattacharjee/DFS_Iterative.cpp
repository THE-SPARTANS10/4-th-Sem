//Name:- Supratim Bhattacharjee
#include<iostream>
#include<climits>
#include<fstream>
using namespace std;
typedef long long ll;

/*
DFS Iterative(Graph algorithm)
----------------------
Time Complexity:- O(n+e) where n is number of nodes of graph and e is number of edges
Space Complexity:- O(n) due to visited array and stack
*/

class Stack
{
    int *arr, top, MAX;
public:
    Stack(int size)
    {
        top=-1;
        arr=new int[size];
        MAX=size;
    }
    int isFull()
    {
        return top==MAX-1;
    }
    int isEmpty()
    {
        return top==-1;
    }
    void push(int num)
    {
        if(!isFull())
        {
            top++;
            arr[top]=num;
        }
        else
            return;
    }
    void pop(){
        if(!isEmpty())
            int num=arr[top--];
        else{
            return;
        }
    }
    void display()
    {
        if (isEmpty())
            return;
        else
        {
            for (int i=0;i<=top;++i)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    int peek(){
        if (isEmpty())
            return INT_MAX;
        return arr[top];
    }
};

void printAdjacencyMatrix(int** adj,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

void dfsIterative(int** graph,bool* vis,int n,int startingVertex)
{
    Stack nodeSt(1000);
    nodeSt.push(startingVertex);
    while(!nodeSt.isEmpty())
    {
        int currentNode=nodeSt.peek();
        nodeSt.pop();
        if(!vis[currentNode])
        {
            cout<<currentNode<<" ";
            vis[currentNode]=true;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && graph[currentNode][i]==1)
                nodeSt.push(i);
        }
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
    bool* visited=new bool[n];
    int startingVertex=0;
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
        int first,second;
        infile>>first>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }

    cout<<"DFS traversal of graph is: ";
    dfsIterative(adj,visited,n,startingVertex);
    cout<<endl;

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;
    delete [] visited;

    return 0;
}
