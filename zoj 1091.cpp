#include <stdio.h>
#include <stdlib.h>

int jump[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
char t_col,s_col;
int t_row,s_row;

struct node
{
        char col;
        int row;
        int number;
        struct node * next;
};
struct node * head,* end;

void enqueue(char col,int row,int number)
{
        
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->col=col;
        temp->row=row;
        temp->number=number;
        temp->next=NULL;
        end->next=temp;
        end=temp;
}

void dequene()
{
        struct node * temp = head;
        head=head->next;
        free(temp);
}

void freeall()
{
        struct node * temp;
        while(head->next!=NULL)
        {
                temp=head;
                head=head->next;
                free(temp);
        }
}

int compute(int number)
{
        char col=head->col,p_col;
        int row=head->row,p_row,i;
        
        for(i=0;i<8;i++)
        {
                p_col=col+(char)jump[i][0];
                p_row=row+jump[i][1];
                if(p_col==t_col&&p_row==t_row)
                {
                        printf("To get from %c%d to %c%d takes %d knight moves.\n",s_col,s_row,t_col,t_row,number+1);
                        return 1;
                }
                if(p_col>='a'&&p_col<='h'&&p_row>0&&p_row<9)
                        enqueue(p_col,p_row,number+1);
        }
        return 0;
}

void run()
{
        if(head->col==t_col&&head->row==t_row)
        {
                printf("To get from %c%d to %c%d takes %d knight moves.\n",s_col,s_row,t_col,t_row,head->number);
                return ;
        }
        while(head!=NULL)
        {
                if(compute(head->number))
                        break;
                dequene();
        }
}

int main()
{
        while(scanf("%c%d %c%d",&s_col,&s_row,&t_col,&t_row)!=EOF)
        {
                getchar();
                head=(struct node *)malloc(sizeof(struct node));
                end=head;
                head->col=s_col;
                head->row=s_row;
                head->number=0;
                head->next=NULL;
                run();
                freeall();
        }
        return 0;
}