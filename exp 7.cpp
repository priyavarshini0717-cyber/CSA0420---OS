
#include <stdio.h>

int main()
{
    int n, i, t = 0, done = 0, p;
    int at[10], bt[10], wt[10], tat[10], flag[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT: ");
        scanf("%d%d", &at[i], &bt[i]);
    }

    while(done < n)
    {
        p = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= t && flag[i] == 0)
            {
                if(p == -1 || bt[i] < bt[p])
                    p = i;
            }
        }

        if(p == -1)
        {
            t++;
            continue;
        }

        wt[p] = t - at[p];
        t += bt[p];
        tat[p] = t - at[p];
        flag[p] = 1;
        done++;
    }

    printf("\nProcess\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);

    return 0;
}
