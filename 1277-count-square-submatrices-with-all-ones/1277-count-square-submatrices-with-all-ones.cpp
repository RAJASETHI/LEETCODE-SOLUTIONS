class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!i || !j)
                {
                    dp[i][j]=mat[i][j];
                }
                else
                {
                    if(mat[i][j])
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                cnt+=dp[i][j];
            }
        }
        return cnt;
    }
};