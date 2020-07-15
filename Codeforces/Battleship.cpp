#include <bits/stdc++.h>
using namespace std;

char arr[105][105];
int hitCnt[105][105];
bool horR[105][105];
bool horL[105][105];
bool verU[105][105];
bool verD[105][105];

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    bool ok=1;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            ok=1;
            if(arr[i][j]=='.')
            {
                if(i+1>=k and !verU[i][j])
                {
                    for(int l=i; l>=i-k+1; l--)
                        if(arr[l][j]=='#')
                            ok=0;
                    if(ok)
                        for(int l=i; l>=i-k+1; l--)
                            if(arr[l][j]=='.')
                                hitCnt[l][j]++, verD[l][j]=1;
                }

                ok=1;
                if(n-i>=k and !verD[i][j])
                {
                    for(int l=i; l<=i+k-1; l++)
                        if(arr[l][j]=='#')
                            ok=0;
                    if(ok)
                        for(int l=i; l<=i+k-1; l++)
                            if(arr[l][j]=='.')
                                hitCnt[l][j]++, verU[l][j]=1;
                }

                ok=1;
                if(j+1>=k and !horR[i][j])
                {
                    for(int l=j; l>=j-k+1; l--)
                        if(arr[i][l]=='#')
                            ok=0;
                    if(ok)
                        for(int l=j; l>=j-k+1; l--)
                            if(arr[i][l]=='.')
                                hitCnt[i][l]++, horL[i][l]=1;
                }
                ok=1;

                if(n-j>=k and !horL[i][j])
                {
                    for(int l=j; l<=j+k-1; l++)
                        if(arr[i][l]=='#')
                            ok=0;
                    if(ok)
                    for(int l=j; l<=j+k-1; l++)
                        if(arr[i][l]=='.')
                            hitCnt[i][l]++, horR[i][l]=1;
                }
            }
        }

    int mx=0,ansi=1,ansj=1;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(hitCnt[i][j]>mx)
            {
                mx=hitCnt[i][j];
                ansi=i+1;
                ansj=j+1;
            }

    cout<<ansi<<" "<<ansj<<" "<<endl;
}
