#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;

    deque<char> dq;

    bool turn= (n&1)?1:0;

    for(int i=0;i<n;i++)
    {
        if(turn)
            dq.push_back(s[i]), turn= 0;
        else
            dq.push_front(s[i]), turn= 1;
    }

    for(int i=0;i<n;i++)
        cout<< dq[i] ;
}
