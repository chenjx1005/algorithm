#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people
{
        char name[9];
        int age;
        int worth;
}people;

people a[100000];
int N,K;
int agecount[201]={0};
int index1[100000];

int comp(const void *a,const void *b)
{
        people *pa=(people *)a;
        people *pb=(people *)b;
        int r;

        if( (r=pb->worth-pa->worth) != 0 ) 
                return r;
        
        if((r=pa->age-pb->age)!=0)
                return r;
        
        return strcmp(pa->name,pb->name);
}

int main()
{
        int i,m,amin,amax,j,count,k,all,n2=0;
        scanf("%d%d",&N,&K);
        for(i = 0; i < N; i++)
        {
                getchar();
                scanf("%s %d%d",a[i].name,&a[i].age,&a[i].worth);
        }
        qsort(a,N,sizeof(people),comp);
        for(i = 0; i < N; i++)
                if(++agecount[a[i].age]<=100)
                        index1[n2++]=i;
                        
        for(i = 0; i < K; i++)
        {
                scanf("%d%d%d",&m,&amin,&amax);
                all=0;
                for(k = amin; k <= amax ; k++)
                        all+=agecount[k];
                printf("Case #%d:\n",i+1);
                count=0;
                m = all < m ? all : m;
                if(all != 0)
                {
                        for(j = 0; j < n2; j++)
                        {
                                if(a[index1[j］.age <= amax && a[index1[j］.age >= amin)
                                {
                                        if(++count <= m)
                                                printf("%s %d %d\n",a[index1[j］.name,a[index1[j］.age,a[index1[j］.worth);
                                        else
                                                break;
                                }
                        }
                }
                if(count == 0)
                        printf("None\n");
        }
        return 0;
}