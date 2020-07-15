#include<bits/stdc++.h>
using namespace std;

int n,k;
string s;
vector<int> chunks;

bool ok( int x )
{
    int cnt= 1, p=0;
    for( int i=0;i<chunks.size();i++ )
    {
        if( chunks[i]>x )
            return 0;
        if( chunks[i]+p<=x )
            p+= chunks[i];
        else
            cnt++, p= chunks[i];
    }

    if( cnt<=k )
        return 1;
    return 0;
}

int main()
{
    cin>>k;
    getchar();
    getline(cin,s);

    n=s.size();

    int p= 0;
    for( int i=0;i<n;i++ )
    {
        if(s[i]==' ' or s[i]=='-')
            chunks.push_back(p+1), p=0;
        else
            p++;
    }
    chunks.push_back(p);
    int l= 1, r= n, ans= n;

    while(l<r-4)
    {
        int mid= (l+r)/2;
        if(ok(mid))
            ans= mid,r= mid;
        else
            l= mid;
    }

    while( l<=r )
    {
        if( l<ans and ok(l) )
            ans= l;
        l++;
    }

    cout<< ans <<endl;
}
