#include <bits/stdc++.h>
using namespace std;

char arr[3000007];

int main()
{
    int zero,one;
    cin>>zero>>one;

    if( (one<zero-1) or (one>zero*2+2) )
    {
        cout<<"-1\n";
        return 0;
    }

    if(zero>one)
    {
        for(int i=0;i<zero+one;i++)
        {
            if( i&1 )
                cout<<"1";
            else
                cout<<"0";
        }
    }

    else
    {
        int cnt= 0;
        for(int i=2;i<=zero*3+1 and cnt<zero;i+=3)
            arr[i]='0', cnt++;
        cnt= 0;
        for(int i=1;i<=zero*3+1 and cnt<one;i+=3)
            arr[i]= '1', cnt++;
        for(int i=0;i<=zero*3+1 and cnt<one;i+=3)
            arr[i]= '1', cnt++;

        for(int i=0;i<=zero*3+1;i++)
        {
            if(arr[i]==0)
                continue;
            cout<<arr[i];
        }
        cout<<endl;
    }
}
