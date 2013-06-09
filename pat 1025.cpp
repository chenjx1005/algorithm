#include <iostream>
#include <string>
#include <set>

using namespace std;

struct re
{
        string id;
        int score;
        int location;
        bool operator < (const re& b ) const
        {
                if( score > b.score )
                        return true;
                else if( score == b.score && id < b.id)
                        return true;
                return false;
        }
};

set<re> ranklist;
int N,K;
int final_i = 1,final_rank = 1,final_score = -1;
int local_i[101]={0},local_rank[101]={0},local_score[101]={0};

int main()
{
        int i,j;
        re temp;
        cin >> N;
        for( i = 0 ; i < N ; i++)
        {
                cin >> K;
                for( j = 1 ; j <= K ; j++)
                {
                        cin >> temp.id >> temp.score;
                        temp.location = i+1;
                        ranklist.insert(temp);
                }
        }
        set<re>::const_iterator pos;
        for( i = 1; i <=N ; i++)
        {
                local_i[i] = 1;
                local_rank[i] = 1;
                local_score[i] = -1;
        }
        cout<<ranklist.size()<<endl;
        for( pos = ranklist.begin() ; pos != ranklist.end() ; pos++)
        {
                if( pos->score != final_score)
                {
                        final_rank = final_i;
                        final_score = pos->score;
                }
                if( pos->score != local_score[pos->location])
                {
                        local_rank[pos->location] = local_i[pos->location];
                        local_score[pos->location] = pos->score;
                }
                cout << pos->id <<" "<<final_rank<<" "<<pos->location<<" "<<local_rank[pos->location]<<endl;
                final_i++;
                local_i[pos->location]++;
        }
}