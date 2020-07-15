#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int range=2*n-1;
    int arr[n][n];
    int x=1;
    for(int i=0;i<range;i++)
        for(int row=0;row<=i && row<n;row++)
    {
        int col=i-row;
        if(col>=0 && col<n)
           arr[row][col]=x++;
    }
    for(int i=0;i<n;i++)
        for(int j=n-1;j>=0;j--)
    {
        cout<<arr[i][j]<<" ";
        if(j==0)
            cout<<endl;
    }

}
