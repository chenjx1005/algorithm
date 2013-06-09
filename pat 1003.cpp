#include <stdio.h>
#include <stdlib.h>

typedef struct table table;
int N,start,end;

struct table
{
        int konw;
        int dist;
        int last;
        int hands;
        int numbers;
};

int path[500][500]={0};

int findsmall(table *s)
{
        int i,min=10000,min_n=-1;
        for(i=0;i<N;i++)
        {
                if(s[i].konw!=1)
                        if(s[i].dist<min)
                        {
                                min_n=i;
                                min=s[i].dist;
                        }
        }
        return min_n;
}

void dijkstr(table *city,int hands[])
{
        int v,i;
        for(;;)
        {
                if((v=findsmall(city))==-1)
                        break;
                city[v].konw=1;
                for(i=0;i<N;i++)
                        if(path[v][i])
                                if(city[i].konw==0)
                                        if(city[i].dist>city[v].dist+path[v][i])
                                        {
                                                city[i].numbers=city[v].numbers;
                                                city[i].hands=city[v].hands+hands[i];
                                                city[i].dist=city[v].dist+path[v][i];
                                                city[i].last=v;
                                        }
                                        else if(city[i].dist==city[v].dist+path[v][i])
                                        {
                                                if(city[i].hands<city[v].hands+hands[i])
                                                        city[i].hands=city[v].hands+hands[i];
                                                city[i].numbers+=city[v].numbers;
                                        }
        }
}

void inittable(table * city,int hands[])
{
        int i;
        for(i=0;i<N;i++)
        {
                city[i].dist=10000;
                city[i].hands=hands[i];
                city[i].konw=0;
                city[i].last=-1;
                city[i].numbers=0;
        }
        city[start].dist=0;
        city[start].numbers=1;
}

int main()
{
        int x,i,a,b;
        scanf("%d%d%d%d",&N,&x,&start,&end);
        int hands[500];
        for(i=0;i<N;i++)
                scanf("%d",&hands[i]);
        for(i=0;i<x;i++)
        {
                scanf("%d%d",&a,&b);
                scanf("%d",&path[a][b]);
                path[b][a]=path[a][b];
        }
        table * city=(table *)malloc(N*sizeof(table));
        inittable(city,hands);
        dijkstr(city,hands);
        printf("%d %d\n",city[end].numbers,city[end].hands);
        return 0;
}