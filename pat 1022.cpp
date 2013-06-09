#include <map>
#include <iostream>
#include <list>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

multimap<string,int> title;
multimap<string,int> keywords;
multimap<string,int> publisher;
multimap<string,int> author;
multimap<string,int> year;
int N,M;

int main()
{
        int i,tmp_id;
        string tmp_title,tmp_author,tmp_key,tmp_publisher,tmp_year;
        cin>>N;
        for ( i = 0 ; i < N ; i++)
        {
                cin >> tmp_id;
                getchar();
                getline(cin,tmp_title);
                getline(cin,tmp_author);
                title.insert(make_pair(tmp_title,tmp_id));
                author.insert(make_pair(tmp_author,tmp_id));
                while(true)
                {
                        cin>>tmp_key;
                        keywords.insert(make_pair(tmp_key,tmp_id));
                        if(getchar() == '\n')
                                break;
                }
                getline(cin,tmp_publisher);
                publisher.insert(make_pair(tmp_publisher,tmp_id));
                cin>>tmp_year;
                year.insert(make_pair(tmp_year,tmp_id));
        }
        cin>>M;
        int query;
        for( i = 0 ; i < M; i++)
        {
                scanf("%d: ",&query);
                switch ( query )
                {
                case 1:
                        {
                                getline(cin,tmp_title);
                                cout<<"1: "<<tmp_title<<endl;
                                multimap<string,int>::const_iterator p,end = title.upper_bound(tmp_title);
                                list<int> output;
                                for( p = title.lower_bound(tmp_title) ; p != end ; p++)
                                {
                                        output.push_back(p->second);
                                }
                                if(output.empty())
                                {
                                        cout<<"Not Found"<<endl;
                                        break;
                                }
                                output.sort();
                                list<int>::const_iterator list_pos;
                                for( list_pos = output.begin() ; list_pos != output.end() ; list_pos++)
                                        cout<<setfill('0')<<setw(7)<< *list_pos<<endl;
                                break;
                        }
                case 2:
                        {
                                getline(cin,tmp_title);
                                cout<<"2: "<<tmp_title<<endl;
                                multimap<string,int>::const_iterator p,end = author.upper_bound(tmp_title);
                                list<int> output;
                                for( p = author.lower_bound(tmp_title) ; p != end ; p++)
                                {
                                        output.push_back(p->second);
                                }
                                if(output.empty())
                                {
                                        cout<<"Not Found"<<endl;
                                        break;
                                }
                                output.sort();
                                list<int>::const_iterator list_pos;
                                for( list_pos = output.begin() ; list_pos != output.end() ; list_pos++)
                                        cout<<setfill('0')<<setw(7)<< *list_pos<<endl;
                                break;
                        }
                case 3:
                        {
                                getline(cin,tmp_key);
                                cout<<"3: "<<tmp_key<<endl;
                                multimap<string,int>::const_iterator p,end = keywords.upper_bound(tmp_key);
                                list<int> output;
                                for( p = keywords.lower_bound(tmp_key) ; p != end ; p++)
                                {
                                        output.push_back(p->second);
                                }
                                if(output.empty())
                                {
                                        cout<<"Not Found"<<endl;
                                        break;
                                }
                                output.sort();
                                list<int>::const_iterator list_pos;
                                for( list_pos = output.begin() ; list_pos != output.end() ; list_pos++)
                                        cout<<setfill('0')<<setw(7)<< *list_pos<<endl;
                                break;
                        }
                case 4:
                        {
                                getline(cin,tmp_publisher);
                                cout<<"4: "<<tmp_publisher<<endl;
                                multimap<string,int>::const_iterator p,end = publisher.upper_bound(tmp_publisher);
                                list<int> output;
                                for( p = publisher.lower_bound(tmp_publisher) ; p != end ; p++)
                                {
                                        output.push_back(p->second);
                                }
                                if(output.empty())
                                {
                                        cout<<"Not Found"<<endl;
                                        break;
                                }
                                output.sort();
                                list<int>::const_iterator list_pos;
                                for( list_pos = output.begin() ; list_pos != output.end() ; list_pos++)
                                        cout<<setfill('0')<<setw(7)<< *list_pos<<endl;
                                break;
                        }
                case 5:
                        {
                                cin >> tmp_year;
                                cout<<"5: "<<tmp_year<<endl;
                                multimap<string,int>::const_iterator p,end = year.upper_bound(tmp_year);
                                list<int> output;
                                for( p = year.lower_bound(tmp_year) ; p != end ; p++)
                                {
                                        output.push_back(p->second);
                                }
                                if(output.empty())
                                {
                                        cout<<"Not Found"<<endl;
                                        break;
                                }
                                output.sort();
                                list<int>::const_iterator list_pos;
                                for( list_pos = output.begin() ; list_pos != output.end() ; list_pos++)
                                        cout<<setfill('0')<<setw(7)<< *list_pos<<endl;
                                break;
                        }
                }
        }
}