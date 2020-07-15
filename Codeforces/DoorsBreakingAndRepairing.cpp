#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;;
    cin>>n>>x>>y;

    if(x>y)
    {
        cout<<n<<endl;
        return 0;
    }

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    int cnt= 0;
    bool turn= 1;

    for(int i=0;i<n;i++)
    {
        if( turn )
        {
            if(arr[i]<=x)
                cnt++;
            turn= 0;
        }

         else
         {
             if( arr[i]+y<=x )
                cnt++;
             turn= 1;
         }
    }

    cout<< cnt <<endl;

}
