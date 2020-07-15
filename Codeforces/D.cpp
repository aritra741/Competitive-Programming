#include<bits/stdc++.h>
using namespace std;
int f[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n,m,q,a,b,c,d;
        cin>>n>>m>>q;
        cout<<"Case "<<tc<<"\n";
        for(int i=1;i<=q;i++){
            cin>>a>>b>>c>>d;
            memset(f,0,sizeof(f));
            for(int i=0;i<m;i++){
                f[0][i]=1;
                if(a<=0 && i>=b && c>=0 && i<=d){
                    break;
                }
            }
            for(int i=0;i<n;i++){
                f[i][0]=1;
                if(a<=i && b<=0 && c>=i && d>=0){
                    break;
                }
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(i>=a && j>=b && i<=c && j<=d){
                        f[i][j]=0;
                        continue;
                    }
                    f[i][j]=(f[i-1][j]+f[i][j-1])%912;
                }
            }
            //cout<<f[1][1]<<endl;
            cout<<"   Query "<<i<<": ";
            cout<<f[n-1][m-1]<<endl;
        }
    }
}
