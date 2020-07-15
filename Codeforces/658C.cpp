#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define mx 100007
using namespace std;

int main()
{
    int n,d,h;
    cin>>n>>d>>h;

    if( h*2<d or d<h )
        return cout<<"-1", 0;

    int base= (d>h)?1:2;

    if(base==2 and d<2 and n>2  )
        return cout<<"-1", 0;

    int k= h+2;

    for( int i=2;i<=h+1;i++ )
        cout<<i-1<<" "<<i<<'\n';

    while(k<=n)
    {
        int baki= min( d-h, n-k+1 );

        cout<<base<<" "<<k++<<endl;

        baki--;

        while(baki>0 and k<=n)
            cout<<k<<" "<<k-1<<endl, baki--, k++;
    }
}
