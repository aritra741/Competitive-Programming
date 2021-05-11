#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost; // set
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset; // multiset


// direction array
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

// Bitmask

/*
bool check(int mask,int pos){return mask&(1<<pos);}
int SET(int mask,int pos){return mask|(1<<pos);}
int FLIP(int mask,int pos){return mask^(1<<pos);}
int reset(int mask,int pos){return mask&~(1 << pos);}

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y,g;

    point(){}
    point( ll a, ll b, ll c ){
    	x= a;
    	y= b;
    	g= c;
    }

} base;


ll operator | (point a,point b){
    return a.x*b.x+a.y*b.y;
}
ll operator * (point a,point b){
    return a.x*b.y-a.y*b.x;
}
point operator - (point a,point b){
    return point(a.x-b.x,a.y-b.y,a.g);
}

vector<point> points;

int Size;

bool operator == (point a, point b)
{
    return a.x==b.x and a.y==b.y;
}

int area( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool half(point p) { return p.y > 0 || (p.y == 0 && p.x < 0);}
void polar_sort(vector<point> &v) {
    sort(v.begin(), v.end(), [](point a,point b) {
        return make_tuple(half(a-base),0,(a-base)|(a-base))<make_tuple(half(b-base),(a-base)*(b-base),(b-base)|(b-base));
    });
}

int main()
{
	FAST;

	int n;
	cin>>n;

	ll tot= 0;

	for( int i=0;i<n;i++ )
	{
		ll x,y,g;
		cin>>x>>y>>g;

		tot+= g;
		points.push_back(point(x,y,g));
	}

	if(n<3)
		return cout<<"0\n", 0;

	// cout<<tot<<endl;
	ll out= 1e18;

	for( int i=0;i<n;i++ )
	{
		base= points[i];

		std::vector<point> v;

		for( auto x: points )
			if( x.x!=base.x or x.y!=base.y  )
				v.push_back(x);

		ll suff[n+5]= {};
		suff[n]= 0;
		ll pre[n+5]= {};

		polar_sort(v);
		pre[0]= v[0].g;

		for( int j=1;j<v.size();j++ )
			pre[j]= pre[j-1]+v[j].g;

		for( int j=v.size()-1;j>=0;j-- )
			suff[j]= suff[j+1]+v[j].g;

		// cout<<tot<<endl;

		for( int j=0;j<v.size();j++ )
		{
			// cout<<v[j].x<<" "<<v[j].y<<" ";
			ll now= tot-base.g;
			now-= v[j].g;

			int l= j+1;
			int r= v.size()-1;
			int ans1= -1;
			int p= area(base, v[j], v.back());

			while(l<=r)
			{
				int mid= (l+r)/2;

				if(area(base, v[j], v[mid])==p)
					ans1= mid, r= mid-1;
				else
					l= mid+1;
			}

			l= 0,r=j-1;
			ll ans2= -1;

			p= area(base, v[j], v[0]);
			while(l<=r)
			{
				int mid= (l+r)/2;

				if(area(base, v[j], v[mid])==p)
					ans2= mid, l= mid+1;
				else
					r= mid-1;
			}			
			
			ll agey, pore;

			if(ans1==-1)
				pore= 0;
			else
				pore= suff[ans1];

			if(ans2==-1)
				agey= 0;
			else
				agey= pre[ans2];

			ll ekdik= pore+agey;
			ll onnodik= now-ekdik;

			// cout<<ekdik<<" "<<onnodik<<endl;
			// cout<<pore<<" "<<onnodik<<endl;
			out= min( out, llabs(ekdik-onnodik) );

			// cout<<i<<" "<<j<<" "<<llabs(ekdik-onnodik)<<endl;
			// pre+= v[j].g;
			// cout<<" "<<pre<<" "<<v[j].g<<endl;
		}
	}

	cout<<out<<endl;
}