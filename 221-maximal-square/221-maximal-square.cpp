class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int mx=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!i || !j)
                {
                    dp[i][j]=mat[i][j]-'0';
                }
                else
                {
                    if(mat[i][j]-'0')
                        dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                    
                }
                mx=max(mx,dp[i][j]);
            }
        }
        return mx*mx;
    }
};