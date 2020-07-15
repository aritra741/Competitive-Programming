#include <bits/stdc++.h>
using namespace std;

bool board[100][100];
int pos= 0;

bool safe( int r,  int row, int col )
{
		for(int j=col;j>=0;j--)
			if(board[row][j]==1)
				return false;

		for(int i=row,j=col;i>=0,j>=0;i--,j--)
			if(board[i][j]==1)
				return false;


		for(int i=row,j=col;i<r,j>=0;i++,j--)
			if(board[i][j]==1)
				return false;

	return true;

}

int utility( int r, int col )
{
	if( col==r )
		{
		    pos++;
		    return 1;
		}
	for(int i=0;i<r;i++)
	{
		if( safe (r, i , col) )
		{
			board[i][col]=1;
			if( utility(r, col+1))
                {
                    pos++;
                    return 1;
                }

            board[i][col]=0;
		}
	}
	return 0;


}

int main()
{
    int n;
    cin>>n;
    utility( n, 0 );
    cout<<pos<<endl;
    if( utility( n, 0 ) )
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"Not possible"<<endl;
}
