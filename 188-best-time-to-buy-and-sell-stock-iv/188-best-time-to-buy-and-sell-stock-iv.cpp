class Solution {
public:
    int f(int idx,int buy,vector<int>&prices,int k,vector<vector<vector<int>>>&dp)
    {
        if(idx==prices.size() || k==0)return 0;
        int profit=0;
        if(dp[idx][k][buy]!=-1)return dp[idx][k][buy];
        if(buy)
        {
            profit=-prices[idx]+f(idx+1,0,prices,k,dp);
            profit=max(profit,f(idx+1,1,prices,k,dp));
        }
        else
        {
            profit=prices[idx]+f(idx+1,1,prices,k-1,dp);
            profit=max(profit,f(idx+1,0,prices,k,dp));
        }
        return dp[idx][k][buy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return f(0,1,prices,k,dp);
    }
};