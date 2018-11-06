/*
	Submitted by : VASHU DEV 
	Roll no		 : 41
	Question no. : 3 - Program to solve N-Queen Problem using backtracking
*/

#include<iostream>
#include<conio.h>
using namespace std;

bool checkQueenSafe(char **board, int n, int row, int col)
{
	 /*
        Objective       : Solve N-Queen problem by using backtracking, checking for the safe position of queen
        				  i.e. no other queen in the same row or same column or diagonal to the position board[row, col]
        Input parameters: board, the chessboard array
        				  n, number of queens
        				  row, index of row
        				  col, index of column
        Return Value    : boolean
    */
	
	int i,j;
	for(i=0; i<col; i++)
		if(board[row][i]=='Q')			//check whether there is a queen in left side of the row 
			return false;
	for (i=row, j=col; i>=0 && j>=0; i--, j--)	//check whether there is a queen in left part of upper diagonal 
        	if (board[i][j]=='Q') 
            		return false;
	for (i=row, j=col; j>=0 && i<n; i++, j--)   //check whether there is a queen in left part of lower diagonal
	if (board[i][j]=='Q') 
	        	return false; 
  
	return true; 
} 


void printboard(char **board, int n)
{
	 /*
        Objective       : Solve N-Queen problem by using backtracking, print the board
        Input parameters: board, the chessboard array
        				  n, number of queens
        Return Value    : none
    */
	
	 
	static int k = 1; 
	cout<<"\n\nSolution "<<k++<<" \n\n"; 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<board[i][j]<<"  ";
		cout<<"\n";
	}
}


bool nqueen(char **board, int n, int t)
{
	 /*
        Objective       : Solve N-Queen problem by using backtracking
        Input parameters: board, the chessboard array
        				  n, number of queens
        				  t, number of block
        Return Value    : boolean
    */
	
	//check whether all queens are placed
	if(t==n)
	{
		printboard(board,n);		// if all queens are placed, print the borad
		return true;
	}
	
	bool a = false;					//initial solution assumption is false 
	
	for(int i=0; i<n; i++)			//placing queens row by row 
	{
		if(checkQueenSafe(board,n,i,t))
		{
			board[i][t]='Q';					
			a=nqueen(board, n, t+1) || a;		
			board[i][t]='-';					
		}
	}
	
	
	return a;
}

//******************************
//main function
//******************************

int main()
{
	 /*
        Objective       : Solve N-Queen problem by using backtracking
        Input parameters: None
        Return Value    : Integer
    */

	int n_queens;
	cout<<"\nEnter number of queens in the problem: ";
	cin>>n_queens; 
	char **board = new char*[n_queens];	//CREATING DYNAMIC BOARD
	for(int i=0; i<n_queens; i++)
		board[i] = new char[n_queens];
		
	//INITIALIZING EVERY BLOCK OF THE BOARD WITH A '-'
	
	for(int i=0; i<n_queens; i++)
		for(int j=0; j<n_queens; j++)
			board[i][j]='-';
			
	//CHECKING POSSIBLITY TO PLACE THE QUEEN IN THE BOARD
	
	if(nqueen(board,n_queens,0)==false)
	{
		cout<<"\nNo solution for the given value";	
	}	
	delete board;							//DEALLOCATION OF MEMORY
	return 0;
}

