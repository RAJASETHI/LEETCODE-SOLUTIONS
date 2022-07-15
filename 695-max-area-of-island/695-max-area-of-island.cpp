class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        int mxArea=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    int cnt=0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(q.size())
                    {
                        int _x=q.front().first,_y=q.front().second;
                        cnt++;
                        q.pop();
                        for(auto d:dir)
                        {
                            int t_x=_x+d[0],t_y=_y+d[1];
                            if( (t_x>=0 && t_y>=0 && t_x<r && t_y<c) &&!vis[t_x][t_y] && grid[t_x][t_y])
                            {
                                vis[t_x][t_y]=1;
                                q.push({t_x,t_y});
                            }
                        }
                    }
                    mxArea=max(mxArea,cnt);
                  }
                
            }
        }
        return mxArea;
        
    }
};