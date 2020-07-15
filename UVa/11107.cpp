#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair< int, pii >
#define lchild 2*node+1
#define rchild lchild+1
#define M 2000007
using namespace std;
const int kinds = 256;///maximum ASCII value of any character of the string
int nn;
char str[M];
int K, buc[M], r[M], sa[M], X[M], Y[M], high[M];
bool cmp(int *r, int a, int b, int x)
{
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}
vector<int>saa;
int lcp[M];

void suffix_array_DA(int n, int m)
{
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++)
        buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++)
        buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--)
        sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1)
    {
        j = 0;
        for(i = n-l; i < n; i++)
            y[j++] = i;
        for(i = 0; i < n; i++)
            if(sa[i] >= l)
                y[j++] = sa[i]-l;
        for(i = 0; i < m; i++)
            buc[i] = 0;
        for(i = 0; i < n; i++)
            buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++)
            buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--)
            sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l)?j-1:j++;
    }
    for(i = 1; i < n; i++)
        r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
void suffix_array_construction(string s)
{
    int n=s.size();
    for(int i=0; i<n; i++)
        str[i]=s[i];
    str[n]='\0';
    suffix_array_DA(n+1,kinds);

    for(int i=1; i<=n; i++)
        saa.push_back(sa[i]);
}
void lcp_construction(string const& s, vector<int> const& p)
{
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (rank[i] == n - 1)
        {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
}

int pos[M], sz[M];
int tree[M*4];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node]= lcp[l];
        return;
    }

    int mid= (l+r)/2;

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= min( tree[lchild], tree[rchild] );
}

void traverse( int node, int l, int r )
{
    if(l==r)
        return;

    int mid= (l+r)/2;

    traverse( lchild, l, mid );
    traverse( rchild, mid+1, r );
}

int rmq( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 1e9;
    if( l>=i and r<=j )
        return tree[node];

    int mid= (l+r)/2;

    int q1= rmq( lchild, l, mid, i, j );
    int q2= rmq( rchild, mid+1, r, i, j );

    return min( q1, q2 );
}

int baame( int koi, int len )
{
    koi--;
    int l= 0, r= koi, ans= koi+1;

    while(l<=r)
    {
        int mid= (l+r)/2;

        int val= rmq( 0, 0, nn-1, mid, koi );
        if(val>1e8)
            val= 0;
        if( val<len )
            l= mid+1;
        else
            r= mid-1, ans= mid;
    }

    return ans;
}

int daane( int koi, int len )
{
    int l= koi, r= nn-1, ans= 0;

    while(l<=r)
    {
        int mid= (l+r)/2;

        int val= rmq( 0, 0, nn-1, koi, mid );
        if(val>1e8)
            val= 0;
        if( val<len )
            r= mid-1;
        else
            l= mid+1, ans= mid;
    }

    return max(0,ans-koi+1);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    bool f= 0;

    while(1)
    {
        cin>>n;
//        cout<<n<<endl;
        if(!n)
            break;
//        cout<<"shuru holo"<<endl;
        saa.clear();
        memset( lcp, 0, sizeof(lcp) );
//        memset( pos, -1, sizeof(pos) );
//        memset( sz, 0, sizeof(sz) );
//        memset( tree, 0, sizeof(tree) );

        string s;

        int p= 0, q= 1;

        for( int i=0; i<n; i++ )
        {
            string t;
            cin>>t;

            for( int j=0;j<t.size();j++ )
                t[j]= t[j]+5;

            sz[i]= t.size();

            if(i)
                s.push_back((char)(q)), q++, sz[i]++;

            s+= t;

            for( int j=p; j<p+sz[i]; j++ )
            {
                if( s[j]>=102 )
                    pos[j]= i;
                else
                    pos[j]= -1;
            }

            p+= sz[i];
        }

        if(f)
            cout<<"\n";
        else
            f= 1;

        if(n==1)
        {
            for( int i=0;i<s.size();i++ )
                cout<<(char)( s[i]-5 );
            cout<<"\n";
            continue;
        }

        suffix_array_construction(s);
        lcp_construction(s,saa);

        nn= saa.size();

        build( 0, 0, nn-1 );

        int ans= 0, i= 0, j= 1;
        int ase= 0;

        map<int,int>mp;
        vector<pii>v;

//        for( int i=0; i<nn; i++ )
//        {
//            cout<<i<<" "<<lcp[i]<<" ";
//            for( int j=saa[i]; j<nn; j++ )
//                cout<<s[j];
//            cout<<endl;
//        }

        if( pos[ saa[0] ]>=0 )
            mp[ pos[saa[0]] ]++;
        if( pos[ saa[1] ]>=0 )
            mp[ pos[saa[1]] ]++;

        while(i<nn and j<nn)
        {
//            cout<<" "<<i<<" "<<j<<" "<<" "<<val<<" "<<mp.size()<<endl;
            if( mp.size()>n/2 )
            {
                int val= rmq( 0, 0, nn-1, i, j-1 );
//                cout<<"dhukse\n";
//                cout<<i<<" "<<j<<" "<<mp.size()<<" "<<val<<" "<<rmq( 0, 0, nn-1, i, j )<<endl;
//                cout<<i<<" "<<j<<" "<<mp.size()<<" "<<val<<endl;

                if( ans<=val )
                    {
//                        cout<<"thik ase\n";
                        if( ans!=val )
                            v.clear();
//                    cout<<"dhukaisi "<<" "<<saa[i]<<endl;
                        v.push_back( pii( i, j ) );
                        ans= val;
//
//                    while( rmq( 0, 0, nn-1, i, j-1 )>=val and j<nn )
//                        j++;
                    }

                if( pos[saa[i]]>=0 )
                {
                    mp[ pos[saa[i]] ]--;

                    if( !mp[pos[saa[i]]] )
                        mp.erase( pos[saa[i]] );
                }
                i++;
                continue;
            }

            j++;
            if( pos[saa[j]]>=0 )
                mp[ pos[saa[j]] ]++;
        }

//        cout<<"   "<<ans<<endl;
////
//        cout<<v[0].first<<" "<<v[0].second<<endl;

        i= 0, j= 1;

        while(i<v.size() and j<v.size())
        {
//            cout<<i<<" "<<j<<" "<<nn<<endl;
            if(i==j)
            {
                j++;
                continue;
            }

            if( v[i].first==-1 )
            {
                i++;
                continue;
            }
            if( v[j].first==-1 )
            {
                j++;
                continue;
            }


            if( rmq( 0, 0, nn-1, v[i].first, v[j].second-1 )==rmq( 0, 0, nn-1, v[i].first, v[i].second-1 ) )
                v[j].first= -1, j++;
            else
                i++;
        }

//        cout<<"total "<<nn<<endl;
        if(ans)
            for( int i=0;i<v.size();i++ )
            {
                pii vv= v[i];
                if( vv.first==-1 )
                    continue;
//                cout<<vv.first<<" "<<" "<<saa[vv.first]<<" "<< s[ saa[vv.first] ]<<endl;;
                for( int i=saa[vv.first]; i<saa[vv.first]+ans and s[i]; i++ )
                        cout<<(char)(s[i]-5);
                cout<<"\n";
            }
        else
            cout<< "?\n";
    }


}
/*
4
aps
aks
aqs
als
*/
