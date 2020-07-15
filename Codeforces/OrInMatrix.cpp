#include <Bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int original[n][m], result[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>result[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            original[i][j]=1;

    int flag=0,cnt=0;;
    bool One=0,done=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                if(!result[i][j])
                    {
                        for(int k=0;k<n;k++)
                            original[k][j]=0;
                        for(int l=0;l<m;l++)
                            original[i][l]=0;
                    }
                else One=1, cnt++;;
            }



    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(result[i][j])
                {
                    done=0;
                    for(int k=0;k<n;k++)
                        if(original[k][j])
                            done=1;
                    for(int l=0;l<m;l++)
                        if(original[i][l])
                            done=1;
                    if(done)
                        flag++;
                }

    if(flag==cnt or !One)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m-1;j++)
                cout<<original[i][j]<<" ";
            cout<<original[i][m-1]<<endl;
        }
    }

    else
        cout<<"NO"<<endl;
}
