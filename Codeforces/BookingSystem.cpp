#include <bits/stdc++.h>
#define mx 1010
#define pii pair<int, int>
#define piii pair<int, pii >
#define f first
#define s second
using namespace std;

piii arr[mx];
int cap[mx];
vector<pii> v;

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i].s.f>>arr[i].f;
        arr[i].s.s= i+1;
    }

    sort( arr, arr+n, greater<piii>() );

    int k;
    cin>>k;

    for(int i=0; i<k; i++)
        cin>>cap[i];

    int cnt= 0;
    int tot= 0;

    for(int i=0; i<n; i++)
    {
        int MX= 2000;
        int idx= -1;

        for(int j=0; j<k; j++)
        {
            if(cap[j]>=arr[i].s.f)
            {
                if(cap[j]<MX)
                    MX= cap[j], idx= j;
            }
        }

        if(idx==-1)
            continue;

        cap[idx]= 0;
        cnt++;
        tot+=arr[i].f;
        v.push_back( pii(arr[i].s.s,idx+1) );
    }

    cout<<cnt<<" "<<tot<<endl;

    for(int i=0;i<v.size();i++)
        cout<<v[i].f<<" "<<v[i].s<<endl;
}
