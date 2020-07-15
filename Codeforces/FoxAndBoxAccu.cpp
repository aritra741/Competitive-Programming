#include <bits/stdc++.h>
#define pib pair<int,bool>
using namespace std;
int main()
{
    int n;
    cin>>n;
    pib arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first;
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        arr[i].second=0;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {

        if(arr[i].second==0)
        {
            cnt++;
            int curCnt=1;
            for(int j=i+1;j<n;j++)
            {
            if(curCnt<=arr[j].first && arr[j].second==0)
            {
                curCnt++;
                arr[j].second=1;
            }

            }
        }
    }

    cout<<cnt<<endl;
}

