#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define mx 100007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

std::vector<pii> v;
int t[mx][21], lg2[mx];

void init( int n )
{
    int i, j, k, m, l, r, q;
    lg2[1] = 0;
    for (i = 2; i <=n; i++) lg2[i] = lg2[i / 2] + 1;
    for (i = 1; i <= n; i++) t[i][0] = v[i].ss;
    for (j = 1; j <= 20; j++) for (i = 1; i + (1 << (j - 1)) <= n; i++) t[i][j] = min(t[i][j-1], t[i + (1 << (j - 1))][j - 1]);
}

int squery( int l, int r )
{
    // int ans = min(ans, t[l][i]), l += (1 << i);
    int k = lg2[r - l + 1];
    int ans = min(t[l][k], t[r - (1 << k) + 1][k]);
    
    return ans;
}

vector<int> f( vector<vector<int>>& rooms, vector<vector<int>>& queries )
{
    v.push_back(pii(-1,-1));

    for( int i=0;i<rooms.size();i++ )
    {
        int x,y;

        for( int j=0;j<rooms[i].size();j++ )
        {
            if(!j)
                x= rooms[i][j];
            else
                y= rooms[i][j];
        }

        v.push_back({y,x});
    }

    sort( v.begin(), v.end() );
    init( (int)v.size()-1 );

    std::vector<int> ans;

    for( int i=0;i<queries.size();i++ )
    {
        int id= queries[i][0];
        int sz= queries[i][1];

        int pos= lower_bound( v.begin(), v.end(), pii(sz,-1) )-v.begin();

        if( pos>=v.size() )
        {
            ans.push_back(-1);
            continue;
        }

        int l= pos, r= (int)v.size()-1;
        int val= 2e9, idx= 2e9;

        while(l<=r-5)
        {
            int mid= (l+r)/2;

            if( squery( pos, mid )<=id )
                l= mid+1;
            else
                r= mid;
        }

        while(l<=r)
        {
            if( abs(v[l].ss-id)==val )
            {
                val= abs(v[l].ss-id);

                if(  v[l].ss<idx )
                    idx= v[l].ss;
            }
            else if( abs(v[l].ss-id)<val )
            {
                val= abs(v[l].ss-id);
                idx= v[l].ss;
            }

            // if( !i )
            //     cout<<l<<" "<<v[l].ss<<" "<<abs(v[l].ss-id)<<endl;

            l++;
        }

        l= pos, r= (int)v.size()-1;
        
        while(l<=r-5)
        {
            int mid= (l+r)/2;

            if( squery( pos, mid )>id )
                r= mid-1;
            else
                l= mid;
        }

        while(l<=r)
        {
            if( abs(v[l].ss-id)==val )
            {
                val= abs(v[l].ss-id);

                if(  v[l].ss<idx )
                    idx= v[l].ss;
            }
            else if( abs(v[l].ss-id)<val )
            {
                val= abs(v[l].ss-id);
                idx= v[l].ss;
            }

            if( !i )
                cout<<l<<" "<<v[l].ss<<" "<<abs(v[l].ss-id)<<endl;

            l++;
        }

        if(val>rooms.size())
        {
            ans.push_back(-1);
            continue;
        }

        ans.push_back(idx);
    }

    return ans;
}

int main()
{
    std::vector< vector<int> > vv= {{23,22},{6,20},{15,6},{22,19},{2,10},{21,4},{10,18},{16,1},{12,7},{5,22}};
    std::vector< vector<int> > qq= {{12,5}};
    
    // {15,15},{21,6},{15,1},{23,4},{15,11},{1,24},{3,19},{25,8},{18,6}

    std::vector<int> x= f( vv, qq );

    for( auto a: x )
        cout<<a<<" ";
}
