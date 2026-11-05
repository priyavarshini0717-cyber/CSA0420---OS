#include <stdio.h>
int main()
{
    int n, i, time = 0, completed = 0;
    int at[10], bt[10], rt[10], pr[10];
    int wt[10] = {0}, tat[10] = {0};
    int min, pos;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority of P%d: ", i+1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    while(completed < n)
    {
        min = 999;
        pos = -1;
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min)
            {
                min = pr[i];
                pos = i;
            }
        }
        if(pos == -1)
        {
            time++;
            continue;
        }
        rt[pos]--;
        time++;
        if(rt[pos] == 0)
        {
            completed++;
            tat[pos] = time - at[pos];
            wt[pos] = tat[pos] - bt[pos];
        }
    }
    printf("\nProcess\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
    return 0;
}
