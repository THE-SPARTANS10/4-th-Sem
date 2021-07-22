//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

/*
Kruskal's algorithm(Greedy algorithm)
----------------------------
Time complexity:-O(E^2+EV)
*/

class Edge
{
    public:
        int src;
        int dst;
        int wt;
        Edge(){}
        Edge(int src,int dst,int wt)
        {
            this->src=src;
            this->dst=dst;
            this->wt=wt;
        }  
};

bool comp(Edge e1,Edge e2)
{
    return e1.wt<e2.wt;
}

int findParent(int* parent,int vertex)
{
    return parent[vertex]==vertex?vertex:findParent(parent,parent[vertex]);
}

void kruskal_algo(Edge* input,int n,int e)
{
    for(int i=0;i<e-1;i++)
    {
        int minWtEdgeIndx=i;
        for(int j=i+1;j<e;j++)
        {
            if(input[j].wt<input[minWtEdgeIndx].wt)
                minWtEdgeIndx=j;
        }
        swap(input[minWtEdgeIndx],input[i]);
    }

    Edge* output=new Edge[n-1];
    int* parent=new int[n];

    for(int i=0;i<n;i++)
        parent[i]=i;

    int count=0;
    int i=0;
    while(count!=n-1)
    {
        Edge currentEdge=input[i];

        int sourceParent=findParent(parent,currentEdge.src);
        int destinationParent=findParent(parent,currentEdge.dst);

        if(sourceParent!=destinationParent)
        {
            output[count++]=currentEdge;
            parent[sourceParent]=destinationParent;
        }
        i++;
    }

    cout<<"MST of the graph with source destination and weight is: "<<endl;
    for(int i=0;i<n-1;i++)
        cout<<output[i].src<<" "<<output[i].dst<<" "<<output[i].wt<<endl;
}

int main()
{
    int n,e;
    cout<<"Enter number of vertices of graph: ";
    cin>>n;
    cout<<"Enter number of edges of graph: ";
    cin>>e;

    Edge* input=new Edge[e];

    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cout<<"Enter source of "<<i+1<<" edge: ";
        cin>>s;
        cout<<"Enter destination of "<<i+1<<" edge: ";
        cin>>d;
        cout<<"Enter weight of edge between vertex "<<s<<" ans vertex "<<d<<": ";
        cin>>w;
        input[i].src=s;
        input[i].dst=d;
        input[i].wt=w;
    }

    kruskal_algo(input,n,e);
    
    return 0;
}