#include <stdio.h>

int N,M,K,Q;
int clock=0,cust_min=1;
typedef struct
{
        int time;
        int finish;
}customer;

customer customers[1001]={0};

typedef struct
{
        int size;
        int front;
        int rear;
        int cust[10];
}queue;

queue queues[20];

void initqueue()
{
        int i;
        for(i = 0;i < N;i++)
        {
                queues[i].size = 0;
                queues[i].front = 1;
                queues[i].rear = 0;
        }
}

int dequeue(int i)
{
        int r;
        if(queues[i].size-- == 0)
        {
                throw "empty!";
                queues[i].size++;
        }
        r=queues[i].cust[queues[i].front];
        if( ++queues[i].front == 10)
                queues[i].front = 0;
        return r;
}

void enqueue(int i ,int id)
{
        if( queues[i].size++ == M)
        {
                throw "full!";
                queues[i].size--;
        }
        if( ++queues[i].rear == 10)
                queues[i].rear = 0;
        queues[i].cust[queues[i].rear] = id;
}

int qisempty()
{
        int i;
        for( i = 0 ;i < N; i++)
        {
                if( queues[i].size != 0)
                        return 0;
        }
        return 1;  
}

int findminhead()
{
        int i,min=1000,id,minid;
        for( i = 0; i < N;i++)
        {
                if( queues[i].size == 0)
                        continue;
                id = queues[i].cust[queues[i].front];
                if( customers[id].time < min )
                {	
                        min = customers[id].time;
                        minid=i;	
                }
        }
        return minid;
}

int updateclock(int minid)
{
        int id=queues[minid].cust[queues[minid].front];
        int time = customers[id].time;
        clock+=time;
        return time;
}

void updatequeuehead(int pass)
{
        int i,id;
        for( i =0 ;i < N; i++)
        {
                id=queues[i].cust[queues[i].front];
                customers[id].time-=pass;
        }
}

void init()
{
        int i,j;  
        for( i = 0; i < M ; i++)
                for( j =0; j < N ; j++)
                {
                        if(cust_min > K)
                                return;
                        enqueue(j,cust_min++);
                }
}

void run()
{
        int i,pass,id;
        while(!qisempty())
        {
                i = findminhead();
                pass = updateclock(i);
                updatequeuehead(pass);
                id = dequeue(i);
                customers[id].finish = clock;
                if(clock < 540)
                {
                        if(cust_min <= K)
                                enqueue(i,cust_min++);
                }
                else
                        queues[i].size=0;
        }
}

void print(int id)
{
        int h,m;
        if( customers[id].finish == 0 )
                printf("Sorry");
        else
        {
                h=customers[id].finish/60+8;
                m=customers[id].finish%60;
                printf("%02d:%02d",h,m);
        }
}

int main()
{
        int i,id;
        scanf("%d%d%d%d",&N,&M,&K,&Q);
        initqueue();
        for( i = 1; i <= K; i++)
        {
                scanf("%d",&customers[i].time);
        }
        init();
        run();
        for( i = 0; i < Q; i++)
        {
                scanf("%d",&id);
                print(id);
                if(i != Q-1)
                printf("\n");
        }
        return 0;
}