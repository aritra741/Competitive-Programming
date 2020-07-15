#include <bits/stdc++.h>
using namespace std;

vector<int> arr(1000007);
vector<int> ::iterator it;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr.begin(), arr.begin()+n);

    int q;
    cin>>q;

    while(q--)
    {
        int p;
        cin>>p;

        it= upper_bound(arr.begin(), arr.begin()+n, p);
        int pos= it-arr.begin();

        cout<< pos <<endl;
    }
}
