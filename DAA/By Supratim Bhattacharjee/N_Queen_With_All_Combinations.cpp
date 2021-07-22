//Name:- Supratim Bhattacharjee
#include<iostream>
using namespace std;
typedef long long ll;

static int count;

bool isSafe(int** grid,int i,int j,int n)
{
    for(int row=0;row<i;row++)
    {
        if(grid[row][j]==1)
            return false;
    }

    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(grid[x][y]==1)
            return false;
        x--;
        y--;
    }

    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(grid[x][y]==1)
            return false;
        x--;
        y++;
    }

    return true;
}

void printGrid(int** grid,int n)
{
    cout<<"Correct configuration of queens: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
                cout<<"Q ";
            else
                cout<<"_ ";
        }
        cout<<endl;
    }
}

bool NQueenHelper(int** grid,int currentRow,int n)
{
    if(currentRow>=n)
    {
        count++;
        printGrid(grid,n);
        cout<<endl;
        return false;
    }
    else
    {
        int currentCol=0;
        for(;currentCol<n;currentCol++)
        {
            if(isSafe(grid,currentRow,currentCol,n))
            {
                grid[currentRow][currentCol]=1;
                bool canNextQueenBePlaced=NQueenHelper(grid,currentRow+1,n);
                if(canNextQueenBePlaced)
                    return true;
                grid[currentRow][currentCol]=0;
            }
        }
        return false;
    }
}

void solveNQueen(int** grid,int n)
{
    int currentRow=0;
    bool result=NQueenHelper(grid,currentRow,n);
}

int main()
{
    int n;
    cout<<"Enter board size: ";
    cin>>n;
    int** grid=new int*[n];
    for(int i=0;i<n;i++)
        grid[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            grid[i][j]=0;

    solveNQueen(grid,n);

    cout<<"Number of configurations: "<<count<<endl;

    for(int i=0;i<n;i++)
        delete [] grid[i];
    delete [] grid;
    
    return 0;
}