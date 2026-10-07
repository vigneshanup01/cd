#include <stdio.h>

int main()
{
    int n, e[10][10], a[10][10], b[10][10];
    int c[10][10] = {0}, na[10][10] = {0}, nb[10][10] = {0};

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&e[i][j]);

    printf("Enter 'a' transition matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter 'b' transition matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&b[i][j]);

    // Find epsilon closure
    for(int i=0;i<n;i++)
    {
        c[i][i]=1;

        for(int j=0;j<n;j++)
            if(e[i][j])
                c[i][j]=1;
    }

    // Create NFA transitions for a and b
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(c[i][j])
            {
                for(int k=0;k<n;k++)
                {
                    if(a[j][k])
                        na[i][k]=1;

                    if(b[j][k])
                        nb[i][k]=1;
                }
            }

    printf("\nNFA without epsilon:\n");

    for(int i=0;i<n;i++)
    {
        printf("q%d --a--> ",i);
        for(int j=0;j<n;j++)
            if(na[i][j])
                printf("q%d ",j);

        printf("\nq%d --b--> ",i);
        for(int j=0;j<n;j++)
            if(nb[i][j])
                printf("q%d ",j);

        printf("\n");
    }

    return 0;
}
