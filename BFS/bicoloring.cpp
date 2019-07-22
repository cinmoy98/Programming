#include<bits/stdc++.h>
using namespace std;
int main()
{

    int x,y,i,e,u,n;


    while(scanf("%d",&n))
    {
        int color[1000]={0};
        vector<int>vec[201];
        if(n==0)break;
        cin>>e;

    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    queue<int>Q;
    Q.push(0);
    int flag=0;
    color[0]=1111;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();

        for(i=0;i<vec[u].size();i++)
        {
            if(color[vec[u][i]]==0)
            {

                if(color[u]==1111)
                {
                    color[vec[u][i]]=2222;
                }
                else
                    {
                        color[vec[u][i]]=1111;
                    }

                Q.push(vec[u][i]);

            }
            if(color[u]==color[vec[u][i]])
            {
              flag=1;
              break;

            }
        }
        if(flag==1)break;
    }

    if(flag==0){cout<<"BICOLORABLE."<<endl;}
    else {cout<<"NOT BICOLORABLE."<<endl;}
    }
}

