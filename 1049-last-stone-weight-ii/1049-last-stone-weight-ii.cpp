class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n=stones.size();
        int sm=0;
        for(auto i:stones)sm+=i;
        vector<vector<int>>dp(n+1,vector<int>(sm+1,0));
        dp[0][0]=1;
        int val=sm;
        int diff=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=val;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=stones[i-1] && dp[i-1][j-stones[i-1]])
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j-stones[i-1]];
                }
                if(i==n)
                {
                    if(dp[i][j])
                    {
                        diff=min(diff,abs(sm-j*2));
                    }
                }
            }
        }
        return diff;
        
    }
};