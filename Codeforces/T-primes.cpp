#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX 1000003
using namespace std;

int arr[MAX];
vector <ull> v;

void sieve(void)
{
    arr[0]=1;
    arr[1]=1;
    for(ull i=2;i<MAX;i++)
    {
        if(arr[i]==0)
        {

            for(ull j=2;i*j<MAX;j++)
                if(arr[i*j]==0)
                    arr[i*j]=1;

        }
    }
    //sort(v.begin(), v.end());

}

int main()
{
    sieve();
    ull n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ull temp;
        cin>>temp;
        ull t=sqrt(temp);
        if(arr[t]==0 && t*t==temp)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
