#include<bits/stdc++.h>
using namespace std;
int visited[21];
int level[21];
void bfs(int s,int e,vector<vector<int> >v)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;
    level[s]=0;
    while(q.empty()==false)
    {
        int top=q.front();
        q.pop();
        int sz=v[top].size();
        for(int i=0;i<sz;i++)
        {
            int n=v[top][i];
            if(visited[n]==0)
            {
                visited[n]=1;
                q.push(n);
                level[n]=level[top]+1;
                if(n==e)return;
            }
        }
    }
}
int main()
{
    int i,j,ct=1;
    while(1)
    {

        vector<vector<int> > v(21);// v.push_back(vector<int>());
        int bn,x;
        for(i=1;i<20;i++)
        {
            cin>>bn;
            for(j=0;j<bn;j++)
            {
                cin>>x;
                v[i].push_back(x);
                v[x].push_back(i);
            }
        }
        int t;
        cin>>t;
        printf("Test Set #%d\n",ct);
        for(i=1;i<=t;i++)
        {
            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));
            int sr,ds;
            cin>>sr>>ds;
            bfs(sr,ds,v);
            printf("%2d to %2d: %d\n",sr,ds,level[ds]);

        }
    cout<<endl;
    ct++;
    }
}
