class Solution {
private:
    int n;
    vector<vector<int>>dd={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int dfs(vector<int>pos,int num,vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        vis[pos[0]][pos[1]]=num;
        int cnt=1;
        for(auto i:dd)
        {
            int r=i[0]+pos[0],c=i[1]+pos[1];
            if( r>=0 && c>=0 && r<n && c<n && vis[r][c]==0 && grid[r][c]==1)
            {
                cnt+=dfs({r,c},num,vis,grid);
            }
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int mx=0;
        vector<int>grp;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int g=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    grp.push_back(dfs({i,j},g,vis,grid));
                    mx=max(mx,grp[g-1]);
                    g++;
                }
                
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)continue;
                int total=1;
                set<int>st;
                for(auto x:dd)
                {
                    int r=x[0]+i,c=x[1]+j;
                    if( r>=0 && c>=0 && r<n && c<n && grid[r][c]==1)
                    {
                        st.insert(vis[r][c]-1);
                    }
                }
                for(auto i:st)total+=grp[i];
                mx=max(mx,total);
            }
        }
        return mx;
    }
};