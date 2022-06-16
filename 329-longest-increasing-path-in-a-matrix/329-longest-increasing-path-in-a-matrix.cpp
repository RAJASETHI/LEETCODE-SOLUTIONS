class Solution {
public:
    vector<vector<int>>dd={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>>dp;
    bool isValid(vector<int>pos,vector<vector<int>>& matrix)
    {
        return (pos[0]>=0 && pos[1]>=0 && pos[0]<matrix.size() && pos[1]<matrix[0].size());
    }
    int f(vector<int>pos,vector<vector<int>>& matrix,vector<vector<int>>& vis)
    {
        if(dp[pos[0]][pos[1]]!=-1)return dp[pos[0]][pos[1]];
        vis[pos[0]][pos[1]]=1;
        int mx=0;
        for(auto i:dd)
        {
            int x=pos[0]+i[0],y=pos[1]+i[1];
            if(isValid({x,y},matrix) && !vis[x][y] && matrix[x][y]>matrix[pos[0]][pos[1]])
                mx=max(mx,1+f({x,y},matrix,vis));
        }
        vis[pos[0]][pos[1]]=0;
        return dp[pos[0]][pos[1]]=mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int mx=0;
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        vector<vector<int>>vis(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                mx=max(mx,f({i,j},matrix,vis));
            }
        }
        return mx+1;
    }
};