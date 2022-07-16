class Solution {
private:
    int m,n;
    vector<vector<int>>dd={{-1,0},{1,0},{0,-1},{0,1}};
public:
    void dfs(vector<int>pos,vector<vector<int>>& grid)
    {
        grid[pos[0]][pos[1]]=0;
        for(auto i:dd)
        {
            int r=pos[0]+i[0],c=pos[1]+i[1];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c])
            {
                dfs({r,c},grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0])dfs({i,0},grid);
            if(grid[i][n-1])dfs({i,n-1},grid);
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i])dfs({0,i},grid);
            if(grid[m-1][i])dfs({m-1,i},grid);
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])cnt++;
            }
        }
        return cnt;
    }
};