#include <stdio.h>
#include <assert.h>

int d[100001];
int from[100001];

int main()
{
	int n;
	scanf("%d", &n);
	int all = 0;
	for(int i=1; i<=n; i++) scanf("%d", d+i), from[i] = all, all+=d[i]; 
	int m;
	scanf("%d", &m);
	int s,t,l,r,tmp;
	while(m--)
	{
		scanf("%d%d", &t, &s);
		assert(t!=s);
		if(t>s) tmp=t,t=s,s=tmp;
		l = from[s]-from[t];
		r =  l< all-l ? l : all-l;
		printf("%d\n",r);
	}
}