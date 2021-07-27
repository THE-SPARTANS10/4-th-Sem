//Name:- Supratim Bhattacharjee
#include <iostream>
#include<climits>
#include <fstream>
using namespace std;

/*
DFS(Graph Algorithm)
---------------------------------------------------------------------------------------------------------
Time Complexity:- O(n+e) where n is number of vertices in the graph and e is number of edges in the graph
Space Complexity:- O(n) due to visited array and queue
*/

class Queue
{
    int *arr;
    int front,rear,n;
public:
    Queue(int size)
    {
        n=size;
        arr=new int[n];
        front=0;
        rear=-1;
    }
    void push(int num)
    {
        if(rear==n-1)
            return;
        arr[++rear]=num;
    }
    bool isFull()
    {
    	if(rear==n-1)
            return true;
        return false;
	}
	bool isEmpty()
	{
		if(front==rear+1)
		    return true;
		return false;
	}
    int pop()
    {
        if(front==rear+1)
            return INT_MAX;
        return arr[front++];
    }
    int peek()
    {
    	if(isEmpty())
    		return INT_MAX;
		else
			return arr[front];
	}
    void print()
    {
        for (int i=front;i<rear+1;++i)
            cout<<arr[i]<<" ";
        cout <<endl;
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

void bfsForConnectedGraph(int** adj,int n,int source,int* vis)
{
    Queue pendingVertices(1000);
    pendingVertices.push(source);
    vis[source]=1;
    while(!pendingVertices.isEmpty())
    {
        int currentVertex=pendingVertices.peek();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<n;i++)
        {
            if(i==currentVertex)
                continue;
            if(adj[currentVertex][i] && !vis[i])
            {
                pendingVertices.push(i);
                vis[i]=1;
            }
        }
    }
}

void BFS(int** adj,int n)
{
    int count=0;
    int* visited=new int[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cout<<"Graph "<<++count<<": ";
            bfsForConnectedGraph(adj,n,i,visited);
            cout<<endl;
        }
    }
    delete [] visited;
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
        //cout<<"Enter connected verties of graph:"<<endl;
        int first,second;
        infile>>first>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }
    BFS(adj,n);

    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete [] adj;

    return 0;
}
