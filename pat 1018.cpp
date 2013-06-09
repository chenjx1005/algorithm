#include <cstdio>
#include <string.h>
#include <vector>
#include <string>

#define INFI 0x5FFFFFFF

using namespace std;

struct station
{
        int length;
        vector<int> path;
        bool know;
        int need;
};

int CMAX,N,Sp,M,mini=0;
station S[501];
int map[501][501]={0};
int min_s = INFI,min_b = INFI;
vector<int> min_p;

void run(int next,int lasts,int lastb,vector<int> pa)
{
        pa.push_back(next);
        if(next == 0)
                if( lasts < min_s || (lasts == min_s && lastb < min_b))
                {
                        min_p = pa;
                        min_s = lasts;
                        min_b = lastb;
                }
        vector<int>::const_iterator p;
        int nows=0,nowb=lastb;
        if( (lasts + S[next].need) > 0)
                nows = lasts + S[next].need;
        if( S[next].need < 0 && ((S[next].need + lasts)<0))
                nowb = lastb - (S[next].need + lasts);
        for( p = S[next].path.begin() ; p != S[next].path.end(); p++)
        {
                run(*p,nows,nowb,pa);
        }
}

int main()
{
        int cur,i,st,ed,v;
        scanf("%d%d%d%d",&CMAX,&N,&Sp,&M);
        CMAX/=2;
        for( i = 1; i <=N; i++)
        {
                scanf("%d",&cur);
                S[i].need = CMAX - cur;
                S[i].length = INFI;
                S[i].know = false;
        }
        S[0].need = S[0].length = 0;
        S[0].know = false;
        for(i = 0; i < M; i++)
        {
                scanf("%d%d",&st,&ed);
                scanf("%d",&map[st][ed]);
                map[ed][st] = map[st][ed];
        }
        while(true)
        {
                int mini_l=INFI;
                S[mini].know = true;
                if(mini == Sp)
                        break;
                for( v = 1; v <= N; v++)
                {
                        if( map[mini][v]!=0 && !S[v].know )
                        {
                                if( S[v].length > S[mini].length + map[mini][v])
                                {
                                        //update
                                        S[v].length = S[mini].length + map[mini][v];
                                        S[v].path.clear();
                                        S[v].path.push_back(mini);
                                        
                                }
                                else if( S[v].length == S[mini].length + map[mini][v])
                                {
                                        S[v].path.push_back(mini);
                                }
                        }
                }
                for( i = 1; i <= N; i++)
                {
                        if( !S[i].know && S[i].length <mini_l )
                        {
                                mini_l = S[i].length;
                                mini= i;
                        }
                }
        }
        vector<int> pa;
         run( Sp,0,0,pa);
        printf("%d ",min_s);
        vector<int>::const_reverse_iterator p;
        for( p = min_p.rbegin();p != min_p.rend(); p++)
        {
                if(*p != Sp)
                printf("%d->",*p);
                else
                        printf("%d %d",Sp,min_b);
        }
}