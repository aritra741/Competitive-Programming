#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull n,q;
    cin>>n>>q;
    ull num[n];
    ull index[n+1];
    memset(index, 0, sizeof(index));
    for(int i=0;i<n;i++)
        cin>>num[i];
    //cout<<n<<" "<<q<<endl;
    sort(num, num+n);
    for(int i=0;i<q;i++)
    {

        ull q1,q2;
        cin>>q1>>q2;
        index[q1-1]++;
        index[q2]--;

    }
    for(int i=1;i<=n;i++)
        index[i]+=index[i-1];
    sort(index, index+n+1);
    ull sum=0;
    for(int i=0;i<=n;i++)
        sum+=index[i]*num[i];
    cout<<sum;

}
