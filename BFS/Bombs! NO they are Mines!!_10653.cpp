#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};
    while(1)
    {
        int R,C,rows,indx,bn,val,sr,sc,dsr,dsc;
        cin>>R>>C;
        if(R==0&&C==0)break;
        int matrix[R][C];
        for(i=0;i<R;i++)
            { for(j=0;j<C;j++)
                  {matrix[i][j]=0;}
            }

        cin>>rows;
        for(i=0;i<rows;i++)
        {
            cin>>indx;
            cin>>bn;
            for(j=0;j<bn;j++)
            {
                cin>>val;
                matrix[indx][val]=-1;
            }

        }
        cin>>sr>>sc;
        cin>>dsr>>dsc;
        matrix[dsr][dsc]=-99;

        int rr,cc,r,c;
        bool r_end=false;
        int visited[R][C];
        int level[R][C];
        for(i=0;i<R;i++)
            { for(j=0;j<C;j++)
                  {visited[i][j]=0;}
            }
        for(i=0;i<R;i++)
            { for(j=0;j<C;j++)
                  {level[i][j]=0;}
            }
        queue<int>qr;
        queue<int>qc;
        qr.push(sr);
        qc.push(sc);
        level[sr][sc]=0;
        visited[sr][sc]=1;
        while(qr.empty()==false)
        {
            r=qr.front();
            c=qc.front();
            qr.pop();
            qc.pop();
            if(matrix[r][c]==-99)
            {
                r_end=true;
                break;
            }
            for(i=0;i<4;i++)
            {
                rr=r+dr[i];
                cc=c+dc[i];
                if((rr<0)||(cc<0)||(rr>=R)||(cc>=C)||(visited[rr][cc]==1)||(matrix[rr][cc]==-1)){continue;}

                else
                    {
                        qr.push(rr);
                        qc.push(cc);
                        visited[rr][cc]=1;
                        level[rr][cc]=level[r][c]+1;
                    }
            }


        }
        cout<<level[dsr][dsc]<<endl;
    }
}
