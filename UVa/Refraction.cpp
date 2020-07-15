#include <bits/stdc++.h>
using namespace std;
#define INF 1<<9

double slope(double x1,double y1,double x2,double y2)
{
    if(x1-x2==0){
        return 1000000000;
    }
    return (y1-y2)/(x1-x2);
}

int main()
{
    double W,H,x,xe,ye,mu;
    int t;
    scanf("%d",&t);

    while(t--){
        //cin>>W>>H>>x>>xe>>ye>>mu;
        scanf("%lf%lf%lf%lf%lf%lf",&W,&H,&x,&xe,&ye,&mu);

        double hl=0,hh=H,hmid;
        double ans=1000000000;

        for(int i=0;i<50;i++){
            hmid=(hl+hh)/2.00;
            bool flag=0;
            double pl=0,ph=W,pmid;

            for(int j=0;j<50;j++){
                pmid=(pl+ph)/2.00;
                double numer= (h*h+(p-x)*(p-x))/((p*x)-
                if(slope2>slope3){
                    ph=pmid;
                }else{
                    double t1=atan(ekta_slope);
                    double t2=acos(0.0)-t1;
                    double t3=asin(sin(t2)*mu);
                    double t4=acos(0.0)-t3;
                    double slope4=tan(t4);

                    if(fabs(slope4-slope3)<=1e-7){
                        ans=hmid;
                        hh=hmid;
                        flag=1;
                        break;
                    }else if(slope4>slope3){
                        pl=pmid;
                    }else if(slope4<slope3){
                        ph=pmid;
                    }
                }
            }
            if(flag==0){
                hl=hmid;
            }
        }
        if(ans==1000000000){
            printf("Impossible\n");
        }else{
            printf("%.4f\n",ans);
        }
    }
}
