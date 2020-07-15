#include <bits/stdc++.h>
using namespace std;

void Update(int BIT[], int i, int n, int val)
{

    while(i<=n)
    {
        BIT[i]+=val;
        i=i+(i & -i);   ///going to child node
    }
}

int getsum(int BIT[], int i, int n)
{
    int sum=0;
    while(i>0)
    {
        sum+=BIT[i];
        i=i-(i & -i);    ///going to parent by removing the set bit
    }
    return sum;

}

int main()
{
    int n;
    cin>>n;
    int arr[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        Update(arr, i, n, temp);
    }
    int ind;
    cin>>ind;
    cout<<getsum(arr, ind, n);
    int ans=getsum(arr, 4, 5);

}
