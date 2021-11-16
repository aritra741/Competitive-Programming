#include <bits/stdc++.h>
using namespace std;

void  RoundRobin(int qt);

int main()
{
    int i, n;

    printf("\nChoose the user: \n1.System process\n2.User process" << endl;
    printf( "Enter your choice: ";
    cin >> n;

    if(n==1)
        RoundRobin(5);
    else if(n==2)
        RoundRobin(2);


    return 0;
}


void  RoundRobin(int qt)
{
    int n, i, cnt = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];

    float awt = 0, atat = 0;

    printf("Enter the number of processes : ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        printf("Process " << i << ": ";
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }

    while(1)
    {
        for(i = 0, cnt = 0; i < n; i++)
        {
            temp = qt;
            if(rem_bt[i] == 0)
            {
                cnt++;
                continue;
            }
            if(rem_bt[i] > qt)
            {
                rem_bt[i] = rem_bt[i]-qt;
            }
            else
            {
                if(rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
            }
            sq += temp;
            tat[i] = sq;
        }

        if(n == cnt)
        {
            break;
        }

    }

    printf("\nProcessID\tBT\tWT\tTAT\n";

    for(i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat+tat[i];
        printf("\nP%d\t\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    awt = awt / n;
    atat = atat / n;

    printf( << "\nAverage Waiting Time: " << awt << endl;
    printf( << "Average Turnaround Time: " << atat << endl;
}