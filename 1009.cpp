#include <bits/stdc++.h>
using namespace std;
int color[20001];
vector<int>A[20001];
vector<int>source;
int bfs()
{
    memset(color,-1,sizeof(color));
    int even=0,odd=0,n=0,ans=0;
    int siz=source.size();
    queue<int>Q;
    for(int i=0;i<siz;i++)
    {
        if(color[source[i]]==-1) {
        odd++;
        Q.push(source[i]);
        color[source[i]]=1;

        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            int s=A[x].size();

            for(int j=0;j<s;j++)
            {
                if(color[A[x][j]]!=2 && color[x]==1)
                {
            even++;
        Q.push(A[x][j]);
        color[A[x][j]]=2;
                }
                else if(color[A[x][j]]!=1 && color[x]==2)
                {
            odd++;
        Q.push(A[x][j]);
        color[A[x][j]]=1;
                }
            }

        }
    ans+=max(even,odd);
    even=odd=0;
    }
}

return ans;
}
int main()
{
    int te;
    int n,u,v;scanf("%d",&te);
    for(int k=1;k<=te;k++) {
    set<int>N;
scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        A[u].push_back(v);
        A[v].push_back(u);
        N.insert(u);
        N.insert(v);
    }
    set<int> ::iterator it;
    for(it=N.begin();it!=N.end();it++)
        source.push_back(*it);
        int ans=bfs();
    printf("Case %d: %d\n",k,ans);
    for(int i=0;i<20001;i++)
        A[i].clear();
    source.clear();

}
}
