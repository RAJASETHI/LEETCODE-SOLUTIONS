class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mxSqr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]-'0')
                {
                    if(!i || !j)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                    mxSqr=max(mxSqr,dp[i][j]);
                }
            }
        }
        return mxSqr*mxSqr;
        
    }
};