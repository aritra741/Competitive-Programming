#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,q,ans;
bool vis[20007];

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void bfs( int m )
{
    queue<pii> q;
    q.push( pii(1,1%m) );

    while(!q.empty())
    {
        pii u= q.front();
        q.pop();
//        decToBinary(u.first);
//        cout<<endl;
//        if( vis[u.second] )
//            continue;

        if( u.second==0 )
        {
            ans= u.first;
//            decToBinary(ans);
//            cout<<"^"<<endl;
            break;
        }

        int t1= u.first;
        t1<<= 1;
        int mod1= (u.second*10)%m;

        q.push( pii( t1, mod1 ) );

        int t2= u.first;
        t2<<= 1;
        t2|= 1;
        int mod2=(u.second*10+1)%m;

        q.push( pii( t2, mod2 ) );

        vis[mod1]= 1,
        vis[mod2]= 1;
    }
}

int main()
{
    cin>>q;

    while(q--)
    {
        scanf("%d", &n);

        bfs(n);

        vector<int> v;
        while(ans)
        {
            v.push_back(ans%2);
            ans/= 2;
        }

        for(int i=v.size()-1;i>=0;i--)
            printf("%d", v[i]);
        printf("\n");
        ans= 0;
    }

}
