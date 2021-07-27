//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;

/*
Kruskal's algorithm(Greedy algorithm)
----------------------------
Time complexity:- O(eloge+elogn)
Space complexity:- O(n)
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

int findParent(int* parent,int vertex)
{
    return parent[vertex]==vertex?vertex:findParent(parent,parent[vertex]);
}

void kruskal_algo(Edge* input,int n,int e)
{
    int totalWeight=0;
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

    cout<<"MST of the graph is: "<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<"From vertex "<<output[i].src<<" to vertex "<<output[i].dst<<" weight of MST is: "<<output[i].wt<<endl;
        totalWeight+=output[i].wt;
    }
    cout<<"Total weight of MST is: "<<totalWeight<<endl;
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

    Edge* input=new Edge[e];

    for(int i=0;i<e;i++)
    {
        int s,d,w;
        //cout<<"Enter source of "<<i+1<<" edge: ";
        infile>>s;
        //cout<<"Enter destination of "<<i+1<<" edge: ";
        infile>>d;
        //cout<<"Enter weight of edge between vertex "<<s<<" ans vertex "<<d<<": ";
        infile>>w;
        input[i].src=s;
        input[i].dst=d;
        input[i].wt=w;
    }

    kruskal_algo(input,n,e);
    
    return 0;
}
