#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);

    int money[n+1], cnt = 1, cnt_max=0;

    for(i=0; i<n; i++){
        scanf("%d", &money[i]);
    }
    money[n] = 0;

    for(i=0; i<n; i++){
        if(money[i] <= money[i+1]){
            cnt++;
        }
        else if(money[i] > money[i+1]){
            if(cnt_max <= cnt){
                cnt++;
                cnt_max = cnt;
                cnt = 0;
            }
        }
    }

    printf("%d\n", cnt_max);
    return 0;
}
