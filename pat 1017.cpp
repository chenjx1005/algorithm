#include <cstring>
#include <queue>
#include <string>
using namespace std;

struct window
{
        int h;
        int m;
        int s;
        bool operator <(const window &a)const
        {
                if(a.h<h)
                        return true;
                else if(a.h==h && a.m<m)
                        return true;
                else if(a.h==h && a.m==m && a.s<s)
                        return true;
                return false;
        }
};

struct customer
{
        int h;
        int m;
        int s;
        int process;
        bool operator <(const customer &a)const
        {
                if(a.h<h)
                        return true;
                else if(a.h==h && a.m<m)
                        return true;
                else if(a.h==h && a.m==m && a.s<s)
                        return true;
                return false;
        }
};

int main()
{
        int N,K,i;
        double wait=0;
        window win={8,0,0};
        customer cu;
        priority_queue<window> W;
        priority_queue<customer> C;
        scanf("%d%d",&N,&K);
        for(i=0;i<N;i++)
        {
                scanf("%d:%d:%d %d",&cu.h,&cu.m,&cu.s,&cu.process);
                if(cu.h<17 || (cu.h==17 && cu.m==0 && cu.s==0))
                        C.push(cu);
        }
        N=C.size();
        if(N == 0)
        {
                printf("0.0");
                return 0;
        }
        for(i=0;i<K;i++)
                W.push(win);
        while(!C.empty())
        {
                win=W.top();
                W.pop();
                cu=C.top();
                C.pop();
                if(cu.h<win.h || (cu.h==win.h && cu.m<win.m) || (cu.h==win.h && cu.m==win.m && cu.s<win.s))
                {
                        wait+=(win.h-cu.h)*60 + win.m-cu.m + (win.s-cu.s)/60.0;
                        win.m+=cu.process;
                        win.h+=win.m/60;
                        win.m%=60;
                        W.push(win);
                }
                else
                {
                        win.s=cu.s;
                        win.m=cu.m+cu.process;
                        win.h+=win.m/60;
                        win.m%=60;
                        W.push(win);
                }
        }
        printf("%.1f",wait/N);
}