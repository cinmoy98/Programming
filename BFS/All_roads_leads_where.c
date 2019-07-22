#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c,i,j;



    int visited[10001];
    for(i=0;i<10001;i++)visited[i]=0;
    queue<int>Q;

            Q.push(m3[x]);
            visited[m3[x]]=1;

            while(!Q.empty())
            {
                int u=Q.front();
                Q.pop();

                for(i=0;i<adj[u].size();i++)
                {

                    if(visited[adj[u][i]]==0)
                    {
                        Q.push(adj[u][i]);
                        visited[adj[u][i]]=1;
                        if(adj[u][i]==m3[y])flag=1;
                        path[u].push_back(adj[u][i]);
                    }
                }
            }

    return 0;
}
