#include <bits/stdc++.h>
using namespace std;

int histo( int arr[], int n )
{
    int mx= -1;
    stack <int> st;
    int i= 0;

    while(i<n)
    {
        if( st.empty() or arr[st.top()]<=arr[i] )
            st.push(i++);
        else
        {
            while(!st.empty() and arr[st.top()]>arr[i])
            {
                int u= st.top();
                st.pop();

                int pos= i;
                if(!st.empty())
                    pos-=(st.top()+1);

                int area= arr[u]*pos;
                mx= max(area, mx);

            }
        }

        //cout<<mx<<endl;
    }

    while(!st.empty())
    {
        int u= st.top();
        st.pop();

        int pos= i;
        if(!st.empty())
            pos-=(st.top()+1);

        int area= arr[u]*pos;
        mx= max(area, mx);

    }

    return mx;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];

        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        printf("Case %d: %d\n", t, histo(arr, n));
    }
}
