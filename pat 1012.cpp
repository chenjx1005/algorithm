#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
        int flag;
        int c;
        int m;
        int e;
        int a;
}stu;

stu student[1000000]={0};
int a[102]={0},c[102]={0},m[102]={0},e[102]={0};
int ra[102]={0},rc[102]={0},rm[102]={0},re[102]={0};

int main()
{
        int N,M,i,id,min;
        char s;
        scanf("%d %d",&N,&M);
        for( i = 0; i < N; i++)
        {
                scanf("%d",&id);
                student[id].flag=1;
                scanf("%d%d%d",&student[id].c,&student[id].m,&student[id].e);
                student[id].a = ( student[id].c + student[id].m + student[id].e) / 3;
                a[student[id].a]++;
                c[student[id].c]++;
                m[student[id].m]++;
                e[student[id].e]++;
        }
        
        for(i = 100; i >=0 ; i--)
        {
                a[i]+=a[i+1];
                ra[i]=a[i+1]+1;
                c[i]+=c[i+1];
                rc[i]=c[i+1]+1;
                e[i]+=e[i+1];
                re[i]=e[i+1]+1;
                m[i]+=m[i+1];
                rm[i]=m[i+1]+1;
        }
        for( i = 0; i < M; i++)
        {
                scanf("%d",&id);
                if(student[id].flag==0)
                        printf("N/A\n");
                else
                {
                        s='A';
                        min=ra[student[id].a];
                        if(rc[student[id].c]<min)
                        {
                                min=rc[student[id].c];
                                s='C';
                        }
                        if(rm[student[id].m]<min)
                        {
                                min=rm[student[id].m];
                                s='M';
                        }
                        if(re[student[id].e]<min)
                        {
                                min=re[student[id].e];
                                s='E';
                        }
                        printf("%d %c\n",min,s);
                }
        }
        return 0;
}