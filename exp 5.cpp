
#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int p[20], pr[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter priority of P%d: ", p[i]);
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nExecution Order:\n");
    for(i = 0; i < n; i++)
        printf("P%d (Priority %d)\n", p[i], pr[i]);

    return 0;
}
