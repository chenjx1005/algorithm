#include <stdio.h>
#include <math.h>

int flag_a=0,flag_b=0;

void compare(int *a,int *b)
{
        int temp;
        if(*b>*a)
        {
                temp=*a;
                *a=*b;
                *b=temp;
        }
}

void DFS(int a,int b,int tmp)
{
        int i;

        if(tmp>100)
                return;
        if(a==1&&b==1)
                flag_a=1;
        if(b==1)
                flag_b=1;
        for(i=tmp;i<=100;i++)
        {
                if(a%i==0)
                        DFS(a/i,b,i+1);
                if(b%i==0)
                        DFS(a,b/i,i+1);
        }
}

void run(int a,int b)
{
        flag_a=flag_b=0;
        DFS(a,b,2);
        if(flag_a==0&&flag_b==1)
                printf("%d\n",b);
        else
                printf("%d\n",a);
}

int main()
{
        int a,b;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
                compare(&a,&b);
                run(a,b);		
        }
        return 0;
}