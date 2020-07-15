#include <bits/stdc++.h>
#define inf 100
using namespace std;
int main()
{
    int n;
    int st=0;
    int corr[50],arr[50],I[50];
    map <int, int> mp;
    string s;

    while(getline(cin,s))
    {
        stringstream ss;
        ss<<s;
        int cnt=0;
        int t,l;
        while(ss>>t)
        {
            cnt++;
            if(cnt>1)
                break;
            l=t;
        }

        if(cnt==1)
            n=t,st=1;

        else if(st==1)
        {
            st=2;
            mp[1]=l;
            mp[2]=t;
            int i=2;

            while(ss>>t)
            {
                mp[i+1]=t;
                i++;
            }

        }

        else if(st==2)
        {
            arr[l-1]=1;
            arr[t-1]=2;
            int i=2;

            while(ss>>t)
                {
                    arr[t-1]=i+1;
                    i++;
                }

            I[0]=-inf;
            mp[-inf]=-inf;
            mp[inf]=inf;

            for(int i=1; i<=n; i++)
                I[i]=inf;

            int Ans=1;

            for(int i=0; i<n; i++)
            {
                int low=0,high=Ans;

                while(low<=high)
                {
                    int mid= (low+high)/2;

                    if(mp[I[mid]]> mp[arr[i]])
                        high= mid-1;
                    else
                        low= mid+1;
                }

                I[low]= arr[i];


                if(low>Ans)
                    Ans=low;
            }

            cout<< Ans <<endl;

        }
    }
}
