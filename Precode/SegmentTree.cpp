/* Segment Tree for Range Sum Query */
#include <bits/stdc++.h>
using namespace std;
int constructUtil(int arr[], int l, int r, int *st, int current)
{
    if(l==r)
    {
        st[current]=arr[l]; //Leaf Node
        return arr[l];
    }
    int mid=l+(r-l)/2;    //mid toh mid. eitar jonne comment laage na
    st[current]= constructUtil(arr, l, mid, st, current*2+1) +
                 constructUtil(arr, mid+1, r, st, current*2+2);   //0 based index
    return st[current];
}
int *constructST(int arr[],int n)
{
    int x=(int)(ceil(log2(n)));   //Height of Segment Tree
    int mx= 2*(int)pow(2,x)-1;     //Maximum Size of Segment Tree
                                  //Hudai pow function nilam :p
    int *st= new int[mx];          //Allocate memory
                                  //st is a pointer to an array, and that array is the constructed Segment Tree
   constructUtil(arr, 0, n-1, st, 0); //Build Branches
   //The segment Tree has been built. Now we need to return the tree
   return st;
}

int getsum(int *st, int l, int r, int ql, int qr, int current)
{
    if(ql>r || qr<l)        //completely out of range
        return 0;
    if(l>=ql && r<=qr)      //completely inside range
        return st[current];
    int mid= l+(r-l)/2;
    return getsum(st, l, mid, ql, qr, current*2+1)+
           getsum(st, mid+1, r, ql, qr, current*2+2);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *st=constructST(arr, n);
    int q,ql,qr;
    cin>>q;
    while(q--)
    {
    cin>>ql>>qr;
    int ans=getsum(st,0,n-1,ql,qr,0);
    cout<<ans<<endl;
    }

}
