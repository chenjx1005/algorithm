#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode treenode; 

struct treenode
{
        int firstchild;
        int sibling;
};

treenode T[100];
int n,m,maxlevel=1;
int numbers[100]={0};


void DFS(int i,int level)
{
        if(level>maxlevel)
                maxlevel=level;
        if(T[i].firstchild==0)
                numbers[level]++;
        else
                DFS(T[i].firstchild,level+1);
        if(T[i].sibling!=0)
                DFS(T[i].sibling,level);
}

int main()
{
        int i,j;
        int pa,k,fi,si;
        memset(T,0,sizeof(T));
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
                scanf("%d%d%d",&pa,&k,&fi);
                T[pa].firstchild=fi;
                for(j=1;j<k;j++)
                {
                        scanf("%d",&si);
                        T[fi].sibling=si;
                        fi=si;
                }
        }
        DFS(1,1);
        for(i=1;i<maxlevel;i++)
                printf("%d ",numbers[i]);
        printf("%d",numbers[maxlevel]);
        return 0;
}