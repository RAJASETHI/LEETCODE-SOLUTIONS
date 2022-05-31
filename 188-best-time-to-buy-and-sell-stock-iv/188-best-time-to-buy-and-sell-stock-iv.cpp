class Solution {
public:
    // int f(int idx,int buy,vector<int>&prices,int k,vector<vector<vector<int>>>&dp)
    // {
    //     if(idx==prices.size() || k==0)return 0;
    //     int profit=0;
    //     if(dp[idx][k][buy]!=-1)return dp[idx][k][buy];
    //     if(buy)
    //     {
    //         profit=-prices[idx]+f(idx+1,0,prices,k,dp);
    //         profit=max(profit,f(idx+1,1,prices,k,dp));
    //     }
    //     else
    //     {
    //         profit=prices[idx]+f(idx+1,1,prices,k-1,dp);
    //         profit=max(profit,f(idx+1,0,prices,k,dp));
    //     }
    //     return dp[idx][k][buy]=profit;
    // }
    int f(int idx,int trns,vector<int>&prices,int k)
    {
        if(idx==prices.size() || trns==2*k)return 0;
        int profit=0;
        if(trns%2==0)
        {
            profit=-prices[idx]+f(idx+1,trns+1,prices,k);
            profit=max(profit,f(idx+1,trns,prices,k));
        }
        else
        {
            profit=prices[idx]+f(idx+1,trns+1,prices,k);
            profit=max(profit,f(idx+1,trns,prices,k));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // Approach 1:
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        // return f(0,1,prices,k,dp);
       // Approach 2:
        // return f(0,0,prices,k);
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=2*k-1;j>=0;j--)
            {
                int profit=0;
                if(j%2==0)
                {
                    profit=-prices[i]+dp[i+1][j+1];
                    profit=max(profit,dp[i+1][j]);
                }
                else
                {
                     profit=prices[i]+dp[i+1][j+1];
                    profit=max(profit,dp[i+1][j]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][0];
    }
    
};