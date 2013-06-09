#include <stdio.h>
#include <string.h>

char number[22];
int digit[10]={0};

int main()
{
        int i;
        scanf("%s",number);
        int legth = strlen(number);
        int up=0,num;
        for( i = legth -1 ; i >= 0 ; i--)
        {
                num = number[i] - '0';
                digit[num]++;
                num = num * 2 + up;
                up = num / 10;
                num %= 10;
                digit[num]--;
                number[i]= num + '0';
        }
        if( up != 0)
        {
                printf("No\n%d",up);
                printf("%s",number);
        }
        else
        {
                for(i = 0 ; i < 10 ; i++)
                        if(digit[i] != 0)
                        {
                                printf("No\n");
                                printf("%s",number);
                                return 0;
                        }
                printf("Yes\n");
                printf("%s",number);
                return 0;
        }
        return 0;
}