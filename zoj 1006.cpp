#include <stdio.h>
#include <string.h>

char plain[71];
int plaincode[71];
char cipher[71];
int ciphercode[71];
int length;
int key;

void encryption(int i);
int toint(char c);
char tochar(int i);
void tocode(char *text,int *code);
void totext(int *code,char *text);


int main()
{
        int i;
        while(scanf("%d",&key)&&key)
        {
                scanf("%s",cipher);
                for(length=0;cipher[length]!='\0';length++);
                tocode(cipher,ciphercode);
                for(i=0;i<length;i++)
                {
                        encryption(i);
                }
                totext(plaincode,plain);
                plain[length]='\0';
                printf("%s\n",plain);
        }

        return 0;
}

int toint(char c)
{
        if(c=='_')
                return 0;
        if(c=='.')
                return 27;
        return (int)c-96;
}

char tochar(int i)
{
        if(i==0)
                return '_';
        if(i==27)
                return '.';
        return (char)(i+96);
}

void tocode(char *text,int *code)
{
        int i;
        for(i=0;i<length;i++)
                code[i]=toint(text[i]);
}

void totext(int *code,char *text)
{
        int i;
        for(i=0;i<length;i++)
                text[i]=tochar(code[i]);
}

int mod(int p_code,int c_i,int c_code)
{
        int m=(p_code-c_i)%28;
        if(m < 0)
                m+=28;
        return m==c_code?1:0;
}

void encryption(int i)
{
        int c_i=i,p_i;
        int c_code,p_code,pa,pb;

        p_i=key*c_i%length;
        c_code=ciphercode[i];
        for(p_code=0;!mod(p_code,c_i,c_code);p_code++);
        plaincode[p_i]=p_code;
}