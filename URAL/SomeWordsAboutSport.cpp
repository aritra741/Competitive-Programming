#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int range=2*n-1;
    int arr[n][n];
    int temp;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        cin>>arr[i][j];
    }
    for(int i=0;i<range;i++)
        for(int col=0;col<=i && col<n;col++)
    {
        int row=i-col;
        if(row>=0 && row<n)
           cout<<arr[row][col]<<" ";
    }
}
