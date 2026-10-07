#include <stdio.h>

#define MAX 10

int n, e[MAX][MAX], a[MAX][MAX], b[MAX][MAX];

void closure(int s, int c[])
{
    c[s] = 1;

    for(int i=0; i<n; i++)
        if(e[s][i] && !c[i])
            closure(i, c);
}

void move(int s, int x[][MAX], int ans[])
{
    int c[MAX] = {0};

    closure(s, c);

    for(int i=0; i<n; i++)
        if(c[i])
            for(int j=0; j<n; j++)
                if(x[i][j])
                    ans[j] = 1;
}

int main()
{
    printf("Enter number of states: ");
    scanf("%d",&n);

    printf("Enter epsilon matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&e[i][j]);

    printf("Enter a matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter b matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&b[i][j]);

    printf("\nNFA without epsilon:\n");

    for(int i=0;i<n;i++)
    {
        int A[MAX]={0}, B[MAX]={0};

        move(i,a,A);
        move(i,b,B);

        printf("q%d --a--> ",i);
        for(int j=0;j<n;j++)
            if(A[j]) printf("q%d ",j);

        printf("\nq%d --b--> ",i);
        for(int j=0;j<n;j++)
            if(B[j]) printf("q%d ",j);

        printf("\n");
    }

    return 0;
}
