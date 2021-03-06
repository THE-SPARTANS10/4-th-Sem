						        /* Program to solve the N-Queens problem using Backtracking */
#include<bits/stdc++.h>
using namespace std;

//Function block to print a solution
void display(int solution[],int n)
{
	cout<<endl;
	cout<<endl;
	cout<<"[ ";
	for(int i=0;i<n;i++)
		cout<<solution[i]+1<<" ";
		cout<<"]";
	cout<<endl;
}

//Function block to return the absolute value of differnce of two numbers
int mod_minus(int a,int b)
{
	if (a>b)
		return a-b;
		
	return b-a;
}

//Function block to check if the current positon is safe i.e. if it doesn't fall in the attacking zone of other Queens 
int safe(int solution[],int r,int c)
{
	int i;
	
	for(i=0;i<r;i++)
	{
		    //Condition of column and diagonal matching respectively of current queen with any other queen 
		if( (solution[i]==c)  ||  (mod_minus(i,r)==mod_minus(solution[i],c)))
			return 0;
	}
	
	return 1;
}

//Function block to find out all possible solutions a
void NQueen(int solution[ ],int r,int n)
{
	for(int c=0;c<n;c++)
	{
		//Condition if the Queen can be placed in the current location
		if(safe(solution,r,c))
		{
			solution[r]=c;
			
			//If the last Queen has been placed successfully
			if(r==n-1)
				display(solution,n);
			
			//Otherwise process continues	
			else
				NQueen(solution,r+1,n);
		}
	}
}

//Driver code
int main(void)
{
	//User input for number of queens
	int n;
	
	cout<<"\nEnter the number of Queens: ";
	cin>>n;
	
	int solution[n];
	
	//Solution is never possible for 3 or less Queens
	if(n<=3)
	{
		cout<<"\nNo solution possible!!!";
		return 1;
	}
	
	cout<<"\nThe possible orientation of the "<<n<<" Queens such that they don't attack each other  are-";
	
	NQueen(solution,0,n);
	
	return 0;
}
