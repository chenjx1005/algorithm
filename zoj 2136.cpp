#include <stdio.h>

int main()
{
        int re,rei;
        int N,i,j;
        int a[1000],max[1000],maxn;
        scanf("%d",&re);
        for(rei=0;rei<re;rei++)
        {
                scanf("%d",&N);
                for(i=0;i<N;i++)
                {
                        scanf("%d",&a[i]);
                        max[i]=1;
                }
                for(i=N-1;i>=0;i--)
                        for(j=i+1;j<N;j++)
                                if(a[i]<a[j])
                                        if(max[j]+1>max[i])
                                                max[i]=max[j]+1;
                maxn=1;
                for(i=0;i<N;i++)
                        if(max[i]>maxn)
                                maxn=max[i];
                printf("%d\n",maxn);
                if(rei!=re-1)
                        printf("\n");
        }

        return 0;
}