#include <bits/stdc++.h>
using namespace std;
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
char grid[21][21];
bool visited[21][21];
int row,col;
bool InGrid(int x,int y)
{
    if(x<=row && y<=col && x>0 && y>0)
        return true;
    else
        return false;
}
int bfs(int x,int y)
{
    memset(visited,0,sizeof(visited));
    queue< pair<int,int> >Q;
    Q.push(make_pair(x,y));
    pair<int, int> P;
    int ans=1;
    visited[x][y]=true;
    while(!Q.empty())
    {
       P=Q.front();
       Q.pop();
        int xx=P.first;
        int yy=P.second;
       for(int i=0;i<4;i++)
       {
           int u=xx+fx[i];
           int v=yy+fy[i];
           if(!visited[u][v] && InGrid(u,v) && grid[u][v]=='.')
           {
               ans++;
               visited[u][v]=true;
               Q.push(make_pair(u,v));
           }

       }
    }
    return ans;

}
int main()
{
    int te,x,y;
    string S;
    scanf("%d\n",&te);
    for(int i=1;i<=te;i++)
    {
        memset(grid,0,sizeof(grid));
        scanf("%d %d",&col,&row);
        for(int j=1;j<=row;j++) {

            for(int k=1;k<=col;k++)
        {
            cin>>grid[j][k];
            if(grid[j][k]=='@') {
                x=j;y=k;
            }
        }
        }
        printf("Case %d: %d\n",i,bfs(x,y));
    }

    return 0;
}
