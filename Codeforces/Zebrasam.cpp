#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    bool flag=0;
    string s;
    cin>>s;
    int cnt=0;
    int arr[s.length()];
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<s.length(); i++)
        if(s[i]=='0')
            if(arr[i]==0)
            {
                arr[i]=1;
                for(int j=i+1; j<s.length(); j++)
                    if(s[j]=='1')
                        if(arr[j]==0)
                        {
                            arr[j]=1;
                            for(int k=j+1; k<s.length(); k++)
                                if(s[k]=='0')
                                    if(arr[k]==0)
                                    {
                                        arr[k]=1;
                                        cnt++;

                                    }
                        }
            }
            cout<<cnt;
}
