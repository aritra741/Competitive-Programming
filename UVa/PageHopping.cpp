#include <bits/stdc++.h>
using namespace std;
const static int INF=10005;
int main()
{

    int i,j,tc=0;
    while(cin>>i>>j, (i!=0 && j!=0) )
    {
        set <int> st;
        int cnt=0;
        int arr[101][101];
        for(int i=0; i<101; i++)
            for(int j=0; j<101; j++)
                arr[i][j]=INF;

        do
        {
            arr[i][j]=1;
            st.insert(i);
            st.insert(j);
        }
        while(cin>>i>>j, (i!=0 && j!=0));
        tc++;
        int sz=st.size();
        for(int k=0; k<101; k++)
            for(int i=0; i<101; i++)
                for(int j=0; j<101; j++)
                    if(arr[i][j]>arr[i][k]+arr[k][j])
                        arr[i][j]=arr[i][k]+arr[k][j];
        for(int i=0; i<101; i++)
            for(int j=0; j<101; j++)
                if(i!=j && arr[i][j]!=INF)
                    cnt+=arr[i][j];
        double ans;
        ans=cnt/(double)((sz-1)*sz);
        cout<<"Case "<<tc<<": average length between pages = "<<setprecision(3)<<fixed<<ans<<" clicks"<<endl;
    }


}


