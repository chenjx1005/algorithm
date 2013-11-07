#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char card[6] = {'S','H','C','D','J'};
int K;
int shuffing[55];
int *position;
int *newp;

int main()
{
	int i, j, *tmp;
	newp = (int *)malloc(55*sizeof(int));
	position = (int *)malloc(55*sizeof(int));
	scanf("%d",&K);
	for(i=1; i<55; i++) scanf("%d",&shuffing[i]);
	for(i=0; i<55; i++) position[i] = i;
	for(i=0; i<K; i++)
	{
		for(j=1; j<55; j++)
			newp[ shuffing[j] ] = position[j];
		tmp = newp;
		newp = position;
		position = tmp;
	}
	//for(i =1 ; i<55; i++) printf("%d ",newp[i]);
	for(i=1; i<55; i++)
	{
		printf("%c", card[ (position[i]-1)/13 ]);
		printf("%d", (position[i]-1)%13+1);
		if(i != 54)
			printf(" ");
	}
	return 0;
}