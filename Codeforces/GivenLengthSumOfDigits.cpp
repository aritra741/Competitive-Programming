#include <bits/stdc++.h>
using namespace std;
int main()
{
    int dig,sum;
    cin>>dig>>sum;
    string s="",s1="";
    int i=0;
    int temp=sum;
    if(sum>9*dig || dig==0 || (sum==0 && dig>1))
        cout<<"-1 -1";
    else
    {
        while(i<dig)
        {
            if(sum==0 && i<dig)
            {
                s.insert(s.begin()+i, '0');
                i++;

            }
            else if(sum>=9)
            {

                sum-=9;
                s.insert(s.begin()+i, '9');
                i++;
            }
            else
            {

                s.insert(s.begin()+i, sum+'0');
                sum-=sum;
                i++;
            }

        }
        i=dig;
        int p=0;
        while(i>0)
        {
            if(temp==0 && i>0)
            {
                s1.insert(s1.end(),i, '0');
                i=0;
                p++;
            }
            else
            {
                int t=ceil( (double)temp/9 );

                    if(i>t && p!=0 && temp<=9*(i))
                    {

                        s1.insert(s1.end(),i-t, '0');


                        p=p+i-t;i=t;

                    }
                    // cout<<dig<<" "<<i<<" "<<temp<<endl;
                    else
                    {
                        for(int j=1; j<=9; j++)
                        {
                            // cout<<temp<<" "<<j<<endl;
                            if(temp-j<= 9*(i-1))
                            {
                                temp-=j;
                                //cout<<dig<<" "<<i<<" "<<temp<<endl;
                                s1.insert(s1.begin()+p, j+'0');
                                i--;
                                p++;
                                break;
                            }
                        }
                    }
                }

            }


        }
        cout<<s1<<" "<<s;
    }


