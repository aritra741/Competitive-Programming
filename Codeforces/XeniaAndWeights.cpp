#include <bits/stdc++.h>
using namespace std;
vector <int> seq;
string s;

bool possible(int n, int balance, int weight, int step)
{

    if(step>=n)
        return 1;
    bool flag=0;

    for(int i=0;i<10;i++)
    {
        if( (s[i]-'0') and weight!=i+1 and i+1>balance)
        {
            flag=possible(n, i+1-balance,i+1, step+1);
        }

        if(flag){
            seq.push_back(i+1);
            return 1;
        }

    }

    return 0;
}

int main()
{

    int n;
    cin>>s;
    cin>>n;
    bool ans= possible(n, 0, 0, 0);
    if(ans)
    {
        reverse(seq.begin(), seq.end());
        cout<<"YES"<<endl;
        for(int i=0;i<seq.size();i++)
            cout<<seq[i]<<" ";
    }

    else
        cout<<"NO";
}
