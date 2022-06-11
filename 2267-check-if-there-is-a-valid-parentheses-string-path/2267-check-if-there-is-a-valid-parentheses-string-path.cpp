class Solution {
public:
    int dp[101][101][202];
    bool f(int i,int j,int k,vector<vector<char>>& grid)
    {
        if(i>=grid.size() || j>=grid[0].size())return 0;
        
        if(grid[i][j]=='(')k++;
        else k--;
        
        if(k<0)return false;
        if(i==grid.size()-1 && j==grid[0].size()-1)return (k==0);
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool ans=f(i+1,j,k,grid) || f(i,j+1,k,grid);
        return dp[i][j][k]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,grid);
    }
};