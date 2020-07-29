#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x1,y1;
    int x2,y2;
    int x3,y3;

    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;

    set<int>hor, ver;

    hor.insert(x1);
    hor.insert(x2);
    hor.insert(x3);

    ver.insert(y1);
    ver.insert(y2);
    ver.insert(y3);

    int ans= min(hor.size()+hor.size()-1, ver.size()+ver.size()-1);
    ans= min( ans, 3 );

    if( x2==x1 and (y3<=min(y2,y1) or y3>=max(y2,y1) ) )
        ans= min( ans, 2 );
    if( x3==x1 and (y2<=min(y3,y1) or y2>=max(y3,y1) ) )
        ans= min( ans, 2 );
    if( x2==x3 and (y1<=min(y2,y3) or y1>=max(y2,y3) ) )
        ans= min( ans, 2 );
    if( y2==y1 and (x3<=min(x2,x1) or x3>=max(x2,x1) ) )
        ans= min( ans, 2 );
    if( y3==y1 and (x2<=min(x3,x1) or x2>=max(x3,x1) ) )
        ans= min( ans, 2 );
    if( y2==y3 and (x1<=min(x2,x3) or x1>=max(x2,x3) ) )
        ans= min( ans, 2 );


    cout<< ans <<endl;
}
