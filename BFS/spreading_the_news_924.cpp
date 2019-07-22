#include <bits/stdc++.h>
using namespace std;

int main()
{
    int visited[2501];
    int level[2501];
    int levelct[2501]={0};
    int e,n,i,x,sc,j;
    vector<vector<int> > adj;
    cin>>e;
    for(i=0;i<e;i++)
    {
        adj.push_back(vector<int>());
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>x;
            adj[i].push_back(x);
        }
    }
//    for(i=0;i<e;i++)
//    {
//        cout<<i<<"-->";
//        for(j=0;j<adj[i].size();j++)
//        {
//            cout<<adj[i][j]<<"   ";
//        }
//        cout<<endl;
//    }
    int t;
    cin>>t;
    for(j=0;j<t;j++)
    {
        cin>>sc;
        queue<int>q;
        q.push(sc);
        visited[sc]=1;
        level[sc]=0;

    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        //cout<<top<<endl;
        int size=adj[top].size();
        for(int i=0;i<size;i++)
        {
            int n=adj[top][i];
            if(visited[n]==0)
            {
                visited[n]=visited[top]+1;
                q.push(n);
                level[n]=level[top]+1;
                levelct[level[n]]++;
            }
        }
    }
//    for(i=0;i<6;i++)
//        cout<<levelct[i]<<"  ";
//cout<<endl;
//
//for(i=0;i<6;i++)
//        cout<<level[i]<<"  ";
//cout<<endl;
int indx;
    int mx=*max_element(levelct,levelct+e);
    for(int i=0;i<2501;i++)
    {
        if(levelct[i]==mx){indx=i;break;}
    }
    if(mx==0)
    {
        cout<<"No route"<<endl;
    }
    else
        cout<<mx<<" "<<indx<<endl;

    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    memset(levelct,0,sizeof(levelct));
    }
	return 0;
}
