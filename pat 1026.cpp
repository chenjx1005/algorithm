//最后一个case超时。。。。。
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <assert.h>
using namespace std;

struct player
{
        string arrive;
        string leave;
        int playtime;
		bool vip;
        bool operator < (const player &b) const
        {
                if( arrive > b.arrive)
                        return true;
                return false;
        }
};

int N,K,M;
priority_queue<player> P_coming;
list<player> P_wait;
int tacount[120]={0};
list<player> finish;
string table[101];
int viplist[101];

string leavetime(const string &start,int playtime)
{
        int h,m;
        m = atoi(start.substr(3,2).c_str()) ;
        m += playtime;
        h = atoi(start.substr(0,2).c_str()) + m/60;
        m %= 60;
        char hh[10],mm[10];
        sprintf(hh,"%02d",h);
        sprintf(mm,"%02d",m);
        string sh = hh,sm = mm;
        string s =  sh+ ':' + sm +':' + start.substr(6,2);
        return s;
}

int waittime(const string &a,const string &b)
{
        int h = atoi(b.substr(0,2).c_str()) - atoi(a.substr(0,2).c_str());
        int m = atoi(b.substr(3,2).c_str()) - atoi(a.substr(3,2).c_str());
        int s = atoi(b.substr(6,2).c_str()) - atoi(a.substr(6,2).c_str());
        int waittime = h * 60 + m;
        if( s > 0)
                waittime++;
        return waittime;
}

int main()
{
        int i,isvip;
        player pl;
        cin >> N;
        for( i = 0 ; i < N ; i++)
        {
				cin >> pl.arrive >> pl.playtime >> pl.vip;
                if( pl.playtime > 120)
                        pl.playtime = 120;
                if( pl.arrive >="21:00:00" )
                        continue;
				P_coming.push(pl);
        }
        cin >> K >> M;
        for( i = 1 ; i <= K ; i++)
			table[i] = "08:00:00";
        for( i = 0 ; i< M ; i++)
			cin >> viplist[i];
		string now = "08:00:00";
        while(now != "21:00:00")
        {
			if( P_wait.empty() && P_coming.empty())
				break;
			while(!P_coming.empty() && P_coming.top().arrive <= now)
			{
				P_wait.push_back(P_coming.top());
				P_coming.pop();
			}
			list<player>::iterator pos = P_wait.begin();
			while( pos != P_wait.end() )
			{
				int stop = 0,find = 1,next = 1;
				if(pos->vip)
				{
					find = 0;
					for( int j = 0 ; j < M; j++)
					{
						if( table[viplist[j]] <= now)
						{
							pos->leave = now;
							tacount[viplist[j]]++;
							table[viplist[j]] = leavetime(now,pos->playtime);
							finish.push_back(*pos);
							pos = P_wait.erase(pos);
							find = 1;
							break;
						}
					}
					if( find == 0)
						stop = 1;
					else
						next = 0;
				}
				if( stop == 1)
					break;
				else if(next == 1)
					pos++;
			}
			pos = P_wait.begin();
			while( pos != P_wait.end() )
			{
				int flag = 0;
				for( int j = 1 ; j <= K ; j++)
				{
					if( table[j] <= now )
					{
						pos->leave = now;
						tacount[j]++;
						table[j] = leavetime(now,pos->playtime);
						finish.push_back(*pos);
						pos = P_wait.erase(pos);
						flag = 1;
						break;
					}
				}
				if( flag == 0)
					break;
			}
			if(!P_wait.empty())
			{
				now = "21:00:01";
				for( int j = 1 ; j <= K ; j++)
				{
					if( table[j] < now)
						now = table[j];
				}
			}
			else if(P_wait.empty())
			{
				now = P_coming.top().arrive;
			}
        }
        for( list<player>::const_iterator pos = finish.begin() ; pos != finish.end() ; pos++)
        {
                cout<< pos->arrive << " " << pos->leave << " " << waittime(pos->arrive,pos->leave) <<endl;
        }
        cout<< tacount[1];
        for( i = 2 ; i <= K ; i++)
        {
                cout<<" "<< tacount[i];
        }
        cout<<endl;
}