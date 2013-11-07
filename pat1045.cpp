#include <stdio.h>
#include <set>
#include <stdlib.h>
using namespace std;

int fa[200], af[201];
int max_l=0;
int count[200] = {0};
set<int,greater<int>> s[200];

int main()
{
	int m,n,t,l,tmp;
	for(int i=0; i<201; i++)af[i]=-1;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) 
	{
		scanf("%d", fa+i);
		af[ fa[i] ] = i;
	}
	scanf("%d",&t);
	int rank, length;
	for(int i=0; i<200; i++) s[i].insert(0);
	for(int i=0; i<t; i++)
	{
		scanf("%d", &tmp);
		if( (rank = af[tmp]) == -1)
			continue;
		int n_l = 0;
		length = *s[rank].begin()+1;
		for(int j=rank; j<200; j++) s[j].insert(length);
		if(length > max_l)max_l=length;
	}
	printf("%d",max_l);
}
