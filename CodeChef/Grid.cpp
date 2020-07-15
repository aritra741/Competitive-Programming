#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long tc;
    cin>>tc;
    while(tc--)
    {
        long long x,y;
        cin>>x>>y;
        if(x>0&&x%2==1&&y>=-x+1 && y<=x+1)
                 cout<<"YES"<<endl;

        else if(x<0&&x%2==0&&y>=x && y<=-x)
                    cout<<"YES"<<endl;

        else if(y>0&&y%2==0&&x>=-y && x<y)
                        cout<<"YES"<<endl;

        else if(y<=0&&y%2==0&&x>=y && x<=-y+1)
                cout<<"YES"<<endl;
        else if(x==0 && y==0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

}
}
