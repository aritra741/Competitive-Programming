#include <bits/stdc++.h>
using namespace std;

int main()
{
    int indexl=-1;
    int indexr=-1;
    bool flagl=0;
    bool flagr=0;
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n,q;
        scanf("%d %d", &n, &q );
        int arr[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d", &arr[j]);
        }
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++)
        {
            int q1,q2;
            flagl=0;
            flagr=0;
            scanf("%d %d", &q1, &q2);
            int r=n-1;
            int l=0;
            indexl=-1;
            indexr=-1;

            while(l<=r)
            {
                int mid=l+(r-l)/2;
              //  cout<<mid<<endl;
                //cout<<l<<" "<<mid<<" "<<r<<endl;

                if(arr[mid]>=q1)
                    {
                        flagl=1;
                        r=mid;
                        indexl=l;
                        if(l==r)
                        break;
                    }
                else
                {
                    l=mid+1;
                }
            indexl=l;

            }
            r=n-1;
            l=0;
            while(l<=r)
            {

                int mid=l+(r-l+1)/2;
                //cout<<mid<<endl;
                if(arr[mid]<=q2)
                {

                    flagr=1;
                    l=mid;
                    indexr=l;
                    if(l==r)
                        break;
                }
                else
                    r=mid-1;
                indexr=l;
            }
            //cout<<indexl<<" "<<indexr<<endl;
            int result=indexr-indexl;
            if(flagl==0 || flagr==0)
                printf("0\n");
            else{
            //if(q1!=q2)
                result++;

printf("%d\n",result);
            }
        }


    }

}
