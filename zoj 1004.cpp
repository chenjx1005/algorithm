#include <stdio.h>
#include <string.h>

char s[50];
char t[50];
char op[100];

int length_s,length_t=0;

void DFS(int n);
int operat(int n);

int main()
{
        int i=0,j=0;

        while(1)
        {
                if(scanf("%c",&s[i++])==EOF)
                        break;
                else
                {
                        while(scanf("%c",&s[i])&&s[i]!='\n')
                                i++;
                }
                while(scanf("%c",&t[j])!=EOF&&t[j]!='\n')
                j++;
                length_s=i;
                length_t=j;
                i=j=0;
                printf("[\n");
                DFS(0);
                printf("]\n");
        }

        return 0;
}

void DFS(int n)
{
        int over;

        over=operat(n);
        if(over)
                return;
        op[n]='i';
        DFS(n+1);
        op[n]='o';
        DFS(n+1);
}

int operat(int n)
{
        char stack[50];
        char gen[50];
        int i,stack_i=0,gen_i=0,s_i=0;

        if(n>2*length_s)
                return 1;
        for(i=0;i<n;i++)
        {
                if(op[i]=='i')
                {
                        if(s_i==length_s)
                                return 1;
                        stack[stack_i++]=s[s_i++];
                }
                else
                {
                        if(stack_i==0)
                                return 1;
                        gen[gen_i++]=stack[--stack_i];
                }
        }
        
        if(gen_i==length_t)
        {
                if(!(strncmp(gen,t,length_t)))
                {
                        for(i=0;i<n;i++)
                                printf("%c ",op[i]);
                        printf("\n");
                }
        }

        return 0;
}