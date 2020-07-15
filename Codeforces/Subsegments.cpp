#include <bits/stdc++.h>
using namespace std;

set<int, greater<int>> st;
map<int,int> freq;
int num[100007];

int main()
{
    int n,k;
    cin>>n>>k;

    for( int i=1; i<=k; i++ )
    {
        int p;
        scanf("%d", &p);

        freq[p]++, num[i]= p;

        if( freq[p]==1 )
            st.insert(p);
        else if( freq[p]==2 )
            st.erase(p);
    }

    if( !st.empty() )
        printf("%d\n", (*st.begin()));
    else
        printf("Nothing\n");

    for( int i=k+1; i<=n; i++ )
    {
        int p;
        scanf("%d", &p);

        int idx= (i-k)%k;
        if( !idx )
            idx= k;

        if( idx==k+1 )
            idx= 1;

        freq[ num[ idx ] ]--;

        if(freq[ num[idx] ]==1)
            st.insert(num[idx]);
        else if( !freq[ num[idx] ] )
            st.erase( num[idx] );

        num[ idx ]= p;
        freq[p]++;

        if( freq[p]==1 )
            st.insert(p);
        else if( freq[p]==2 )
            st.erase(p);

        if( !st.empty() )
            printf("%d\n", (*st.begin()));
        else
            printf("Nothing\n");

    }
}
