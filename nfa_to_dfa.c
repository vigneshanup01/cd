#include <stdio.h>

int main()
{
    int n,t[10][2][10]={0},d[20],cnt=1;
    int i,j,k,c,x,s,next,found;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(c=0;c<2;c++)
        {
            scanf("%d",&x);
            while(x--)
            {
                scanf("%d",&s);
                t[i][c][s]=1;
            }
        }

    d[0]=1;

    for(i=0;i<cnt;i++)
    {
        printf("D%d: ",i);

        for(j=0;j<n;j++)
            if(d[i]&(1<<j)) printf("q%d ",j);

        for(c=0;c<2;c++)
        {
            next=0;

            for(j=0;j<n;j++)
                if(d[i]&(1<<j))
                    for(k=0;k<n;k++)
                        if(t[j][c][k])
                            next|=1<<k;

            for(found=0;found<cnt;found++)
                if(d[found]==next) break;

            if(found==cnt) d[cnt++]=next;

            printf(" | %d->D%d",c,found);
        }
        printf("\n");
    }
}
