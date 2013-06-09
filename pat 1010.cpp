#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 9223372036854775807LL
long long dec1=MAX;

long long tode(char *d,int length,long long ra)
{
        if(ra==0)
                return 0;
        int i,k;
        long long de=0;
        for(i=0;i<length;i++)
        {
                if(d[i]>='0'&&d[i]<='9')
                        k=d[i]-48;
                else
                        k=d[i]-97+10;
                if(de!=0)
                        if( (MAX-k)/ra < de)
                                return dec1+1;
                de=de*ra+k;
        }
        return de;
}

int main()
{
        char * n1, * n2;
        n1=(char*)malloc(10*sizeof(char));
        n2=(char*)malloc(10*sizeof(char));
        int tag,ra,l=0,i;
        long long left=0,mid,right=MAX;
        long long de1,de2;
        scanf("%s %s %d %d",n1,n2,&tag,&ra);
        if(tag==2)
        {
                char *tmp;
                tmp=n1;
                n1=n2;
                n2=tmp;
        }
        if(n1[0]!='0'&&n2[0]=='0')
        {
                printf("Impossible");
                return 0;
        }
        while(n1[l++]!='\0');
        l-=1;
        de1=tode(n1,l,ra);
        dec1=de1;
        l=0;
        while(n2[l++]!='\0');
        l-=1;
        for(i=0;i<l;i++)
        {
                int tmp;
                if(n2[i]>='0'&&n2[i]<='9')
                        tmp=n2[i]-48;
                else
                        tmp=n2[i]-97+10;
                if(left<tmp)
                        left=tmp;
        }
        left++;
        while(left<right)
        {
                mid=left+(right-left)/2;
                de2=tode(n2,l,mid);
                if(de1>de2)
                        left=mid+1;
                else if(de2>de1)
                        right=mid-1;
                else
                        right=mid;
        }
        if(tode(n2,l,left)==de1)
                printf("%lld",left);
        else
                printf("Impossible");
        return 0;
}