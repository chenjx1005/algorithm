#include <stdio.h>
#include <string.h>
int n, best;
char map[5][5];
void Search(int m);
int Over(void);
int Canput(int i, int j);
int main(void)
{
 while (scanf("%d", &n) != EOF && n)
 {
  for (int i = 0; i < n; i++)
      scanf("%s", map[i]);
  
  best = 0;
  Search(0);
  printf("%d\n", best);
 }
 return 0;
}
 

void Search(int m)
{ 
 if (Over()) 
 {
  best = m > best? m : best; 
  return;
 }
 
 for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
   if (Canput(i,j)) 
   {
    map[i][j] = '@';
    Search(m + 1);
    map[i][j] = '.';
   }
  } 
}

int Over(void)
{
 for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
       if (Canput(i,j)) return 0;
 
 return 1;
}

int Canput(int i, int j)
{
 int row, col;
 
 if (map[i][j] != '.') return 0;
 
 for (row = i - 1; row >= 0; row--)
 {
  if (map[row][j] == 'X') break;
  if (map[row][j] == '@') return 0;
 }
 
 for (row = i + 1; row < n; row++)
 {
  if (map[row][j] == 'X') break;
  if (map[row][j] == '@') return 0;
 }
 
 for (col = j - 1; col >= 0; col--)
 {
  if (map[i][col] == 'X') break;
  if (map[i][col] == '@') return 0;
 }
   
 for (col = j + 1; col < n; col++)
 {
  if (map[i][col] == 'X') break;
  if (map[i][col] == '@') return 0;
 }
 
    return 1;
}