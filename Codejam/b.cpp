#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 200007
#define inf 1e9
using namespace std;

int arr[mx];
int n,k;

int ok( int x )
{
    int cc= 0;
    for( int i=0;i<n/2;i++ )
    {
        int a= arr[i];
        int b= arr[n-i-1];

        if( a+b==x )
            continue;

        if( a+b<x )
        {
            if( a+b+k-max(a,b)<x )
                cc+= 2;
            else
                cc++;
        }
        else
        {
            if( x<=min(a,b) )
                cc+=2;
            else
                cc++;
        }

        cout<<i<<" "<<cc<<endl;
    }

    return cc;
}

int main()
{
//    fast

    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>k;

        for( int i=0;i<n;i++ )
            cin>> arr[i];

        int l= 2, r= k*2;
//        int ans= n;
//
//        while(r-l>5)
//        {
//            int mid= (r+l)/2;
//
//            int f1= ok(mid);
//            int f2= ok(mid+1);
//
//            cout<<" "<<l<<" "<<r<<" "<<mid<<" "<<f1<<" "<<mid+1<<" "<<f2<<endl;
//
//            if( f1<f2 )
//                ans= f1, r= mid;
//            else
//                l= mid;
//        }
//
//        cout<<" "<<l<<" "<<r<<endl;
        while(l<=r)
        {
            int f= ok(l);

            cout<<"    "<<l<<" "<<ok(l)<<endl;

//            if( f<ans )
//                ans= f;
            l++;
        }

//        cout<< ans <<'\n';
    }
}
