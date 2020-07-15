#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s,t;
string dp[10007][107];
int vis[10007][107];
int n,m,p;

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        // Calculate carry for next step
        carry = sum/10;
    }

    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}


string rec( int i, int j )
{
    if( j>=m )
        return "1";
    if( i>=n )
        return "0";
    if( vis[i][j]==p )
        return dp[i][j];

    string ret= "0";

    if( s[i]==t[j] )
        ret= rec( i+1, j+1 );
    ret= findSum(ret,rec( i+1, j ));

    vis[i][j]= p;

    return dp[i][j]= ret;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>s>>t;

        n= s.size();
        m= t.size();

        p++;
        cout<< rec( 0, 0 ) <<endl;
    }
}
