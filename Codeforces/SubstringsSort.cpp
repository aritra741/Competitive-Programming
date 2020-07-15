#include <bits/stdc++.h>
using namespace std;

string arr[110];

bool cmp(const string &a, const string &b)
{
    return a.length()<b.length();
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n, cmp);
    int flag=0;

    for(int i=0;i<n-1;i++)
    {
        int lenS=arr[i].length();
        int lenB=arr[i+1].length();
        for(int j=0;j<=lenB-lenS+1;j++)
        {
            string t=arr[i+1].substr(j, lenS);
            if(t==arr[i])
            {
                flag++;
                break;
            }
        }

    }


    if(flag==n-1)
      {
          cout<<"YES"<<endl;
          for(int i=0;i<n;i++)
            cout<<arr[i]<<endl;
      }

    else
        cout<<"NO"<<endl;
}
