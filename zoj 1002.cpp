#include <iostream>
using namespace std;

int config(int a[],int row)
{
        int r=0;
        for(int i=0;i<row;i++)
                for(int j=0;j<row;j++)
                        if(a[i*row+j]==2)
                        r++;
        for(int i=0;i<row;i++)
        {
                int flag=1;
                for(int j=0;j<row;j++)
                {
                        flag*=*(a+i*row+j);
                        if(flag==0)
                                flag=1;
                        else if(flag>3)
                                return 0;
                }
        }
        for(int i=0;i<row;i++)
        {
                int flag=1;
                for(int j=0;j<row;j++)
                {
                        flag*=*(a+j*row+i);
                        if(flag==0)
                                flag=1;
                        else if(flag>3)
                                return 0;
                }
        }
        return r;
}

int randall(int a[],int p,int row)
{
        int c,c1;
        if(p==row*row-1)
        {
                c=config(a,row);
                a[p/row*row+p%row]*=2;
                c1=config(a,row);
                a[p/row*row+p%row]/=2;
                return c1>c?c1:c;
        }
        c=randall(a,p+1,row);
        a[p/row*row+p%row]*=2;
        if(config(a,row))
        {
                c1=randall(a,p+1,row);
                if(c1>c)
                {
                        a[p/row*row+p%row]/=2;
                        return c1;
                }
                else
                {
                        a[p/row*row+p%row]/=2;
                        return c;
                }
        }
        else
        {
                a[p/row*row+p%row]/=2;
                return c;
        }
}



int main()
{
        int row;
        while(1)
        {
                int board[15]={0};
                cin>>row;
                if(row==0)
                        break;
                for(int i=0;i<row;i++)
                        for(int j=0;j<row;j++)
                        {
                                char bh;
                                cin>>bh;
                                if(bh=='.')
                                        board[i*row+j]=1;
                        }
                int max;
                max=randall(board,0,row);
                cout<<max<<endl;
        }
        return 0;
}