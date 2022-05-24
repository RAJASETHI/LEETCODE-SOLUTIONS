class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=amount;j++)
            {
                int flag=0;
                    if(j>=coins[i-1] && dp[i][j-coins[i-1]]!=-1 && ++flag)dp[i][j]=dp[i][j-coins[i-1]]+1;
                    if(dp[i-1][j]!=-1)
                    {
                        dp[i][j]=min((flag?dp[i][j]:INT_MAX),dp[i-1][j]);
                    }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
        return dp[n][amount];
    }
};