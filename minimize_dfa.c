#include <stdio.h>
#define MAX 10

int main()
{
    int n, m, t[MAX][2], f[MAX];
    int mark[MAX][MAX] = {0};
    int i, j, k, a, x, y;

    printf("Enter states and symbols: ");
    scanf("%d%d", &n, &m);

    printf("Enter transition table:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&t[i][j]);

    printf("Enter final states (1/0):\n");
    for(i=0;i<n;i++)
        scanf("%d",&f[i]);

    // Mark final/non-final pairs
    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            if(f[i]!=f[j])
                mark[i][j]=1;

    // Check transitions
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
                if(!mark[i][j])
                    for(a=0;a<m;a++)
                    {
                        x=t[i][a];
                        y=t[j][a];

                        if(x!=y && mark[x][y])
                        {
                            mark[i][j]=1;
                            break;
                        }
                    }

    printf("\nEquivalent states:\n");
    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            if(!mark[i][j])
                printf("q%d = q%d\n",i,j);

    printf("\nDistinguishable states:\n");
    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            if(mark[i][j])
                printf("q%d != q%d\n",i,j);

    return 0;
}
