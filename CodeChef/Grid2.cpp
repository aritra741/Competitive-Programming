#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int cnt=0;
        int n;
        cin>>n;
        char ch[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>ch[i][j];
        int X[n][n],Y[n][n];
        for(int i=0; i<n; i++)
            for(int j=n-1; j>=0; j--)
            {
                if(ch[i][j]=='.')
                {
                    if(j==n-1)
                        X[i][j]=1;
                    else
                        X[i][j]=X[i][j+1];


                }
                else
                    X[i][j]=0;
                if(ch[j][i]=='.')
                {
                    if(j==n-1)
                        Y[j][i]=1;
                    else
                        Y[j][i]=Y[j+1][i];


                }
                else
                    Y[j][i]=0;

            }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(X[i][j]==1 && Y[i][j]==1)
                {

                    cnt++;
                }
                else
                    continue;
            }
        }
 cout<<cnt<<endl;
    }


}

