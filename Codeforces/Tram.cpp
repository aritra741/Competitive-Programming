#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,in,out;
    cin>>n;
    int MAX=0;int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>out>>in;
        sum=sum+in-out;
        MAX=max(MAX, sum);
        MAX=max(in,MAX);

    }
    cout<<MAX;

}
