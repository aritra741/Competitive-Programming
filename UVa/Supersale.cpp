#include <bits/stdc++.h>
using namespace std;

int knpsck[1001][31];
int wt[1005];
int val[1005];

int knapsack(int i, int w, int cap, int n)
{
    if(i>n)
        return 0;
    if(knpsck[i][w]!=-1)
        return knpsck[i][w];
    int profit1,profit2;
    if(w+wt[i]>cap)
        profit1=0;
    else
        profit1=val[i]+ knapsack(i+1, w+wt[i], cap, n);
    profit2=knapsack(i+1, w, cap, n);

    knpsck[i][w]=max (profit1, profit2);

    return knpsck[i][w];
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
    int n;
    cin>>n;
    for(int i=01;i<=n;i++)
        cin>>val[i]>>wt[i];
    int p;
    cin>>p;
    int arr[p];
    int tot=0;
    for(int i=0;i<p;i++)
        {
            cin>>arr[i];
            memset( knpsck, -1, sizeof(knpsck) );
            tot+=knapsack(0, 0, arr[i], n);

        }
    cout<<tot<<endl;
    }

}
