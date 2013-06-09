#include <cstdio>
#include <queue>
#include <string.h>
#include <cassert>
using namespace std;

struct customer
{
        int n;
        int eh;
        int em;
        int process;
};
struct window
{
        int line;
        int eh;
        int em;
        bool operator < (const window &b)const
        {
                if(eh > b.eh)
                        return true;
                else if(eh == b.eh && em > b.em)
                        return true;
                else if(eh == b.eh && em==b.em && line > b.line)
                        return true;
                return false;
        }
};

queue <customer> Qu[20];
priority_queue <window> W;
customer C[1002];
int N,M,K,Q;
int main()
{
        int i,j,min=1;
        customer cu;
        window win;
        memset(C,0,sizeof(C));
        scanf("%d%d%d%d",&N,&M,&K,&Q);
        for( i = 1; i <= K; i++)
        {
                scanf("%d",&C[i].process);
                C[i].n=i;
        }
        for( i= 0 ; i < M; i++)
                for( j = 0; j < N; j++)
                {
                        if(min > K)
                                break;
                        Qu[j].push(C[min++]);
                }
        for( i = 0 ; i < N; i++)
        {
                if(!Qu[i].empty())
                {
                        win.em=Qu[i].front().process;
                        win.eh=8+win.em/60;
                        win.em%=60;
                        win.line=i;
                        W.push(win);
                }
        }
        while(!W.empty())
        {
                int line;
                win=W.top();
                line=win.line;
                W.pop();
                cu=Qu[line].front();
                cu.eh=win.eh;
                cu.em=win.em;
                                assert(win.eh <= 17 && win.eh >=8);
                C[cu.n]=cu;
                Qu[line].pop();
                                if(min <= K)
                                        Qu[line].push(C[min++]);
                if(win.eh < 17)
                {
                        if(!Qu[line].empty())
                        {	
                                win.em+=Qu[line].front().process;
                                win.eh+=win.em/60;
                                win.em%=60;
                                W.push(win);
                        }
                }
        }
        for(i = 0; i < Q; i++)
        {
                int q;
                scanf("%d",&q);
                if(C[q].eh!=0)
                        printf("%02d:%02d\n",C[q].eh,C[q].em);
                else
                        printf("Sorry\n");
        }
}