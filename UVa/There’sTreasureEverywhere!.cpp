#include <bits/stdc++.h>
#define d sqrt(2)/2
using namespace std;
int main()
{
    string s;
    int i=1;
    while( getline(cin, s) )
    {
        if(s=="END")
            break;
        cout<<"Map #"<<i++<<endl;
        double x=0;
        double y=0;
        stringstream ss;
        ss<<s;
        string t="";
        while( getline( ss, t,',' ) )
        {
            int step=stoi(t);
            if(t[t.length()-1]=='.')
                t.erase(t.end()-1);
            string dir="";
            for(int i=0;i<t.length();i++)
                if( (t[i]<'0' || t[i]>'9') && t[i]!='.'  )
                    dir.insert(dir.end(),t[i]);
           if(dir.length()==1)
           {
               if(dir[0]=='S')
               {
                    y-=step;
               }
            if(dir[0]=='N')
               {
                    y+=step;
               }
            if(dir[0]=='E')
               {
                    x+=step;
               }
            if(dir[0]=='W')
               {
                    x-=step;
               }
           }
           else if(dir.length()==2)
           {
               if(dir=="NE")
               {
                   x+=(d*step);
                   y+=(d*step);
               }
           if(dir=="SW")
               {
                   x-=(d*step);
                   y-=(d*step);
               }
           if(dir=="SE")
               {
                    x+=(d*step);
                    y-=(d*step);
               }
           if(dir=="NW")
               {
                    x-=(d*step);
                    y+=(d*step);
               }
           }

        }
        cout<<"The treasure is located at ("<<setprecision(3)<<fixed<<x<<","<<setprecision(3)<<fixed<<y<<")."<<endl;
        double dist= sqrt (x*x + y*y);
        cout<<"The distance to the treasure is "<<setprecision(3)<<fixed<<dist<<"."<<endl;
        cout<<endl;
    }
}
