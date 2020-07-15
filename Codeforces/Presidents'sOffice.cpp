#include <bits/stdc++.h>
using namespace std;

char arr[100][100];
int sti,stj;
bool vis[100][100];
set<char> st;

int main()
{
    int n,m;
    char c;
    cin>>n>>m>>c;


    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];


    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]==c)
            {
                if(i!=0 and arr[i-1][j]!=c and arr[i-1][j]!='.')
                    st.insert( arr[i-1][j] );
                if(i!=n-1 and arr[i+1][j]!=c and arr[i+1][j]!='.')
                    st.insert( arr[i+1][j] );
                if(j!=0 and arr[i][j-1]!=c and arr[i][j-1]!='.')
                    st.insert( arr[i][j-1] );
                if(j!=m-1 and arr[i][j+1]!=c and arr[i][j+1]!='.')
                    st.insert( arr[i][j+1] );
            }
        }

    cout<<st.size();
}
