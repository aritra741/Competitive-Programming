#include<bits/stdc++.h>
using namespace std;

int d[2][5007];

void Man(string &S,bool T)
{
    int n=S.size();
    for(int i=0,l=0,r=-1; i<n; i++)
    {
        int k=(i>r)?T:min(d[T][l+r-i+!T],r-i+1);
        while(0<=i-k-!T&&i+k<n&&S[i-k-!T]==S[i+k])
            k++;
        d[T][i]=k--;
        if(i+k>r)
        {
            l=i-k-!T;
            r=i+k;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        Man(s,0);
        Man(s,1);

        map<int,int>mp;
        int ans= 1;

        for( int i=0; i<s.size(); i++ )
            ans= max( ans,  max(d[0][i]*2,d[1][i]*2-1) ), mp[ max(d[0][i]*2,d[1][i]*2-1) ]++;

        cout<< ans <<" "<< mp[ans] <<'\n';
    }
}

