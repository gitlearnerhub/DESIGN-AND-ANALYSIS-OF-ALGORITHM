/*
	Submitted by : VASHU DEV 
	Roll no		 : 41
	Question no. : 1 - find the minimum multiplication operations required for multiplying n matrices
*/
#include <iostream>
#include <conio.h>
using namespace std;

void printOutputOrder(int **m, int i, int j)
{
	/*
        Objective       : Given order of n matrices, print optimal parenthesis for
                          multiplying n matrices in minimum multiplication operations
        Input parameters: m - Integer array, contain matrix dimensions
                          i - Integer,
                          j - Integer,
        Return Value    : None
    */
    
    if(i==j)
        cout<<" A"<<i+1<<" ";
    else
    {
        cout<<"(";
        printOutputOrder(m,i,m[j][i]);
        printOutputOrder(m,m[j][i]+1,j);
        cout<<")";
    }
}

void matrixChainCalc(int *p, int num_mat)
{
	 /*
        Objective       : Given order of n matrices, find the minimum multiplication
                          operations required for multiplying n matrices
        Input parameters: p - Integer array, contain matrix dimensions
                          num_mat - Integer, Number of matrices
        Return Value    : none
    */

	int n=num_mat, q;

    int **m = new int*[n];
	for(int i = 0; i < n; i++)
    	m[i] = new int[n];

    for(int i=0; i<n; i++)
        m[i][i]=0;

    for(int chain=1; chain<n; chain++)
    {
        for(int i=0, j=chain; i<(n-chain), j<n; i++, j++)
        {
            m[i][j]=99999;
            for(int k=i; k<j; k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
                if(q<m[i][j])
                {
                   m[i][j]=q;
                   m[j][i]=k;
                }
            }
        }
    }

    cout<<"\nMinimal Cost for matrix multiplication is "<<m[0][n-1];
    cout<<"\nOrder of Multiplication is ";
    printOutputOrder(m,0,n-1);
    cout<<endl;
}

//******************************
//main function
//******************************


int main()
{0
	 /*
        Objective       : Given order of n matrices, find the minimum multiplication
                          operations required for multiplying n matrices.
        Input parameters: None
        Return Value    : Integer
    */

	int num_mat, row, col, dimcount=0;

	cout<<"How many matrices you want to multiply: ";
	cin>>num_mat;

	int *p = new int[num_mat+1];

	cout<<"Enter the dimensions of each matrix : : \n";

	do
	{

		cout<<"ROWS OF MATRIX 1: ";
		cin>>row;
		p[dimcount++]=row;

		cout<<"COLUMNS OF MATRIX 1: ";
		cin>>col;

		for(int i=1; i<num_mat ; i++)
		{
			cout<<"ROWS OF MATRIX "<<i+1<<": ";
			cin>>row;

			if(row==col)
				p[dimcount++]=row;
			else
			{
				cout<<"Matrices cannot be multiplied as dimensions are not compatible.\nEnter dimensions again.\n";
				dimcount=0;
				break;
			}
			cout<<"COLUMNS OF MATRIX "<<i+1<<": ";
			cin>>col;
		}
	}while(dimcount==0);
	p[dimcount++]=col;

    matrixChainCalc(p,num_mat);
    return 0;
}
