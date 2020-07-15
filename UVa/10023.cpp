#include<bits/stdc++.h>
using namespace std;

string s,mid,por;

string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";

    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

string division(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx)
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    int carry = 0;

    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}

bool ok()
{
    if( s.size()<por.size() )
        return 0;
    if( s.size()>por.size() )
        return 1;

    for( int i=0;i<s.size();i++ )
    {
        if( s[i]<por[i] )
            return 0;
        if( s[i]>por[i] )
            return 1;
    }
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>s;
        string low= "1", high= s;

        string ans;

        for( int i=0;i<3500;i++ )
        {
            mid= findSum(low,high);
            mid= division(mid,2);

            por= multiply( mid, mid );

//            cout<<mid<<" "<<por<<endl;

            if(por==s)
            {
                ans= mid;
                break;
            }

            if( ok() )
                low= mid;
            else
                high= mid;
        }

        cout<< ans <<endl;

        if(tc)
            cout<<endl;
    }
}
