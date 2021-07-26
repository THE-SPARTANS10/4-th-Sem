//Name:- Supratim Bhattacharjee
#include<iostream>
#include<fstream>
using namespace std;
const int MAX=2147483647;
/*
Floyd Warshall(DP)
----------------------------
Time complexity:- O(n^3) where n is number of vertices
Space complexity:- O(n^2) for extra dist matrix
*/

void floydWarshallAlgo(int** graph,int n)
{
    int** dist= new int*[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=new int[n];
        for(int j=0;j<n;j++)
            dist[i][j]=graph[i][j];
    }
    for(int x=0;x<n;x++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][x]==MAX || dist[x][j]==MAX)
                    continue;
                else
                {
                    int distFromSelectedVertex=dist[i][x]+dist[x][j];
                    if(distFromSelectedVertex<dist[i][j])
                        dist[i][j]=distFromSelectedVertex;
                }
            }
        }
    }

    for(int x=0;x<n;x++)
    {
        if(dist[x][x]<0)
        {
            cout<<"Negative edge weight cycle detected"<<endl;
            cout<<"Not possible to find using Floyd Warshall algorithm"<<endl;
            return ;
        }
    }

    for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<"Minimum distance between "<<i<<" and "<<j<<" is "<<dist[i][j]<<endl;
		cout<<endl;
	}

    for(int i=0;i<n;i++)
        delete [] dist[i];
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
    int n,e;
    cout<<"Enter number of vertices: ";
    infile>>n;
    cout<<"Enter number of edges: ";
    infile>>e;
    cout<<"Enter graph: "<<endl;
    int** graph=new int*[n];
    for(int i=0;i<n;i++)
        graph[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            infile>>graph[i][j];

    floydWarshallAlgo(graph,n);

    for(int i=0;i<n;i++)
        delete [] graph[i];
    delete [] graph;

    return 0;
}
