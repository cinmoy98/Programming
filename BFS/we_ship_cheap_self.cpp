#include<bits/stdc++.h>
using namespace std;

map<string,string> route;
map<string,int> visited;

int bfs(string a , string b , map<string,vector<string> > graph)
{
    queue<string> s;
    s.push(a);
    visited[a]=1;
    while(s.empty()==false)
    {
        string top =s.front();
        s.pop();
        if(top==b)
            return visited[top];
        int size=graph[top].size();
        for(int i=0;i<size;i++)
        {
            string n=graph[top][i];
            if(visited[n]==-1)
            {
                visited[n]=visited[top]+1;
                route[n]=top;
                s.push(n);
            }
        }
    }
    return -1;
}

void printpath(string a ,string b)
{
    if(a==b){return;}
        printpath(route[a],b);
        cout<<route[a][0]<<" "<<a<<endl;
}

int main()
{
    int n,i;
    bool primera = false;
    while(scanf("%d",&n)!=EOF)
    {
        map<string,vector<string> > graph;
        string s1,s2,start,end;
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
            visited[s1]=-1;
            visited[s2]=-1;
        }
        cin>>start>>end;

        if(bfs(start,end,graph)!=-1)
        {
            printpath(end,start);
        }
        else
            printf("No route\n");

    }
    return 0;
}
