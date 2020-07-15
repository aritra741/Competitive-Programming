#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

vector <int> v;

int main()
{
    int n,tc=0;
    bool found=0,last=0;

    while(!last)
    {
        while(1)
        {
            cin>>n;

            if(found and n==-1)
            {
                last=1;
                break;
            }

            if(n==-1)
            {
                found=1;
                tc++;
                break;
            }

            else
                {
                    v.push_back(n);
                    found=0;
                }

        }

        if(last)
            break;

        int sz= v.size();
        reverse(v.begin(), v.end());

        int I[sz+5];
        I[0]= -inf;

        for(int i=1;i<=sz;i++)
            I[i]= inf;

        int LIS=1;

        for(int i=0;i<sz;i++)
        {
            int low=0,high= LIS;

            while(low<=high)
            {
                int mid= (low+high)/2;

                if(I[mid] < v[i])
                    low= mid+1;
                else
                    high= mid-1;
            }

            while(I[low]==v[i])
                low++;

            I[low]=v[i];

            if(low>LIS)
                LIS++;

        }

        if(tc>1)
            cout<<endl;

        cout<<"Test #"<<tc<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<LIS<<endl;
        v.clear();

    }
}
