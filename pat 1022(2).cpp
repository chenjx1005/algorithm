#include <iostream>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

map<string,set<int>> tag[5];//title,author,key,pub,year
int N,M;

int main()
{
        int i,j;
        string tmp_s;
        cin >> N;
        for( i = 0; i < N ; i++)
        {
                int tmp_i;
                map<string,set<int>>::const_iterator pos;
                cin >> tmp_i;
                cin.get();
                for(j = 0 ; j < 5 ; j++)
                {
                        if(j == 2)
                        {
                                for(;;)
                                {
                                        cin >> tmp_s;
                                        tag[j][tmp_s].insert(tmp_i);
                                        if( getchar() == '\n')
                                                break;
                                }
                        }
                        else
                        {
                                getline(cin,tmp_s);
                                tag[j][tmp_s].insert(tmp_i);
                        }
                }
        }
        cin >> M;
        int choose;
        map<string,set<int>>::const_iterator pos;
        set<int>::const_iterator poset;
        for( i = 0 ; i < M ; i++)
        {
                cin >> choose;
                cin.ignore(2);
                getline(cin,tmp_s);
                cout<< choose << ": " << tmp_s <<endl;
                pos = tag[choose-1].find(tmp_s);
                if( pos == tag[choose-1].end() )
                {
                        cout<<"Not Found"<<endl;
                }
                else
                {
                        for(poset = pos->second.begin() ; poset != pos->second.end() ; poset++)
                                cout<< setw(7) << setfill('0') <<*poset<<endl;
                }
        }
}