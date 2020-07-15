#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        ll n;
        int m;
        scanf("%lld %d", &n, &m);

        int arr[m];
        priority_queue<pii>pq;

        for( int i=0;i<m;i++ )
            scanf("%d", &arr[i]);

        sort( arr, arr+m, greater<int>() );

        ll tot= 0;
        int j= 0;

        while(j<m)
        {
            if( tot+arr[j]<=n )
                tot+= arr[j], arr[j]= -1;
            j++;
        }

        if( tot==n )
        {
            printf("0\n");
            continue;
        }

        for( int i=0;i<m;i++ )
            if( arr[i]>-1 )
                pq.push(pii(arr[i],0));

        ll rem= n-tot;
        ll ans= 0;

        while( !pq.empty() and rem>0 )
        {
            pii u= pq.top();
//            cout<<u<<endl;
            if(!u.ff)
                break;

            pq.pop();

            if( rem>=u.ff )
                rem-= u.ff, ans+= u.ss;
            else
                pq.push(pii(u.ff/2, u.ss+1)),
                pq.push(pii(u.ff/2, u.ss+1));
        }

        if( rem )
            ans= -1;

        printf("%lld\n", ans);
    }
}
