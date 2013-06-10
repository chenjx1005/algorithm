#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int ID;
	char name[9];
	int grade;
}student;

int comp1(const void *a,const void *b)
{
	student *sa = (student *)a;
	student *sb = (student *)b;
	return sa->ID - sb ->ID;
}

int comp2(const void *a,const void *b)
{
	student *sa = (student *)a;
	student *sb = (student *)b;
	int re = strcmp(sa->name,sb->name);
	if( re != 0)
		return re;
	else
		return sa->ID - sb ->ID;
}

int comp3(const void *a,const void *b)
{
	student *sa = (student *)a;
	student *sb = (student *)b;
	if( sa->grade != sb->grade)
		return sa->grade - sb->grade;
	else
		return sa->ID - sb->ID;
}

student S[100000];

int main()
{
	int N,C,i;
	scanf("%d%d",&N,&C);
	for( i =0 ; i < N ; i++)
	{
		scanf("%d %s %d",&S[i].ID,S[i].name,&S[i].grade);
	}
	if( C == 1)
		qsort(S,N,sizeof(student),comp1);
	else if(C == 2)
		qsort(S,N,sizeof(student),comp2);
	else
		qsort(S,N,sizeof(student),comp3);
	for( i = 0 ; i < N ; i++)
		printf("%06d %s %d\n",S[i].ID,S[i].name,S[i].grade);
	return 0;
}