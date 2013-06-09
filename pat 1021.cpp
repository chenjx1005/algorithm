#include <cstdio>
#include <cstdlib>
#include <list>
#include <cstring>

using namespace std;

int N;
int visit[10001]={0};
list<int> G[10001];

int dfs(int i)
{
        int max = 0 , temp;
        visit[i] = 1;
        list<int>::const_iterator p;
        for( p = G[i].begin() ; p != G[i].end(); p++)
        {
                if( !visit[*p] )
                {
                        temp = dfs(*p);
                        if( temp > max)
                                max = temp;
                }
        }
        return max + 1;
}

int main()
{
        int i,a,b,components=0;
        scanf("%d",&N);
        for( i= 0 ; i < N-1 ; i++)
        {
                scanf("%d%d",&a,&b);
                G[a].push_back(b);
                G[b].push_back(a);
        }
        for( i = 1 ; i <= N ; i++)
        {
                if( !visit[i] )
                {
                        dfs(i);
                        components++;
                }
        }
        if(components != 1)
        {
                printf("Error: %d components",components);
                return 0;
        }
        list<int> maxnodes;
        int max = 0;
        for( i =1 ; i <= N ; i++)
        {
                memset(visit,0,sizeof(visit));
                int temp = dfs(i);
                if( temp > max)
                {
                        maxnodes.clear();
                        maxnodes.push_back(i);
                        max = temp;
                }
                else if( temp == max)
                {
                        maxnodes.push_back(i);
                }
        }
        maxnodes.sort();
        list<int>::const_iterator pos;
        for( pos = maxnodes.begin() ; pos != maxnodes.end() ; pos++)
        {
                printf("%d\n",*pos);
        }
}