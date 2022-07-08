class Solution {
public:
    int f(int idx,int prev_col,vector<int>& houses, vector<vector<int>>& cost,int target,vector<vector<vector<int>>>&dp){
        if(idx==houses.size() || target<0)
        {
            if(!target)return 0;
            return 1e9;
        }
        if(dp[idx][prev_col][target]!=-1 )return dp[idx][prev_col][target];
        if(houses[idx]!=0)
        {
            if(houses[idx]!=prev_col)
            {
                return dp[idx][prev_col][target]=f(idx+1,houses[idx],houses,cost,target-1,dp);
            }
            else return dp[idx][prev_col][target]=f(idx+1,houses[idx],houses,cost,target,dp);
        }
        int mn=INT_MAX;
        for(int i=0;i<cost[0].size();i++)
        {
            if(prev_col==i+1)
            {
                mn=min(mn,cost[idx][i]+f(idx+1,prev_col,houses,cost,target,dp));
            }
            else
            {
                mn=min(mn,cost[idx][i]+f(idx+1,i+1,houses,cost,target-1,dp));
            }
        }
        return dp[idx][prev_col][target]=mn;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+2,vector<int>(target+1,-1)));
        int ans=f(0,n+1,houses,cost,target,dp);
        return (ans>=1e9?-1:ans);
    }
};