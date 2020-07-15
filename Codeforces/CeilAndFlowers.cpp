#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    ll flowers[3];
    cin>>flowers[0]>>flowers[1]>>flowers[2];
    sort(flowers, flowers+3);

    ll rem = min( flowers[0]%3, min(flowers[1]%3, flowers[2]%3) );
    ll ans1=0, ans2=0, ans3=0;
    ans1= flowers[0]/3 + flowers[1]/3 + flowers[2]/3;
    if(flowers[0])
        ans2= 1 + (flowers[0]-1)/3 + (flowers[1]-1)/3 + (flowers[2]-1)/3;
    if(flowers[0])
        ans3= 2 +  (flowers[0]-2)/3 + (flowers[1]-2)/3 + (flowers[2]-2)/3;

    cout<< max( ans1, max(ans2, ans3)) <<endl;
}
