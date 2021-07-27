//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
typedef long long ll;
const int INF=100000;

/*
Bellman Ford(Graph algorithm)
----------------------
Time Complexity:- O(ne) where n is number of vertices and e is number of edges

Space Complexity:- O(n) due to distance array
*/

class Edge
{
    public:
    int src;
    int dst;
    int wt;
    /*Edge()
    {
        src=-1;
        dst=-1;
        wt=INF;
    }
    Edge(int src,int dst,int wt)
    {
        this->src=src;
        this->dst=dst;
        this->wt=wt;
    }*/
};

void bellmanFord(Edge* edges,int n,int e,int sv)
{
    int counter=n-1;
    int* dist=new int[n];
    for(int i=0;i<n;i++)
        dist[i]=INF;
    dist[sv]=0;

    //Relaxation of edges for n-1 times
    while(counter--)
    {
        for(int i=0;i<e;i++)
        {
            if(dist[edges[i].src]!=INF)
            {
                //Relaxation of edges
                if (dist[edges[i].src]+edges[i].wt<dist[edges[i].dst])
                {
                    dist[edges[i].dst]=dist[edges[i].src]+edges[i].wt;
                }
            }
        }
    }

    bool hasNegativeWeightCycle=false;

    //One more time relaxation to find if there is NegativeWeightCycle in graph
    for(int i=0;i<e;i++)
    {
        //If flow goes into if then there is negative weight cycle cause it will change distance array
        if (dist[edges[i].src]+edges[i].wt<dist[edges[i].dst])
        {
            hasNegativeWeightCycle=true;
            break;
        }
    }

    if(hasNegativeWeightCycle)
    {
        cout<<"Negative weight cycle detected"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(i==sv)
                continue;
            cout<<"Minimum distance between "<<sv<<" to "<<i<<" is: "<<dist[i]<<endl;
        }
    }
    delete [] dist;
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

    int n,e,sv;
    //cout<<"Total number of vertices: ";
    infile>>n;
    //cout<<"Total number of edges: ";
    infile>>e;

    //cout<<"Enter source vertex: ";
    Edge* edges=new Edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        //cout<<"Enter source vertex: ";
        infile>>s;
        //cout<<"Enter destination vertex: ";
        infile>>d;
        //cout<<"Enter weight between "<<s<<" and "<<d<<" vertex: "<<w;
        infile>>w;
        edges[i].src=s;
        edges[i].dst=d;
        edges[i].wt=w;
    }

    //cout<<"Enter source: ";
    infile>>sv;

    bellmanFord(edges,n,e,sv);

    delete [] edges;
    return 0;
}
