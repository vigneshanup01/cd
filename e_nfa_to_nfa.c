#include <stdio.h>

int main()
{
    int n, eps[10][10], closure[10][10] = {0};

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &eps[i][j]);

    // Find epsilon closure
    for(int i = 0; i < n; i++)
    {
        closure[i][i] = 1;

        for(int j = 0; j < n; j++)
            if(eps[i][j] == 1)
                closure[i][j] = 1;
    }

    // Print epsilon closure
    printf("\nEpsilon Closure:\n");
    for(int i = 0; i < n; i++)
    {
        printf("State %d: ", i);
        for(int j = 0; j < n; j++)
            if(closure[i][j])
                printf("%d ", j);
        printf("\n");
    }

    return 0;
}
