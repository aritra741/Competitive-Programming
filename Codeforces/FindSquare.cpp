#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    int cnt=0;
    bool found=0;
    int col=-1,row=-1;
    int l=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        char c;
        cin>>c;
        cnt=0;
        if(c=='B')
        {
            if(!found)
                {col=j+1;
                found=1;}
            cnt++;
        }

        if(c=='W' and found)
        {
            l=cnt-1;
        }
    }

    col= (col+l)/2;




}
