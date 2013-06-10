#include <stdio.h>
#include <assert.h>
int a[1000001],b[1000001];
#define INFI 0x7FFFFFFF

int main()
{
  int la,lb,i,j,flag,im,m;
  scanf("%d",&la);
  for( i = 0 ; i < la ; i++)
  {
    scanf("%d",a+i);
  }
  scanf("%d",&lb);
  for( i = 0 ; i < lb ; i++)
  {
    scanf("%d",b+i);
  }
  i = j = flag = im =0;
  m = (la + lb - 1) / 2;
  while(1)
  {
    if( i != la && j != lb)
    {
      assert(a[i]!=b[j]);
      if( a[i] < b[j])
      {
        i++;
        flag =1;
      }
      else
      {
        j++;
        flag = 2;
      }
    }
    else
    {
      if( i == la)
      {
        assert(a[i-1]!=b[j]);
        j++;
        flag = 2;
      }
      else
      {
        assert(a[i]!=b[j-1]);
        i++;
        flag =1;
      }
    }
    if( im == m)
    {
      if(flag == 1)
        printf("%ld",a[i-1]);
      else
        printf("%ld",b[j-1]);
      break;
    }
    im++;
  }
  return 0;
}