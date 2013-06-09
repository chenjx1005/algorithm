#include <stdio.h>
#include <string.h>
int main(void)
{
    int A, B, N;
    int a, b, temp;
    
    while (scanf("%d%d%d", &A, &B, &N) != EOF)
    {
        a = b = 0;  
        while (1)
        {
            if (a == A)
            {
                printf("empty A\n");
                a = 0;
            }
            else if (b == 0)
            {
                printf("fill B\n");
                b = B;
            }
            else 
            {
                printf("pour B A\n");
                temp = b;
                b = a + temp <= A? 0 : temp - (A - a);
                a = a + temp <= A? a+temp : A;
            }
                
            if (a == N || b == N) 
            {
                printf("success\n");
                break;
            }
        }
    }
    return 0;
}