#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,q;

    while(scanf("%d %d", &p, &q)==2)
    {
        vector<int>v;

        while( p>1 and q )
        {
            v.push_back(p/q);
            int now= p;
            swap(p,q);
            q= now%p;
        }

        if(v.size())
        {
            cout<<"["<<v[0]<<";";

            for( int i=1;i<(int)v.size()-1;i++ )
                cout<<v[i]<<",";

            if( v.size()>1 )
                cout<<v[v.size()-1];

            cout<<"]\n";
        }
        else
        {
            cout<<"[0;"<<q<<"]\n";
        }
    }
}
