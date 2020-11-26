#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<ll,ll>
#define ff first
#define ss second
#define piii pair<int,pii>
using namespace std;

ll f( ll val, ll cut )
{
   ll mn = val / cut;
   ll baki = val % cut;

   return (cut - baki) * mn * mn + baki * (mn + 1) * (mn + 1);
}

struct cmp
{
   bool operator()(const pii& a, const pii& b)
   {
      ll val1 = f( a.ff, a.ss ) - f( a.ff, a.ss + 1 );
      ll val2 = f( b.ff, b.ss ) - f( b.ff, b.ss + 1 );

      return val1 < val2;
   }
};

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int n, k;
   cin >> n >> k;

   int arr[n + 5];
   priority_queue<pii,vector<pii>,cmp> pq;

   for ( int i = 0; i < n; i++ )
   {
      ll x;
      cin >> x;

      pq.push(pii(x, 1));
   }

   int cc = n;

   while (cc < k)
   {
      pii u = pq.top();
      pq.pop();
      cc++;
      u.ss++;
      pq.push(u);
   }

   ll ans = 0;

   while (!pq.empty())
   {
      pii u = pq.top();
      pq.pop();
      
      ans += f( u.ff, u.ss );
   }

   cout << ans << "\n";
}
