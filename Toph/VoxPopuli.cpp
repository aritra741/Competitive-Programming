#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<int,pii>
using namespace std;

map<pii,int>mp;
vector<piii>v;

bool cmp( piii a, piii b )
{
    if( a.first==b.first )
    {
        if( a.second.first==b.second.first )
            return a.second.second<b.second.second;
        return a.second.first<b.second.first;
    }

    return a.first>b.first;
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0; i<n; i++ )
    {
        int p,q;
        scanf("%d %d", &p, &q);

        for( int j=1; j<=10; j++ )
            for( int k=1; k<=10; k++ )
            {
                if( (p-j)%10==0 and (q-k)%10==0 )
                    if( abs(p-j-p)+abs(q-k-q)<=10 )
                        mp[ pii( p-j, q-k ) ]++;
                if( (p+j)%10==0 and (q+k)%10==0 )
                    if( abs(p+j-p)+abs(q+k-q)<=10 )
                        mp[ pii( p+j, q+k ) ]++;
                if( (p-j)%10==0 and (q+k)%10==0 )
                    if( abs(p-j-p)+abs(q+k-q)<=10 )
                        mp[ pii( p-j, q+k ) ]++;
                if( (p+j)%10==0 and (q-k)%10==0 )
                    if( abs(p+j-p)+abs(q-k-q)<=10 )
                        mp[ pii( p+j, q-k ) ]++;
            }

        for( int j=1;j<=10;j++ )
        {
            if( q%10==0 and (p-j)%10==0 )
                mp[ pii(p-j,q) ]++;
            if( p%10==0 and (q-j)%10==0 )
                mp[ pii(p,q-j) ]++;
            if( q%10==0 and (p+j)%10==0 )
                mp[ pii(p+j,q) ]++;
            if( p%10==0 and (q+j)%10==0 )
                mp[ pii(p,q+j) ]++;
        }

        if( p%10==0 and q%10==0 )
            mp[ pii(p,q) ]++;
    }

    for( auto x: mp )
        v.push_back( piii( x.second, x.first ) );

    sort( v.begin(), v.end(), cmp );

    int ff= v[0].first;

    for( int i=0;i<v.size();i++ )
    {
        if( ff==v[i].first )
            cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
        else
            break;
    }

}
