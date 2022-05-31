class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int>dp(n,0);
    int low=prices[0];
    for(int i=1;i<n;i++)
    {
        if(low>prices[i])low=prices[i];
        dp[i]=max(dp[i-1],prices[i]-low);
    }
    int res=0,high=prices[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(high<prices[i])high=prices[i];
        res=max(res,high-prices[i]+(i-1>=0?dp[i-1]:0));
    }
    return res;
    }
};