class Solution {
public:
    int m,n;
    vector<vector<int>>dd={{-1,0},{1,0},{0,1},{0,-1}};
    bool isValid(int x,int y)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    bool res=1;
    bool rec(vector<int>pos,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis)
    {
        // if(grid1[pos[0]][pos[1]]==0)return 0;
        vis[pos[0]][pos[1]]=1;
        bool cnt=1;
        res=res && grid1[pos[0]][pos[1]];
        for(auto i:dd)
        {
            int x=pos[0]+i[0];
            int y=pos[1]+i[1];
            if(isValid(x,y) && !vis[x][y] && grid2[x][y]==1)
            {
                // cout<<","<<x<<" "<<y;
                cnt= cnt && rec({x,y},grid1,grid2,vis);
            }
        }
        return (cnt);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res=1;
                if(!vis[i][j] && grid2[i][j]==1)
                {
                    // cout<<i<<" "<<j<<" ";
                    rec({i,j},grid1,grid2,vis);
                    cnt+=res;
                    // cout<<"\n";
                }
            }
        }
        return cnt;
    }
};