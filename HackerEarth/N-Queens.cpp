#include <iostream>
using namespace std;

bool board[100][100];

bool safe( int r,  int row, int col )
{
		for(int j=0;j<row;j++)
			if(board[j][col]==1)
				return false;

		for(int i=row,j=col;i>=0,j>=0;i--,j--)
			if(board[i][j]==1)
				return false;


		for(int i=row,j=col;i>=0,j<r;i--,j++)
			if(board[i][j]==1)
				return false;

	return true;

}

bool utility( int r, int row )
{
	if( row>=r )
		return true;
	for(int i=0;i<r;i++)
	{
		if( safe (r, row , i) )
		{
			board[row][i]=1;
			if( utility(r, row+1))
			return true;

            board[row][i]=0;
		}
	}
	return false;


}

int main()
{
    int n;
    cin>>n;
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
