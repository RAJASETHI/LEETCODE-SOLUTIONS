class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1e9);
        dp[n-1]=0;
        dp[n]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]+i>=n-1)
            {
                    dp[i]=1;
                    continue;
            }
            for(int j=i+1;j<=min(n-1,nums[i]+i);j++)
            {
                dp[i]=min(dp[i],dp[j]+1);
            }
            // cout<<dp[i]<<" ";
        }
        return dp[0];
    }
};