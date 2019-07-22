#include<bits/stdc++.h>
using namespace std;

map<string,string> route;
map<string,int> visited;
map<string,int>:: iterator it;

int bfs(string a, string b, map<string,vector<string> > graph)
{
    int i;
    queue<string> s;
    s.push(a);
    visited[a]=1;
    while(s.empty()==false)
    {
        string top=s.front();
        s.pop();
        if(top==b)return visited[top];
        int size=graph[top].size();
        for(i=0;i<size;i++)
        {
            string n=graph[top][i];
            if(visited[n]==-1)
            {
                visited[n]=visited[top]+1;
                s.push(n);
                route[n]=top;
            }
        }
    }
    return -1;
}

void printpath(string a, string b)
{
    if(a==b){return;}
    printpath(route[a],b);
    cout<<route[a][0];
}

int main()
{
    int t,n,m,i;
    cin>>t;
    while(t--)
    {
        map<string,vector<string> > graph;
        cin>>m>>n;
        string s1,s2,start,end;
        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
            visited[s1]=-1;
            visited[s2]=-1;
        }
        for(i=0;i<n;i++)
        {
            cin>>start>>end;
            if(bfs(start,end,graph)!=-1)
            {
                printpath(end,start);
                cout<<end[0]<<endl;
            }
            else
            {
                printf("No route\n");
            }
            route.clear();
            for (it=visited.begin(); it!=visited.end(); ++it)
            {
                it->second = -1;
            }
        }
        cout<<endl;
    }
    return 0;
}
