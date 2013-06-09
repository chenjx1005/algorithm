#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
        int i,N;
        scanf("%d",&N);
        vector<int> postorder(N);
        vector<int> inorder(N);
        for(i = 0; i < N; i++)
                scanf("%d",&postorder[i]);
        for(i = 0; i < N; i++)
                scanf("%d",&inorder[i]);
        queue<vector<int>> Q;
        Q.push(inorder);
        vector<int>::const_reverse_iterator root;
        vector<int>::iterator sp;
        while(!Q.empty())
        {
                inorder = Q.front();
                Q.pop();
                for(root = postorder.rbegin(); root != postorder.rend(); root++)
                {
                        sp = find(inorder.begin(),inorder.end(),*root);
                        if(sp != inorder.end())
                        {
                                vector<int> left(inorder.begin(),sp);
                                vector<int> right(sp+1,inorder.end());
                                if(!left.empty())
                                {
                                        Q.push(left);
                                }
                                if(!right.empty())
                                {
                                        Q.push(right);
                                }
                                if(!Q.empty()) 
                                {
                                        printf("%d ",*sp);
                                        break;
                                }
                                else
                                {
                                        printf("%d",*sp);
                                        break;
                                }
                        }
                }
        }
}