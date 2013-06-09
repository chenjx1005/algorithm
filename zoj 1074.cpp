#include <stdio.h>
#include <string.h>

int N;
int arr[100][100];
int sum[100];

/*void run()
{
        int left,right,i,j,li,lj,ri,rj;
        int sum=0,max=0;
        for(left=0;left<N*N;left++)
        {
                li=left/N;
                lj=left%N;
                for(right=left;right<N*N;right++)
                {
                        sum=0;
                        ri=right/N;
                        rj=right%N;
                        for(i=li;i<=ri;i++)
                                for(j=lj;j<=rj;j++)
                                {
                                        sum+=arr[i][j];
                                        if(sum>max)
                                                max=sum;
                                }
                }
        }
        printf("%d\n",max);
}*/

void run()
{
        int i,j,k,length;
        int max=-1270000;
        for(i=0;i<N;i++)
                for(j=i;j<N;j++)
                {
                        memset(sum,0,sizeof(sum));
                        for(k=0;k<N;k++)
                                for(length=i;length<=j;length++)
                                        sum[k]+=arr[length][k];
                        max=sum[0]>max?sum[0]:max;
                        for(k=1;k<N;k++)
                        {
                                sum[k]+=sum[k-1]>0?sum[k-1]:0;
                                if(sum[k]>max)
                                        max=sum[k];
                        }
                }
        printf("%d\n",max);
}

int main()
{
        int i,j;
        while(scanf("%d",&N)!=EOF)
        {
                for(i=0;i<N;i++)
                        for(j=0;j<N;j++)
                                scanf("%d",&arr[i][j]);
                run();
        }
        return 0;
}