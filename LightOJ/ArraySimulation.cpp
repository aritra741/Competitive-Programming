#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int n,m;
        cin>>n>>m;
        vector <int> arr;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }

        int sz=arr.size();

        for(int i=0;i<m;i++)
        {
            char c;
            int a,b;

            cin>>c;
            if(c=='S')
            {
                cin>>a;
                for(int i=0;i<sz;i++)
                    arr[i]+=a;
            }
            else if(c=='M')
            {
                cin>>a;
                for(int i=0;i<sz;i++)
                    arr[i]*=a;
            }
            else if(c=='D')
            {
                cin>>a;
                for(int i=0;i<sz;i++)
                    arr[i]/=a;
            }
            else if(c=='R')
            {
                reverse(arr.begin(), arr.end());
            }
            else
            {
                cin>>a>>b;
                iter_swap(arr.begin()+a, arr.begin()+b);
            }

        }
        printf("Case %d:\n", t);
        for(int i=0;i<sz-1;i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[sz-1]);

    }
}
