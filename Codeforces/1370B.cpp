#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        int arr[2*n+5];

        vector<int>odd,ev;

        for( int i=0;i<2*n;i++ )
        {
            cin>> arr[i];

            if(arr[i]&1)
                odd.push_back(i+1);
            else
                ev.push_back(i+1);
        }

        if( odd.size()&1 )
        {
            for( int i=0;i<(int)odd.size()-1;i+=2 )
                cout<< odd[i] <<" "<< odd[i+1] <<endl;
            for( int i=0;i<(int)ev.size()-1;i+=2 )
                cout<< ev[i] <<" "<< ev[i+1] <<endl;
        }

        else
        {
            bool f= 0;
            for( int i=0;i<(int)odd.size()-2;i+=2 )
                f= 1, cout<< odd[i] <<" "<< odd[i+1] <<endl;
            if(odd.size()==2)
                f= 1;
            if(f)
                for( int i=0;i<(int)ev.size();i+=2 )
                    cout<< ev[i] <<" "<< ev[i+1] <<endl;
            else
                for( int i=0;i<(int)ev.size()-2;i+=2 )
                    cout<< ev[i] <<" "<< ev[i+1] <<endl;
        }
    }
}
