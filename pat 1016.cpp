#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
        char name[21];
        int month;
        int day;
        int hour;
        int minute;
        char flag[10];
}record;

record r[1000];
int rate[24],N;

int comp(const void * a,const void *b)
{
        record *pa = (record *)a;
        record *pb = (record *)b;
        int res = strcmp(pa->name,pb->name);
        if(res!=0)
                return res;
        res = pa->day - pb->day;
        if(res!=0)
                return res;
        res= pa->hour - pb->hour;
        if(res!=0)
                return res;
        res= pa->minute - pb->minute;
        return res;
}

void run()
{
        int i=0,amount=0,flag=0;
        record now,next;
        char name[21];
        strcpy(name,r[0].name);
        
        while( 1)
        {
                now=r[i++];
                if(strcmp(now.name,name)!=0)
                {
                        if(amount) printf("Total amount: $%.2f\n",amount/100.0);
                        amount=0;
                        flag=0;
                        strcpy(name,now.name);
                }
                if(i >= N)
                        break;
                next=r[i];
                if( strcmp(next.name,now.name)==0 && strcmp(next.flag,"off-line")==0 && strcmp(now.flag,"on-line")==0)
                {
                                if(flag==0)
                                {
                                        printf("%s %02d\n",now.name,now.month);
                                        flag=1;
                                }
                                int j,k,d1=now.day,d2=next.day,h1=now.hour,h2=next.hour,m1=now.minute,m2=next.minute;
                                int money,time;
                                if(d1==d2)
                                {
                                        if(h1==h2)
                                        {
                                                time=m2-m1;
                                                money=(m2-m1)*rate[h1];
                                        }
                                        else
                                        {
                                                money=(60-m1)*rate[h1]+m2*rate[h2];
                                                time=60-m1+m2+(h2-h1-1)*60;
                                                for(j=h1+1;j<h2;j++)
                                                        money+=rate[j]*60;
                                        }
                                }
                                else
                                {
                                        time=60-m1+(23-h1)*60+h2*60+m2+(d2-d1-1)*24*60;
                                        for(j=d1;j<=d2;j++)
                                        {
                                                if(j==d1)
                                                {
                                                        money=rate[h1]*(60-m1);
                                                        for(k=h1+1;k<24;k++)
                                                                money+=rate[k]*60;
                                                }
                                                else if (j==d2)
                                                {
                                                        money+=rate[h2]*m2;
                                                        for(k=0;k<h2;k++)
                                                                money+=rate[k]*60;
                                                }
                                                else
                                                        for(k=0;k<24;k++)
                                                                money+=rate[k]*60;
                                        }
                                }
                                amount+=money;
                                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",d1,h1,m1,d2,h2,m2,time,money/100.0);
                }
        }
        if(amount) printf("Total amount: $%.2f\n",amount/100.0);
}

int main()
{
        int i;
        for( i = 0;i<24;i++)
                scanf("%d",&rate[i]);
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
                getchar();
                scanf("%s %d:%d:%d:%d %s",&r[i].name,&r[i].month,&r[i].day,&r[i].hour,&r[i].minute,&r[i].flag);
        }
        qsort(r,N,sizeof(record),comp);
        run();
        return 0;
}