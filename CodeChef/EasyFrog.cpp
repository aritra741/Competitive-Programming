#include <bits/stdc++.h>
using namespace std;
typedef  pair <int, int> pii;
int main()
{
   unsigned long long n,k,p,temp;
   cin>>n>>k>>p;
   vector <pii> arr;
   long long mx[n+1];
   mx[0]=0;
   for(int i=1;i<=n;i++)
    {
        cin>>temp;
        arr.push_back(pii(temp,i));
    }
   sort(arr.begin(), arr.end(), greater<pii>());
   mx[arr[0].second]=arr[0].first+k;
   for(int i=1;i<n;i++)
        {
            if(arr[i-1].first-arr[i].first<=k)
                mx[arr[i].second]=mx[arr[i-1].second];
            else
            mx[arr[i].second]=arr[i].first+k;

        }
    int l,q;
    for(int i=0;i<p;i++)
        {
            cin>>l>>q;

            if(mx[l]==mx[q])
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
}
