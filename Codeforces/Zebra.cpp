#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    bool flag=0;
    string s;
    cin>>s;
    int arr[s.length()];
    int cnt=0;
    for(int i=0; i<s.length(); i++)
        if(s[i]=='0')
        {
            flag=1;
            arr[cnt]=i+1;
            cnt++;

    }
    if(flag==0)
        cout<<"-1";
    else{cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<"1 "<<arr[i]<<endl;}


}

