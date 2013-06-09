#include <stdio.h>
#include <string.h>
int map[1001][1001]={0};
int tmp[1001][1001]={0};
int search[1001]={0};
int N,M,K,sa;
int link(int a, int b)
{
  int i,flag=(a==b);
  search[a]=1;
  for(i = 1; i <= N; i++)
  {
    if( search[i]==0 && map[a][i] != 0 && i!=sa)
    {
      if(link(i,b))
        flag=1;
    }
  }
  return flag;
}

int main()
{
  int i,a,b,number,j,k,last,count;
  scanf("%d%d%d",&N,&M,&K);
  for(i = 0; i < M; i++)
  {
    scanf("%d %d",&a,&b);
    map[a][b]=map[b][a]=tmp[a][b]=tmp[b][a]=1;
  }
  for(i = 0; i < K; i++)
  {
        number=0;
        memset(search,0,sizeof(search));
    for(j = 1; j <= N; j++)
      for(k =1; k < j; k++)
        map[j][k]=map[k][j]=tmp[j][k];
    scanf("%d",&sa);
        int start= sa==1?2:1;
        last=start;
        for(j = start+1; j <= N ; j++)
        {
                if(search[j] == 1 || j==sa)
                        continue;
                if( !link(start,j) )
                {
                        map[start][j]=map[j][start]=1;
                        number++;
                }
        }
    printf("%d\n",number);
  }
  return 0;
}