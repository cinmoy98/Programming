#include<bits/stdc++.h>
using namespace std;
int main()
{
    int R,C,i,j;
    cin>>R>>C;

    int matrix[R][C];
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
        cin>>matrix[i][j];

    int visited[R][C];
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
        visited[i][j]=0;
//        for(i=0;i<R;i++)
//        for(j=0;j<C;j++)
//        cout<<visited[i][j]<<" ";
//cout<<endl;

    int rr,cc,sr,sc,move_count=0;
    cin>>sr>>sc;
    queue<int>rq;
    queue<int>cq;
    bool r_end=false;

    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};

    rq.push(sr);cq.push(sc);
    visited[sr][sc]=1;
    int dist[R][C];
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
        dist[i][j]=0;

    int countt=1;
    dist[sr][sc]=0;
    while(rq.empty()==false)
    {
        //cout<<endl<<endl<<endl<<"Loop no "<<countt<<endl;
        countt++;
        int r,c;
        r=rq.front();
        c=cq.front();

        rq.pop();
        cq.pop();
        //cout<<"r is: "<<r<<"      "<<"c is : "<<c<<endl<<endl;

        if(matrix[r][c]==-99)
        {
            r_end=true;
            break;
        }
        for(i=0;i<4;i++)
        {
            rr=r+dr[i];
            cc=c+dc[i];
            //cout<<"rr is : "<<rr<<"    cc is: "<<cc<<"    ";
            if((rr<0)||(cc<0)||(rr>=R)||(cc>=C)||(visited[rr][cc]==1)||(matrix[rr][cc]==-1)){continue;}
            else{
                   // cout<<rr<<" and "<<cc<<" pushed into the queue"<<endl;
                    rq.push(rr);
                    cq.push(cc);
                    visited[rr][cc]=1;
                    dist[rr][cc]=dist[r][c]+1;
                    move_count++;

                }
        }
        if(r_end==true)break;


    }
 cout<<dist[9][9]<<endl;
}
