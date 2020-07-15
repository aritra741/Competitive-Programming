#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

string fib[5001];

string add(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        carry = sum/10;
    }

    for (int i=n1; i<n2; i++)
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

void precalc()
{
    fib[0]="0";
    fib[1]="1";

    for(int i=2;i<=5000;i++)
        fib[i]= add( fib[i-1],fib[i-2]);
}

int main()
{
    precalc();

    int n;

    while(cin>>n)
        cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
}
